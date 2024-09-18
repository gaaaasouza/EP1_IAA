#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "utils.h"

void Merge(int* v, int ini, int m, int f){

    int* aux = (int*) malloc(sizeof(int)*(f+1)); 
    int j = m+1; 
    int i = ini; 
    int p;

    for(p = 0; i <= m && j <= f; p++){ 
        if(v[i] <= v[j]){ 
            aux[p] = v[i]; 
            i++; 
        }else{ 
            aux[p] = v[j]; 
            j++; 
        } 
    } 

    while(i <= m){ 
        aux[p] = v[i]; 
        i++; 
        p++; 
    }

    while(j <= f){ 
        aux[p] = v[j]; 
        j++; 
        p++; 
    }
    
    for(p = 0, i = ini; i <= f; p++, i++){ 
        v[i] = aux[p]; 
    }

}

void MergeSort(int* A, int inicio, int fim){

    int metade;

    if(fim > inicio){ 
        metade = ((inicio + fim)/2); 
        MergeSort(A, inicio, metade); 
        MergeSort(A, metade+1, fim); 
        Merge(A, inicio, metade, fim); 
    } 
}

int Selecao1(int* A, int inicio, int fim, int i){ 
    MergeSort(A, inicio, fim); 
    return A[i]; 
}

int Particao(int* A, int inicio, int fim){

    int pivo = A[fim]; 
    int i, j, aux;

    for(i = 0, j = 0; j < fim; j++){ 
        if(A[j] <= pivo){ 
            aux = A[i]; 
            A[i] = A[j]; 
            A[j] = aux; 
            i++; 
        } 
    }

    aux = A[i]; 
    A[i] = A[j]; 
    A[j] = aux; 
    return i;

}

int Selecao2(int* A, int inicio, int fim, int i){

    int q = Particao(A, inicio, fim);
    
    if(fim == 0){ 
        return A[0]; 
    }
    else if(i < q){ 
        return Selecao2(A, inicio, q-1, i); 
    } 
    else if(i > q){ 
        return Selecao2(A, q+1, fim, i); 
    } 
    else{ 
        return A[q]; 
    } 
} 