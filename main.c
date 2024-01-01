#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct utilizador
{
    // Pointer to 'self'
    // this keyword
    struct utilizador *self;

    // Actual "member variables"
    char email[100];
    char name[20];
    char role[20];

    // "Member functions" or "methods" that we implement from scratch
    // Could embed these in another struct to change behaviour of different functions (polymorphism)
    char *(*getEmail)(struct utilizador *);
    void (*setEmail)(struct utilizador *, char email[100]);

    char *(*getName)(struct utilizador *);
    void (*setName)(struct utilizador *, char name[20]);

    char *(*getRole)(struct utilizador *);
    void (*setRole)(struct utilizador *, char role[20]);
} utilizador_t;

char *getEmail(utilizador_t *self)
{
    return (*self).email;
};

void setEmail(utilizador_t *self, char *email)
{
    strcpy((*self).email, email); // change from '==' to 'strcpy'
};

char *getName(utilizador_t *self)
{
    return (*self).name;
};

void setName(utilizador_t *self, char *name)
{
    strcpy((*self).name, name); // change from '==' to 'strcpy'
};

char *getRole(utilizador_t *self)
{
    return (*self).role;
};

void setRole(utilizador_t *self, char *role)
{
    strcpy((*self).role, role); // change from '==' to 'strcpy'
};
void destroy_user(utilizador_t *self)
{
 	free(self->email);
 	free(self->name);
 	free(self->role);

 	free(self);}
utilizador_t *create_utilizador(char *email, char *name, char *role)
{
    utilizador_t *newutilizador = (utilizador_t *)malloc(sizeof(utilizador_t));
    // Store the pointer back to the memory that holds our actual object
    (*newutilizador).self = newutilizador;
    strcpy((*newutilizador).email, email); // change from '==' to 'strcpy'
    strcpy((*newutilizador).name, name); // change from '==' to 'strcpy'
    strcpy((*newutilizador).role, role); // change from '==' to 'strcpy'

    // Set up the function pointers
    (*newutilizador).getEmail = getEmail;
    (*newutilizador).setEmail = setEmail;

    (*newutilizador).getName = getName;
    (*newutilizador).setName = setName;

    (*newutilizador).getRole = getRole;
    (*newutilizador).setRole = setRole;

    return newutilizador;
};

int main()
{
    utilizador_t *test = create_utilizador("test@gmail.com", "test", "utilizador");

    // Retrieve all values
    printf("%s\n", (*test).getEmail(test->self));
    printf("%s\n", (*test).getName(test->self));
    printf("%s\n", (*test).getRole(test->self));
    destroy_user(test);
    return EXIT_SUCCESS;
}