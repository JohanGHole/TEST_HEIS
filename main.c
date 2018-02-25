#include <stdio.h>

int N_FLOORS = 4;
int DIRN_DOWN = -1;
int DIRN_STOP = 0;
int DIRN_UP = 1;
int order_matrix[3][4] ={
//	 1 2 3 4   // Floor    
	{0,0,0,0}, // Up 
	{0,0,0,0}, // Down
	{0,0,0,1}  // Panel
	
};


int current_floor = 2;

int next_floor = -2;

int current_dir = 0;

int last_dir = -1;

void set_current_floor(int floor){
	current_floor = floor;
}

int get_current_floor(){
	return current_floor;
}

void set_next_floor(int floor){
	next_floor = floor;
}

int get_next_floor(){
	return next_floor;
}

void set_current_dir(int dir) {
	current_dir = dir;
}

int get_current_dir(){
	return current_dir;
}

void set_last_dir(int dir){
	last_dir = dir;
}

int get_last_dir(){
	return last_dir;
}



int check_order_above(){
	for (int floor = get_current_floor()+1; floor < N_FLOORS; floor++) {
		if(order_matrix[0][floor] == 1 || order_matrix[2][floor] == 1)  {
			set_next_floor(floor);
			return 1;
		}
	}
	for (int floor = N_FLOORS-1; floor > get_current_floor(); floor--){
		if (order_matrix[1][floor] == 1){
		set_next_floor(floor);
		return 1;
		}
	}
	return 0;	
}

int check_order_below(){
	for (int floor = get_current_floor()-1; floor >= 0; floor--) {
		if(order_matrix[1][floor] == 1 || order_matrix[2][floor] == 1) {
			set_next_floor(floor);
			return 1;
		}
	}
	for (int floor = 0; floor < get_current_floor(); floor++){
		if (order_matrix[0][floor] == 1){
			set_next_floor(floor);
			return 1;
		}
	}
	return 0;	
}
//setter next_floor etter hva som er mest gunstig
void set_priority(){
	if (get_current_dir() == DIRN_UP){
		check_order_above();
		return;
	}
	else if (get_current_dir() == DIRN_DOWN){
		check_order_below();
		return;
	}
	else if (get_last_dir() == DIRN_UP && get_current_floor() != 3){
		check_order_above();
		return;
	}
	else if (get_last_dir() == DIRN_DOWN && get_current_floor() != 0){
		check_order_below();
		return;
	}
	else if (get_current_floor() == 0 && get_current_dir() == DIRN_STOP){
		check_order_above();
		return;
	}
	else if (get_current_floor() == 3 && get_current_dir() == DIRN_STOP){
		check_order_below();
		return;
	}
}

int main() {
	printf("dette er en test \n");
	set_priority();
	printf("next floor: %d \n",get_next_floor()+1);
	return 0;
}