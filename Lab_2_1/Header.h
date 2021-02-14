#pragma once

using namespace std;


struct elem_list {
	int val;
	elem_list* next;
};

typedef elem_list* listptr;