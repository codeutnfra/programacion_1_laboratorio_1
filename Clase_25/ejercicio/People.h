struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

struct S_PeopleList
{
    int listSize;
    Person** people;
    int index;
};
typedef struct S_PeopleList PeopleList;

int list_enterPerson(Person* p);
void list_printPerson(Person* p);

PeopleList* list_initPeopleList(void);
void list_addPerson(PeopleList* pl,Person* p);
Person* list_newPerson(void);
int list_getSize(PeopleList* pl);
Person* list_get(PeopleList* pl,int i);
void list_free(PeopleList* pl);

void list_remove(PeopleList* pl,int indexToDelete);



