#include <iostream>
#include <list>
#include <string>
#include <pthread.h>


struct Tarefa{
public:
    int id = 0;
    void* (*funcao) (void* t) = NULL;
    void* parametros = NULL;
    void* retorno = NULL;
    void* attrib = NULL;
};

struct Attrib {
public:
    int p; //Prioridade da tarefa
    int c; //Custo computacional
};

pthread_cond_t c_tarefas_prontas;
pthread_mutex_t m_tarefas_prontas;
pthread_mutex_t m_tarefas_terminadas;
std::list <Tarefa> tarefasProntas;
std::list <Tarefa> tarefasTerminadas;
std::list <pthread_t> threads;

int countID = 0;
bool isFinished = false;

    //Mutex para verificar a lista
    //Se tiver uma tarefa pega ela e retira da lista
    //Libera a lista
    //Chama tarefaAtual->funcao(tarefaAtual->parametros)
    //Agora como pegar o retorno?
    //tarefaAtual->retorno = tarefaAtual->funcao(tarefaAtual->parametros)
    //Coloca tarefa concluida na lista de tarefasTerminadas
    //Agora como eu saio desse loop?

void* loop_que_itera(void*p)
{
    Tarefa *tarefaAtual = new Tarefa;
    do 
    {
        pthread_mutex_lock(&(m_tarefas_prontas));   // lock: m_tarefas_prontas; Garante a exclusividade ao verificar a lista de tarefas prontas
        while(tarefasProntas.empty())
        {
            pthread_cond_wait(&c_tarefas_prontas, &m_tarefas_prontas);
            if(isFinished)
            {
                pthread_mutex_unlock(&m_tarefas_prontas);
                return 0;
            }
        }

        //Verifica se a lista está vazia
        //Caso a lista não esteja vazia pega uma tarefa e libera o mutex
        *tarefaAtual = (tarefasProntas.front());
        tarefasProntas.pop_front();

        pthread_mutex_unlock(&(m_tarefas_prontas)); // unlock caso if=True: m_tarefas_prontas;

        //Executa a função
        tarefaAtual->retorno = tarefaAtual->funcao(tarefaAtual->parametros);
        //Coloca o resultado na lista de tarefas terminadas

        pthread_mutex_lock(&m_tarefas_terminadas);  // lock: m_tarefas_terminadas;
        tarefasTerminadas.push_back(*tarefaAtual);
        pthread_mutex_unlock(&m_tarefas_terminadas);    // unlock: m_tarefas_terminadas;
    
    } while(!isFinished);
    
    delete(tarefaAtual);
    return 0;
}

int start(int m){
    pthread_mutex_init(&m_tarefas_prontas, NULL);
    pthread_mutex_init(&m_tarefas_terminadas, NULL);
    pthread_cond_init(&c_tarefas_prontas, NULL);
    for (int i = 0; i < m; ++i){
        pthread_t thread;
        threads.push_back(thread);
        if(pthread_create(&(threads.back()), NULL, loop_que_itera, NULL) != 0){
            perror("Failed to create the thread");
            return 0;
        }
    }
    return 1;
}

int spawn(void* *attr = NULL, void* (*func) (void*) = NULL, void* dta = NULL){
    try {
        if(func == NULL){
            throw 404;
        }
    }
    catch (int error){
        if(error == 404){
            std::cout << "Error no function passed\n";
        }
    }
    pthread_mutex_lock(&(m_tarefas_prontas));
    countID += 1;
    int returnID = countID;
    Tarefa novaTarefa;
    novaTarefa.funcao = func;
    novaTarefa.parametros = dta;
    novaTarefa.id = returnID;
    novaTarefa.attrib = attr;
    tarefasProntas.push_back(novaTarefa);
    pthread_cond_signal(&c_tarefas_prontas);
    pthread_mutex_unlock(&(m_tarefas_prontas)); // unlock: m_tarefas_prontas
    return returnID;
}

