#ifndef SRC_CLIENTEXAMPLE_H_
#define SRC_CLIENTEXAMPLE_H_

#ifdef __cplusplus
extern "C" {
#endif

struct TableOps {
	char *table_name;
	// stuff you don't use
	struct connector *parent;
	void *tableOpsPtr;
};

struct connector {

	// stuff you don't use
	void *masterPtr;
	void *zk;

};

struct connector *create_connector(char *instance, char *zks, char *username,
		char *password);

int free_connector(struct connector *connector);

struct TableOps *open_table(struct connector *connector, char *tableName);

struct TableOps *create_table(struct connector *connector, char *tableName);

int free_table(struct TableOps *tableOps);

#ifdef __cplusplus
}
//end extern "C"
#endif

#endif
