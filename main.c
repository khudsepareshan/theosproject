#include<stdio.h>
#include<conio.h>
struct process{
    float bursttime;
    float id;
    float arrival;
    float turnaround;
    float complete;
    float wait;
};
int main(){
    float turnaround = 0.0 , waiting = 0.0;
    int instance = 0,i=0;
    struct process a,b,c;
    a.bursttime = a.wait =2;
    a.arrival = 0;
    a.id = 2132;
    b.bursttime = b.wait = 4;
    b.arrival = 0;
    b.id = 2102;
    c.bursttime = c.wait = 8;
    c.arrival = 0;
    c.id = 2453;
    while (!(a.bursttime==0 && b.bursttime==0 && c.bursttime==0)){
        if(a.bursttime>b.bursttime && a.bursttime>c.bursttime){
            if(a.arrival == 0){
                a.arrival = instance;
            }
            if(a.bursttime ==1){
                a.complete = instance+1;
                a.wait = a.complete - a.wait;
                a.turnaround =a.complete-a.arrival;
            }
            a.bursttime--;
            printf("\n1");
            instance++;
        }else if(b.bursttime>c.bursttime && b.bursttime>a.bursttime){
            if(b.arrival == 0){
                b.arrival = instance;
            }
            if(b.bursttime ==1){
                b.complete = instance+1;
                b.wait = b.complete - b.wait;
                b.turnaround =b.complete-b.arrival;
            }
            b.bursttime--;
            instance++;
            printf("\n2");
        }else if(c.bursttime>a.bursttime && c.bursttime>b.bursttime){
            if(c.arrival == 0){
                c.arrival = instance;
            }
            if(c.bursttime ==1){
                c.complete = instance+1;
                c.wait = c.complete - c.wait;
                c.turnaround =c.complete-c.arrival;
            }
            c.bursttime--;
            instance++;
            printf("\n3");
        }else{
            if(a.bursttime == b.bursttime){
                if(a.id>b.id){
                    if(a.arrival == 0){
                        a.arrival = instance;
                    }
                    if(a.bursttime ==1){
                        a.complete = instance+1;
                        a.turnaround =a.complete-a.arrival;
                        a.wait = a.turnaround - a.wait;
                    }
                    a.bursttime=a.bursttime-1;
                    instance++;
                    printf("\n4");
                }else{
                    if(b.arrival == 0){
                        b.arrival = instance;
                    }
                    if(b.bursttime ==1){
                        b.complete = instance+1;
                        b.turnaround =b.complete-b.arrival;
                        b.wait = b.turnaround - b.wait;
                    }
                    b.bursttime=b.bursttime-1;
                    instance++;
                    printf("\n5");
                }
            }else if(c.bursttime == b.bursttime){
                if(c.id>b.id){
                    if(c.arrival == 0){
                        c.arrival = instance;
                    }
                    if(c.bursttime ==1){
                        c.complete = instance+1;
                        c.turnaround =c.complete-c.arrival;
                        c.wait = c.turnaround - c.wait;
                    }
                    c.bursttime=c.bursttime-1;
                    instance++;
                    printf("\n6");
                }else{
                    if(b.arrival == 0){
                        b.arrival = instance;
                    }
                    if(b.bursttime ==1){
                        b.complete = instance+1;
                        b.turnaround =b.complete-b.arrival;
                        b.wait = b.turnaround - b.wait;
                    }
                    b.bursttime=b.bursttime-1;
                    instance++;
                    printf("\n7");
                }

            }else if(c.bursttime == a.bursttime){
                if(c.id>a.id){
                    if(c.arrival == 0){
                        c.arrival = instance;
                    }
                    if(c.bursttime ==1){
                        c.complete = instance+1;
                        c.turnaround =c.complete-c.arrival;
                        c.wait = c.turnaround - c.wait;
                    }
                    c.bursttime=c.bursttime-1;
                    instance++;
                    printf("\n8");
                }else{
                    if(a.arrival == 0){
                        a.arrival = instance;
                    }
                    if(a.bursttime ==1){
                        a.complete = instance+1;
                        a.turnaround =a.complete-a.arrival;
                        a.wait = a.turnaround - a.wait;
                    }
                    a.bursttime=a.bursttime-1;
                    instance++;
                    printf("\n9");
                }
            }
        }


    }
    printf("\nProcess \t\t Process ID \t Arrival \t Completion \t Turnaround \t Waiting\n");
    printf("Process A \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f\n",a.id,a.arrival,a.complete,a.turnaround,a.wait);
    printf("Process B \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f\n",b.id,b.arrival,b.complete,b.turnaround,b.wait);
    printf("Process C \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f \t\t %.0f\n",c.id,c.arrival,c.complete,c.turnaround,c.wait);
    turnaround = (a.turnaround+b.turnaround+c.turnaround)/3;
    waiting = (a.wait+b.wait+c.wait)/3;
    printf("\n\nAverage Turnaround Time :: %2f",turnaround);
    printf("\nAverage Waiting Time :: %2f",waiting);
}