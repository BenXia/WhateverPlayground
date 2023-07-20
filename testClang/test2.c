#include <stdio.h>
#include <stdlib.h>

static int edgeTable[101] = { 0 };

static int edgeId[101] = { 0 };
static int edgeTo[101] = { 0 };
static int edgeIdIndex = 1;

double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    if (n == 0 || edges == NULL || edgesSize == 0) {
        return 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        if (edgeTable[edges[i][0]] == 0) {
            edgeTable[edges[i][0]] = edgeIdIndex++;
            edgeId[edgeIdIndex-1] = 0;
            edgeTo[edgeIdIndex-1] = edges[i][1];
        } else {
            edgeId[edgeIdIndex++] = edgeTable[edges[i][0]];
            edgeTable[edges[i][0]] = edgeIdIndex - 1;
            edgeTo[edgeIdIndex-1] = edges[i][1];
        }

        if (edgeTable[edges[i][1]] == 0) {
            edgeTable[edges[i][1]] = edgeIdIndex++;
            edgeId[edgeIdIndex-1] = 0;
            edgeTo[edgeIdIndex-1] = edges[i][0];
        } else {
            edgeId[edgeIdIndex++] = edgeTable[edges[i][1]];
            edgeTable[edges[i][1]] = edgeIdIndex - 1;
            edgeTo[edgeIdIndex-1] = edges[i][0];
        }
    }

    double queueProbability[5001] = { 1, 0 };
    int queue[5001] = { 1, 0 }, front = 0, tail = 2, currentStep = 0;

    int visited[101] = { 0 };
    visited[1] = 1;

    while (front < tail) {
        int cIndex = queue[front];
        double cProbability = queueProbability[front];
        front++;

        if (cIndex == 0) {
            queue[tail] = 0;
            queueProbability[tail] = 0;
            tail++;

            currentStep++;
        } else {
            if (currentStep == t && target == cIndex) {
                return cProbability;
            }

            int childCount = 0;
            for (int idx = edgeTable[cIndex]; idx != 0; idx = edgeId[idx]) {
                if (visited[edgeTo[idx]] == 0) {
                    childCount += 1;
                }
            }

            if (childCount == 0) {
                queue[tail] = cIndex;
                queueProbability[tail] = cProbability;

                tail++;
            } else {
                for (int idx = edgeTable[cIndex]; idx != 0; idx = edgeId[idx]) {
                    if (visited[edgeTo[idx]] == 0) {
                        visited[edgeTo[idx]] = 1;

                        queue[tail] = edgeTo[idx];
                        queueProbability[tail] = cProbability / childCount;

                        tail++;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    int **edges = (int **)malloc(sizeof(int *) * 6);
    int *edgesColSize = (int *)malloc(sizeof(int) * 6);
    for (int i = 0; i < 6; i++) {
        edges[i] = (int *)malloc(sizeof(int) * 2);
        edgesColSize[i] = 2;
    }
    edges[0][0] = 1;
    edges[0][1] = 2;
    edges[1][0] = 1;
    edges[1][1] = 3;
    edges[2][0] = 1;
    edges[2][1] = 7;
    edges[3][0] = 2;
    edges[3][1] = 4;
    edges[4][0] = 2;
    edges[4][1] = 6;
    edges[5][0] = 3;
    edges[5][5] = 5;

    double result = frogPosition(7, edges, 6, edgesColSize, 1, 7);
    printf("%f", result);

    return 0;
}


