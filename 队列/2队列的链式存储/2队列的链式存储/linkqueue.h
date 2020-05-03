#pragma once

typedef void LinkQueue;

LinkQueue* LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue* queue);

void LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Append(LinkQueue* queue, void* item);

//从队列中删除元素
void* LinkQueue_Retrieve(LinkQueue* queue);

void* LinkQueue_Header(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);
