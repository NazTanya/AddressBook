#include <stdio.h>


struct record {
	int key_;
	char name_[15];
	char surname_[15];
	char number_[8];
	struct record *next;
};

void print(struct record *book)
{
	if(book == NULL){
		printf("This is empty!\n\n");
		return;
	}
	struct record *ptr = book;
	while(ptr != NULL)
	{
		printf("Key: %d\nName: %s\nSurname: %s\nNumber:%s\n\n",ptr->key_,ptr->name_,ptr->surname_,ptr->number_);
		ptr = ptr->next;
	}
}
struct record* push(struct record *book, int key, char name[],char surname[],char number[])
 {
    struct record *tmp = malloc(sizeof(struct record));
	tmp->key_=key;
	strcpy(tmp->name_,name);
	strcpy(tmp->surname_,surname);
	strcpy(tmp->number_,number);
    tmp->next = book;
    book = tmp;
	return book;
}

struct record* del_record(struct record* Head, int key)
{
  struct record *ptr;
  struct record *Current = Head;
  while(Current->key_ != key && Current != NULL)
    Current = Current->next;
  if (Current != NULL){
    if (Current == Head)
	{
      Head = Head->next;
      free(Current);
      Current = Head;
    }
    else 
	{
      ptr = Head;
      while (ptr->next != Current)
        ptr = ptr->next; 
      ptr->next = Current->next;
      free(Current);
      Current=ptr;
    }
  }
  return Head;
}


void del_book(struct record* Head){
  if (Head != NULL){
    del_book(Head->next);
    free(Head);
  }
}

int main()
{
	char name[15],surname[15],number[8],ac[2],key[3];
	int k;
	struct record *book = NULL;
	//при первом запуске пользователю предлагается внести 
	//какое-либо количество записей, а потом через меню можно 
	//выбирать различные действия
	printf("please cheate some records\n");
	char cont = 0;
	do
	{
		printf("enter the key\n");
		fgets(key,3,stdin);
		printf("enter the name\n");
		fgets(name,15,stdin);
		printf("enter the surname\n");
		fgets(surname,15,stdin);
		printf("enter the number\n");
		fgets(number,8,stdin);
		k = atoi(key);
		book = push(book,k,name,surname,number);
		printf("if you want enter record press y");
		cont = getchar();
	} while (cont == 'y' || cont == 'Y');

	while(ac[0] != '4')
	{
			printf("1) Add new record\n2) Show the address book\n3)Delete record\n4) Quit\n");
			printf("please choose action\n");
			fgets(ac,2,stdin);
			//if(ac[0] == '4')
			//	exit(0);
			switch(ac[0])
			{
			case '1':
			{ 
				printf("enter the key\n");
				getchar();
				fgets(key,3,stdin);
				printf("enter the name\n");
				fgets(name,15,stdin);
				printf("enter the surname\n");
				fgets(surname,15,stdin);
				printf("enter the number\n");
				fgets(number,8,stdin);
				k = atoi(key);
				book = push(book,k,name,surname,number);
				break; //Здесь был Коля. Таня очень старалась. Но как вы поняли сюда добрался яяяяя так что, если что то не получилось то вы знайте это всё я.
			}
			case '2':
			{
				printf("you address book:\n");
				print(book);
				getchar();
				break;
			}
			case '3':
			{
				printf("enter the key\n");
				getchar();
				fgets(key,3,stdin);
				k=atoi(key);
				book = (struct record*)del_record(book,k);
				printf("this record has been deleted\n");
				break;
			}
			case '4':
			{
				del_book(book);
				exit(0);
			}
			default:
			{
				break;
			}
		}
	}
	return 0;
}