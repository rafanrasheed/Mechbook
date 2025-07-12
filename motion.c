//contains funcn primarily used for motion analysis.

#include<stdio.h>
#include<ctype.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<math.h>

#include"helpers.h"
#include"motion.h"

//function to ask user for and assign the distance.
double input_dist(void)
{
    double s;
    printf("\nEnter distance in metres:  ");
    scanf("%lf", &s);
    return s;
}

//function to ask user for and assign the initial velocity.
double input_initial_vel(void)
{
    double u;
    printf("\nEnter initial velocity in metres per second:  ");
    scanf("%lf", &u);
    return u;
}

//function to ask user for and assign the final velocity.
double input_final_vel(void)
{
    double v;
    printf("\nEnter final velocity in metres per second:  ");
    scanf("%lf", &v);
    return v;
}

//function to ask user for and assign the acceleration.
double input_accl(void)
{
    double a;
    printf("\nEnter acceleration in m/s^2:  ");
    scanf("%lf", &a);
    return a;
}

//function to ask user for and assign the tima taken.
double input_time(void)
{
    double t;
    printf("\nEnter time taken in seconds:  ");
    scanf("%lf", &t);
    return t;
}

//function to run logic of 2D motion analysis
//at constant acceleration using the SUVAT eqns of motion:
//--> v = u + at
//--> v^2 = u^2 + 2as
//--> s = ut + 0.5 a t^2
//--> s = ((u+v)/2) (t)
void _2d_motion(void)
{
    double s=0, u=0, v=0, a=0, t=0;

    bool all=false, sb=false, ub=false, vb=false, ab=false, tb=false;
    
    printf("\nIs the distance travelled known?\n");
    sb = get_bool();
    if(sb){
        printf("\nEnter distance in metres:   ");
        s = get_dbl();
    }

    printf("\nIs the initial velocity known?\n");
    ub = get_bool();
        if(ub){
        printf("\nEnter initial velocity in metres per second:   ");
        u = get_dbl();
    }

    printf("\nIs the final velocity known?\n");
    vb = get_bool();
        if(vb){
        printf("\nEnter final velocity in metres per second:   ");
        v = get_dbl();
    }

    printf("\nIs the acceleration known?\n");
    ab = get_bool();
        if(ab){
        printf("\nEnter acceleration in m/s^2:   ");
        a = get_dbl();
    }

    printf("\nIs the time taken known?\n");
    tb = get_bool();
        if(tb){
        printf("\nEnter time taken in seconds:   ");
        t = get_dbl();
    }

    if(sb && ub && vb && ab && tb){
        all = true;
    }
    else if(sb && ub && vb && ab)
    {
        if(s == 0 && u == 0 && v == 0 && a == 0){
            t = 0;
        }
        else if(u == 0 && v == 0 && a == 0){
            no_data();
        }
        else if(a == 0){
            t = (2*s) / (u+v);
        }
        else{
            t = (v-u) / a;        
        }
    }
    else if(sb && ub && vb && tb)
    {
        if(t == 0){
            s = 0;
            v = u;
            a = 0;
        }
        else{
            a = (v-u) / t;
        }
    }
    else if(sb && ub && ab && tb)
    {
        v = u+(a*t);
    }
    else if(sb && vb && ab && tb)
    {
        u = v-(a*t);
    }
    else if(ub && vb && ab && tb)
    {
        s = (u*t)+(0.5*a*t*t);
    }
    else if(sb && ub && vb)
    {
        if (s==0 && u==0 && v==0){
            t = 0;
            a = 0;
        }
        else{
            t = (2*s) / (u+v);
            a = (v-u) / t;
        }
    }
    else if(sb && ub && ab)
    {
        double temp = (u*u)+(2*a*s);
        if (temp < 0)
        {
            double x = a;
            double y = (u*t);
            double z = (-2)*s;
            double disc = (y*y)-(4*x*z);
            if(disc < 0){
                printf("ERROR_CODE_107");
                quit();
            }
            disc = sqrt(disc);
            disc = (-y)+disc;
            if (x == 0){
                no_data();
            }
            t = disc / (2*x);
            v = u+(a*t);
        }
        else
        {
            if (a == 0){
                no_data();
            }
            else{
                v = sqrt(temp);
                t = (v-u) / a;
            }
        }
    }
    else if(sb && ub && tb)
    {
        if (t == 0){
            v = u;
            s = 0;
            a = 0;
        }
        else{
            v = ((2*s) / t)-u;
            a = (v-u) / t;
        }
    }
    else if(sb && vb && ab)
    {
        double temp = (v*v)-(2*a*s);
        if (temp < 0){
            printf("\nERROR_CODE_105\n\n");
            return;
        }
        if (a == 0){
            no_data();
        }
        else{
            u = sqrt(temp);
            t = (v-u) / a;
        }
    }
    else if(sb && vb && tb)
    {
        if (t == 0){
            u = v;
            s = 0;
            a = 0;
        }
        else{
            u = ((2*s) / t)-v;
            a = (v-u) / t;
        }
    }
    else if(sb && ab && tb)
    {
        if (t == 0){
           no_data();
        }
        else{
            u = (s / t)-((a*t) / 2);
            v = u+(a*t);
        }
    }
    else if(ub && vb && ab)
    {
        if (a == 0){
            no_data();
            return;
        }
        else{
            t = (v-u) / a;
            s = (u*t)+(0.5*a*t*t);
        }
    }
    else if(ub && vb && tb)
    {
        if (t == 0){
            v = u;
            a = 0;
            s = 0;
        }       
        else{
            s = ((u+v) / 2)*t;
            a = (v-u) / t;
        }
    }
    else if(ub && ab && tb)
    {
        v = u+(a*t);
        s = (u*t)+(0.5*a*t*t);
    }
    else if(vb && ab && tb)
    {
        u = v-(a*t);
        s = (u*t)+(0.5*a*t*t);
    }
    else{
        no_data();
        return;
    }

    printf("\n\n------------------RESULTS------------------\n\n");
    if(all){
        printf("NOTE: All values were provided by the user and \n      are printed as is.\n\n");
    }
    printf("--> Distance:          %.10g m\n", s);
    printf("--> Initial velocity:  %.10g m/s\n", u);
    printf("--> Final velocity:    %.10g m/s\n", v);
    printf("--> Acceleration:      %.10g m/s^2\n", a);
    printf("--> Time taken:        %.10g sec\n\n\n", t);
}
