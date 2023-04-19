
#include <stdio.h>
#include <stdlib.h>


#define NUM_CHARGING_POINTS 3
#define MAX_QUEUE_SIZE 10
#define BASE_PRICE 0.20
#define PEAK_HOUR_START 18.0
#define PEAK_HOUR_END 22.0
#define PEAK_PRICE 0.35
#define HOUR_INCREMENT 0.5
#define BATTERY_INCREMENT 0.25


typedef struct {
    int battery_level;
    float charging_time;
} EV;

typedef struct {
    EV vehicles[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

int isQueueFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *q, EV vehicle) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->vehicles[q->rear] = vehicle;
    q->size++;
}

EV dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        EV empty = {-1, 0};
        return empty;
    }
    EV vehicle = q->vehicles[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    q->size--;
    return vehicle;
}

int main() {
    Queue queue1, queue2, queue3;
    initQueue(&queue1);
    initQueue(&queue2);
    initQueue(&queue3);
    float hour = 0;
    float price = BASE_PRICE;
    EV ev1 = {10, 1.5};
    EV ev2 = {5, 1.0};
    EV ev3 = {8, 2.0};
    EV ev4 = {3, 1.5};
    EV ev5 = {6, 2.0};
    enqueue(&queue1, ev1);
    enqueue(&queue2, ev2);
    enqueue(&queue3, ev3);
    enqueue(&queue1, ev4);
    enqueue(&queue2, ev5);
while (!isQueueEmpty(&queue1) || !isQueueEmpty(&queue2) || !isQueueEmpty(&queue3)) {
    if (hour >= PEAK_HOUR_START && hour < PEAK_HOUR_END) {
        price = PEAK_PRICE;
    } else {
        price = BASE_PRICE;
    }
    printf("Current hour: %.1f\n", hour);
    printf("Current price: %.2f\n", price);
    printf("Charging vehicles...\n");
    for (int i = 0; i < NUM_CHARGING_POINTS; i++) {
        Queue *current_queue;
        if (i == 0) {
            current_queue = &queue1;
        } else if (i == 1) {
            current_queue = &queue2;
        } else {
            current_queue = &queue3;
        }
        if (!isQueueEmpty(current_queue)) {
            EV current_vehicle = dequeue(current_queue);
            float charging_time = current_vehicle.charging_time;
            printf("EV%d is charging for %.1f hours\n", i + 1, charging_time);
            charging_time -= HOUR_INCREMENT;
            current_vehicle.battery_level += (int)(BATTERY_INCREMENT * HOUR_INCREMENT);
            if (charging_time > 0) {
                enqueue(current_queue, current_vehicle);
            } else {
                printf("EV%d is fully charged!\n", i + 1);
            }
        } else {
            printf("Charging point %d is empty\n", i + 1);
        }
    }
    hour += HOUR_INCREMENT;
}

return 0;

}