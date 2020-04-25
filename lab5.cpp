#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>

int main(){
	int task = 0, i = 0, j = 0, rows, columns, matrix[rows][columns];
	char buffer[7] = { 'a', 'b', 'c', 'd', 'e', 'f', '*' };
	srand(time(NULL));

	printf("Enter number of task (1 - 5): ");
	scanf("%d", &task);

	if(task >= 1 && task <= 5){
		switch(task){
		case 1:
			enum Universities { Oxford, Harvard, California, Massachusetss };

			Universities uni;
			printf("Enter a value (From 0 to 3): ");
			scanf("%d", &uni);

			if(uni >= 0 && uni <= 3){
				switch(uni){
					case Oxford: printf("Oxford University\n"); break;
					case Harvard: printf("Harvard University\n"); break;
					case California: printf("California University in Berkly\n"); break;
					case Massachusetss: printf("Cambridge University\n"); break;
					default: printf("Oxford University\n");
				}
			}
			printf("Address of \"University\" enum in hex: %x\n", &uni);
			printf("Size of \"University\" enum: %d bytes\n", sizeof(uni));
		break;
		case 2:
			printf("Enter an index (0 - 7): ");
			while(task != 8){
				scanf("%d", &task);

				if(task >= 0 && task < 7){
					printf("Symbol in array with index %d is %c\n", task, buffer[task]);
				}
				else if(task == 7)
					printf("Symbol in array with index %d is \\0\n", task);
				else if(task > 8) continue;
				else break;
			}
		break;
		case 3:
			printf("Enter count of rows in matrix: ");
			scanf("%d", &rows);
			printf("Enter count of columns in matrix: ");
			scanf("%d", &columns);

			for(i = 0; i < rows; i++)
				for(j = 0; j < columns; j++)
					matrix[i][j] = 1 + rand() % 100;

			printf("Enter indexes which element do you want to output:\n");

			i = 0, j = 0;

			while(i != rows){
				while(j != columns){
					scanf("%d %d", &i, &j);

					if(i >= rows || j >= columns){
						system("clear");
						break;
					}
					else {
						printf("Element[%d][%d] = %d\n", i, j, matrix[i][j]);
					}
				}
			}
		break;
		case 4:{
			struct SecurityData {
				long id;
				char name[256];
				char surname[256];
				int code;
				enum AccessLevel { green = 'g', yellow = 'y', red = 'r' } _lvl;
			} Person;

			Person.id = 256 + rand() % 100;
			strcpy(Person.name, "Anatoliy");
			strcpy(Person.surname, "Dyatlov");
			Person.code = rand() % 100;
			Person._lvl = SecurityData::AccessLevel::red;

			printf("ID: %ld\nName: %s\nSurname: %s\nPersonal Code: %d\n",
				 Person.id, Person.name, Person.surname, Person.code);
			switch(Person._lvl){
				case SecurityData::AccessLevel::green: printf("Access Level: Green\n"); break;
				case SecurityData::AccessLevel::yellow: printf("Access Level: Yellow\n"); break;
				case SecurityData::AccessLevel::red: printf("Access Level: Red\n"); break;
				default: printf("Access Level: None\n");
			}
			printf("Size of struct 1: %d bytes\n", sizeof(Person));

			struct Library{
				long id;
				char name[256];
				enum Cathegory { scientistific = 54, artistic = 5, children = 'c', cookery };
				char author[50];
			} Book;

			printf("Size of struct 2: %d bytes\n", sizeof(Book));

		}
		break;
		case 5:{
			union Error{
				int errcode;
				char errstr[256];
			};

			Error err;
			err.errcode = 1 + rand() % 100;
			strcpy(err.errstr, "error message");

			printf("Error: %X - %s!\n", &err.errcode, err.errstr);
			printf("Size of union <Error>: %d bytes\n", sizeof(err));
		}
		break;
		default: printf("Entered number is invalid!\n");
		}
	}
	else printf("Recieved value is invalid!\n");

	return EXIT_SUCCESS;
}
