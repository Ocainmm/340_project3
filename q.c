#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct __node {
    char* line;
    struct node *next;
}node;

typedef struct queue {
    node *head;
    node *tail;
    pthread_mutex_t head_lock,tail_lock;
}

void queue_init(queue *q){
    node *tmp = malloc(sizeof(node));
    tmp->next=NULL;
    q->head = q->tail = tmp;
    pthread_mutex_init(&q->head_lock, NULL)
    pthread_mutex_init(&q->tail_lock, NULL)
}

void q_push(queue *q, char *line){
    node *tmp = malloc(sizeof(node));
    assert(tmp != NULL);
    tmp->line = *line
    tmp->next = NULL

    pthread_mutex_lock(&q->tail_lock);
    q->tail->next = tmp;
    q->tail=tmp;
    pthread_mutex_unlock(&q->tail_lock);
}

int q_pop(queue *q, char* *line){
    thread_mutex_lock(&q->head_lock);
    node *tmp = q->head;
    node *new_head = tmp->next;
    if(new_head == NULL){
        pthread_mutex_unlock(&q->head_lock);
        //signal empty
        return -1;
    }
    *line = new_head->line;
    q->head=new_head;
    pthread_mutex_unlock(&q->head_lock);
    free(tmp);
    return 0;
}