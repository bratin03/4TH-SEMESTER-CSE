#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum E_TYPE
{
    Er,
    Mgr,
    Dir
} E_TYPE;
typedef void (*psFuncPtr)(void *);
typedef struct Engineer
{
    char *name_;
} Engineer;
Engineer *InitEngineer(const char *name)
{
    Engineer *e = (Engineer *)malloc(sizeof(Engineer));
    e->name_ = strdup(name);
    return e;
}
void ProcessSalaryEngineer(void *v)
{
    Engineer *e = (Engineer *)v;
    printf("%s: Process Salary for Engineer\n", e->name_);
}
typedef struct Manager
{
    char *name_;
    Engineer *reports_[10];
} Manager;
Manager *InitManager(const char *name)
{
    Manager *m = (Manager *)malloc(sizeof(Manager));
    m->name_ = strdup(name);
    return m;
}
void ProcessSalaryManager(void *v)
{
    Manager *m = (Manager *)v;
    printf("%s: Process Salary for Manager\n", m->name_);
}
typedef struct Director
{
    char *name_;
    Manager *reports_[10];
} Director;
Director *InitDirector(const char *name)
{
    Director *d = (Director *)malloc(sizeof(Director));
    d->name_ = strdup(name);
    return d;
}
void ProcessSalaryDirector(void *v)
{
    Director *d = (Director *)v;
    printf("%s: Process Salary for Director\n", d->name_);
}

typedef struct Staff
{
    E_TYPE type_;
    void *p;
} Staff;
int main()
{
    psFuncPtr psArray[] = {ProcessSalaryEngineer,
                           ProcessSalaryManager,
                           ProcessSalaryDirector};
    Staff staff[] = {{Er, InitEngineer("Rohit")},
                     {Mgr, InitEngineer("Kamala")},
                     {Mgr, InitEngineer("Rajib")},
                     {Er, InitEngineer("Kavita")},
                     {Er, InitEngineer("Shambhu")},
                     {Dir, InitEngineer("Ranjana")}};
    for (int i = 0; i < sizeof(staff) / sizeof(Staff); ++i)
        psArray[staff[i].type_](staff[i].p);
    return 0;
}