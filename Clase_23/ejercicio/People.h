struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

int list_enterPerson(Person* p);
void list_printPerson(Person* p);

void list_initPeopleList(void);
void list_addPerson(Person* p);
Person* list_newPerson(void);
int list_getSize(void);
Person* list_get(int i);
void list_free(void);
