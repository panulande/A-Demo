#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define PEAK_HOUR_START 12
#define PEAK_HOUR_END 16
#define BASE_PRICE 0.5
#define PEAK_PRICE 1.0

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
    Queue queue[3];
    initQueue(&queue[0]);
    initQueue(&queue[1]);
    initQueue(&queue[2]);
    int hour = 0;
    float price = BASE_PRICE;
    EV ev1 = {10, 1.5};
    EV ev2 = {5, 1.0};
    EV ev3 = {8, 2.0};
    EV ev4 = {3, 1.5};
    EV ev5 = {6, 2.0};
    enqueue(&queue[ev1.battery_level / 4], ev1);
    enqueue(&queue[ev2.battery_level / 4], ev2);
    enqueue(&queue[ev3.battery_level / 4], ev3);
    enqueue(&queue[ev4.battery_level / 4], ev4);
    enqueue(&queue[ev5.battery_level / 4], ev5);
while (!isQueueEmpty(&queue[0]) || !isQueueEmpty(&queue[1]) || !isQueueEmpty(&queue[2])) {
    if (hour >= PEAK_HOUR_START && hour < PEAK_HOUR_END) {
        price = PEAK_PRICE;
    } else {
        price = BASE_PRICE;
    }
    printf("Hour: %d, Price: $%.2f\n", hour, price);
    for (int i = 0; i < 3; i++) {
        if (!isQueueEmpty(&queue[i])) {
            EV vehicle = dequeue(&queue[i]);
            printf("Vehicle with battery level %d dequeued from queue %d\n", vehicle.battery_level, i);
            float charging_time = vehicle.charging_time;
            printf("Charging time for vehicle: %.1f\n", charging_time);
            float cost = charging_time * price;
            printf("Cost of charging: $%.2f\n", cost);
        }
    }
    hour++;
}

    return 0;
}
