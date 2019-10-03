#include "list.h"
//#include <iostream>
//#include <stdio.h>

List::List(){
  this->begin = nullptr;
  this->end = nullptr;
  this->num_elements=0;
}

List::~List(){
  Node *aux = this->begin;
  Node *aux2 = nullptr;
  while(aux != nullptr){
    aux = aux->next;
    aux2 = aux;
    delete (aux2);
    this->num_elements--;
  }
}

int List::front(){
  return this->begin->element;
}

int List::weigth(){
  return this->begin->operations;
}

bool List::empty(){
  return num_elements == 0;
}

bool List::pop_front(){
  Node *aux = this->begin;
  if (num_elements==0) return false;
  if (num_elements==1) {
    this->begin = nullptr;
    this->end = nullptr;
    delete (aux);
  }
  else {
    this->begin = aux->next;
    delete(aux);
  }
  this->num_elements--;
  return true;
}

void List::remove(int x){
  Node *aux;
  Node *aux2;
  for (aux=this->begin; aux != nullptr; aux=aux->next){
    if (aux->next->element == x){
      aux2=aux->next;
      if (aux2 == this->end){
        aux->next = nullptr;
        this->end = aux;
      }
      else{
        aux->next = aux2->next;
      }
      delete(aux2);
      this->num_elements--;
      break;
    }
  }
}

void List::push_back(int x, int y){
  Node *node = new Node;
  node->element = x;
  node->operations = y;
  node->next = nullptr;
  if (num_elements==0){
    this->begin = node;
    this->end = node;
  }
  else{
    this->end->next = node;
    this->end = node;
  }
  this->num_elements++;
}

int List::size(){
  return this->num_elements;
}