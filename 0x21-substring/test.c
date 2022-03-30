    #include<stdio.h>

    #include<string.h>
     

    void print(char **num, int n)

    {

        int i;

        for ( i = 1 ; i < n ; i++)
            printf("%s ", num[i]);
        printf("\n");

    }

    int main(int ac, char **av)

    {
        char *temp;

        int i, j;

       for (j = 1; j <= ac; j++) {
            for (i = 1; i < ac-1; i++) {
                temp = av[i];
                av[i] = av[i+1];
                av[i+1] = temp;
                print(av, ac);
    	    }
        }
        return 0;
    }