#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct connection
{
  int a;
  int b;
};
struct graph
{
    int elements_count;
    struct connection* connections;
    int connections_count;
};

int main()
{
    struct graph g;
    printf("Enter number of graph elements:\n");
    int n;
    scanf("%d", &n);
    g.elements_count = n;
    
    g.connections_count = 0;
    g.connections = (struct connection*)malloc(sizeof(struct connection));
    int finished = 0;
    
    while(!finished)
    {
        printf("1.Add connection\n2.Generate graphviz code\n3.Check coherence\n4.Finish\n");
        int in;
        scanf("%d", &in);
        switch(in)
        {
            case 1:
            {
                g.connections_count++;
                g.connections = (struct connection*)realloc(g.connections, sizeof(struct connection) * g.connections_count);
                printf("Type 2 values: ");
                int a, b;
                scanf("%d %d", &a, &b);
                g.connections[g.connections_count - 1].a = a;
                g.connections[g.connections_count - 1].b = b;
                
                break;
            }
            case 2:
            {
                char* filename = "out.txt";
//                 printf("Enter filename: ");
//                 scanf("%s", filename);

                FILE* f = fopen(filename, "w");
                fprintf(f, "graph g {\n");
                for(int i = 0; i != g.elements_count; ++i)
                    fprintf(f, "%d;\n", i);
                for(int i = 0; i != g.connections_count; ++i)
                {
                    fprintf(f, "%d -- %d;\n", g.connections[i].a, g.connections[i].b);
                }
                fprintf(f, "}");
                fclose(f);
                printf("Code is written to out.txt!\n");
                break;
            }
            case 3:
            {
                if(g.connections_count > ((g.elements_count - 1) * (g.elements_count - 2))/2)
                    printf("This graph is coherent!\n");
                else
                    printf("This graph is not coherent!\n");
                break;
            }
            case 4:
            {
                finished = 1;
                break;
            }
            default:
            {
                printf("incorrect input\n");
                break;
            }
            
        };
    }    

    return 0;
}
