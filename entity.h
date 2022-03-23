// This structure represent a single entity with its own genoma
//

static long entity_id_counter =0;

typedef struct NN_struct {
	char *genome;
	long entity_id;
} NN;

NN* makeEntity(char **newGenome);

