//https://leetcode.com/problems/implement-queue-using-stacks/description/


typedef struct {
    int *in;
    int *out;
    int topIn;
    int topOut;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->in = (int*)malloc(sizeof(int) * 100);
    obj->out = (int*)malloc(sizeof(int) * 100);
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++(obj->topIn)] = x;
}

void move(MyQueue* obj) {
    if (obj->topOut == -1) {
        while (obj->topIn != -1) {
            obj->out[++(obj->topOut)] = obj->in[(obj->topIn)--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    move(obj);
    return obj->out[(obj->topOut)--];
}

int myQueuePeek(MyQueue* obj) {
    move(obj);
    return obj->out[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->in);
    free(obj->out);
    free(obj);
}