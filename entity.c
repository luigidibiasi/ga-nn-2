#include "entity.h"
#include <malloc.h>
NN* makeEntity(char **newGenome)
{
	NN* entity = malloc(sizeof(NN));
	entity->genome="TEST";
	entity->entity_id=entity_id_counter++;

	return entity;
}