int sync(int idTarefa, void** retornoTarefa){
    Tarefa *tarefaSync = new Tarefa;
    std::list<Tarefa>::iterator iterator_t;
    bool achou = false;
    
    // ------------------------------------------------------------------------------------------------------
    // Checa caso 2 pela primeira vez: Tarefa está na lista de tarefas_terminada
    // ------------------------------------------------------------------------------------------------------
    pthread_mutex_lock(&(m_tarefas_terminadas));    // lock: m_tarefas_terminadas
    for(iterator_t = tarefasTerminadas.begin(); iterator_t != tarefasTerminadas.end(); ++iterator_t){

        if(idTarefa == iterator_t->id){    // caso 2: Tarefa está na tarefasTerminadas

            *tarefaSync = *iterator_t;
            tarefasTerminadas.erase(iterator_t);

            //pthread_mutex_unlock(&(m_tarefas_prontas));   // unlock caso if=True: m_tarefas_prontas
            pthread_mutex_unlock(&(m_tarefas_terminadas)); // unlock caso if=True: m_tarefas_terminadas
            if(retornoTarefa != NULL){
                *retornoTarefa = tarefaSync->retorno;
            }
            delete(tarefaSync);
            return 1;
        }
    }
    pthread_mutex_unlock(&(m_tarefas_terminadas));  // unlock: m_tarefas_terminadas

    // ------------------------------------------------------------------------------------------------------
    // Checa caso 1: Tarefa está na lista de tarefas_prontas
    // ------------------------------------------------------------------------------------------------------
    pthread_mutex_lock(&(m_tarefas_prontas));   // lock: m_tarefas_prontas
    for(iterator_t = tarefasProntas.begin(); iterator_t != tarefasProntas.end(); ++iterator_t){

        if(idTarefa == iterator_t->id){    // caso 1: Tarefa está na tarefasProntas

            *tarefaSync = *iterator_t;
            tarefasProntas.erase(iterator_t);

            pthread_mutex_unlock(&(m_tarefas_prontas));   // unlock caso if=True: m_tarefas_prontas
            //pthread_mutex_unlock(&(m_tarefas_terminadas)); // unlock caso if=True: m_tarefas_terminadas

            if(retornoTarefa != NULL){
                *retornoTarefa = tarefaSync->funcao(tarefaSync->parametros);
            }
            else if(retornoTarefa == NULL){
                tarefaSync->funcao(tarefaSync->parametros);
            }
            delete(tarefaSync);
            return 1;
        }
    }
    pthread_mutex_unlock(&(m_tarefas_prontas));   // unlock: m_tarefas_prontas

    // ------------------------------------------------------------------------------------------------------
    // caso 3: Tarefa não está na lista de tarefas_prontas e também não está na lista de tarefas_terminadas
    //          Então fica em loop executando alguma tarefa até a tarefa desejada ficar pronta
    // ------------------------------------------------------------------------------------------------------

    while(!isFinished){

        pthread_mutex_lock(&(m_tarefas_prontas));   // lock: m_tarefas_prontas
        if(!tarefasProntas.empty()){    // checa se há uma tarefa para finalizar enquanto espera pela tarefaSync terminar
                
            // tarefas_prontas já está com lock
            *tarefaSync = (tarefasProntas.front());
            tarefasProntas.pop_front();

            pthread_mutex_unlock(&(m_tarefas_prontas)); // unlock caso if=True: m_tarefas_prontas;

            //Executa a função
            tarefaSync->retorno = tarefaSync->funcao(tarefaSync->parametros);   // Coloca o resultado na lista de tarefas terminadas.

            pthread_mutex_lock(&m_tarefas_terminadas);  // lock: m_tarefas_terminadas;
            tarefasTerminadas.push_back(*tarefaSync);
            pthread_mutex_unlock(&m_tarefas_terminadas);    // unlock: m_tarefas_terminadas;
        }
        //Se a lista estiver vazia libera a mutex
        else {
            pthread_mutex_unlock(&(m_tarefas_prontas)); // unlock caso if=False: m_tarefas_prontas;
        }
        // ------------------------------------------------------------------------------------------------------
        // Checa caso 2: Tarefa está na lista de tarefas_terminadas
        // ------------------------------------------------------------------------------------------------------
        
        if(!tarefasTerminadas.empty()){
            pthread_mutex_lock(&(m_tarefas_terminadas));    // lock: m_tarefas_terminadas

            for(iterator_t = tarefasTerminadas.begin(); iterator_t != tarefasTerminadas.end(); ++iterator_t){

                if(idTarefa == iterator_t->id){    // caso 2: Tarefa está na tarefasTerminadas

                    *tarefaSync = *iterator_t;
                    tarefasTerminadas.erase(iterator_t);

                    //pthread_mutex_unlock(&(m_tarefas_prontas));   // unlock caso if=True: m_tarefas_prontas
                    pthread_mutex_unlock(&(m_tarefas_terminadas)); // unlock caso if=True: m_tarefas_terminadas

                    if(retornoTarefa != NULL){
                        *retornoTarefa = tarefaSync->retorno;
                    }
                    delete(tarefaSync);
                    return 1;
                }
            }
            pthread_mutex_unlock(&(m_tarefas_terminadas));    // unlock: m_tarefas_terminadas
        }
    }
    return 0;
}

void finish(){
    isFinished = true;
    pthread_cond_broadcast(&c_tarefas_prontas);
    while (!threads.empty()){
        if(pthread_join(threads.front(), NULL) != 0){
            std::cout << "Error join thread: \n";
        }
        threads.pop_front();
    }
    isFinished = false;
    countID = 0;
    pthread_cond_destroy(&c_tarefas_prontas);
    pthread_mutex_destroy(&m_tarefas_prontas);
    pthread_mutex_destroy(&m_tarefas_terminadas);
}