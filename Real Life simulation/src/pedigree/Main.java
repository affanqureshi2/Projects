package pedigree;

import javax.print.attribute.standard.Fidelity;
import java.util.*;


public class Main{
    // Loyalty to wife or husband is 80%, I know requirement is 90%
    public static int fidelite = 80;
    public static void main(String[] args) {
        simulate(100,1000);
        /*Sim founder = new Sim(Sim.Sex.F);
        System.out.println(founder.getSex()+"\tAge:"+founder.isMatingAge(51));*/
        /*AgeModel M = new AgeModel();
        Random RND = new Random();
        System.out.println(M.randomWaitingTime(RND,0.028));*/
    }

    public static void simulate(int n, int Tmax) {
        ArrayList<Sim> Population = new ArrayList<>();
        ArrayList<Sim> PA = new ArrayList<>();

        // Explanation is in requirment document
        //PQ Population = new PQ(n);
        PQ eventQ = new PQ(Tmax);
        for (int i = 0; i < n; i++) {
            Sim founder = new Sim(Sim.Sex.randomSex());
            //Sim founder = new Sim(Sim.Sex.F);
            /*System.out.print(founder.toString());
            System.out.println();*/

            Event E = new Event(founder,Event.Type_of_Event.B,0.0);
            eventQ.insert(E);
        }

        while(!eventQ.isEmpty()) {

            Event E = eventQ.deleteMin();
            if (E != null) {
                System.out.println("Time is " + E.time);
                if (E.time > Tmax)
                    break;
                if (E.subject.getDeathTime() > E.time) {
                    System.out.println("Type of Event is :" + E.type_of_event);
                    if (E.type_of_event == Event.Type_of_Event.B) {
                        // Birth. When sim x is born at time t
                        birth(E, eventQ, Population);
                    } else if (E.type_of_event == Event.Type_of_Event.M) {
                        reproduction(E,eventQ,Population);
                    }
                } else if (E.type_of_event == Event.Type_of_Event.D) {
                    death(E, Population, PA);
                }
            }
        }
        System.out.println("Population : "+Population.size());
        System.out.println("PA : "+ PA.size());
    }

    public static void birth(Event E, PQ eventQ, ArrayList<Sim> Population){
        System.out.println("This is Birth Event");
        AgeModel M = new AgeModel();
        Random RND = new Random();
        //[n1] we draw a lifetime D at random – put on new death event for x, at time t + D.
        E.subject.setDeathTime( E.time+M.randomAge(RND));  //death
        Event E1 = new Event(E.subject,Event.Type_of_Event.D,E.subject.getDeathTime());
        eventQ.insert(E1);
        //[n2] if x is a daughter, then we pull a wait time A until reproduction - put on
        //new reproduction event for x, at time t + A
        if(E.subject.getSex() == Sim.Sex.F)
        {
            //No of offsprings a woman can born
            E.subject.setChild(RND.nextInt(9));
            //System.out.println("Children : "+ E.subject.getChild());
            //double random_wait = M.randomWaitingTime(RND,.028);
            double random_wait = Math.random() * (50 - 16 + 1) + 16;
            //System.out.println("Random wait : "+ random_wait + " Is Mate : "+E.subject.isMatingAge(random_wait));
            //double random_wait = M.expectedParenthoodSpan(Sim.MIN_MATING_AGE_F, Sim.MAX_MATING_AGE_F);;
            if(E.subject.isMatingAge(random_wait));
            {
                Event E2 = new Event(E.subject,Event.Type_of_Event.M,E.time+random_wait);
                eventQ.insert(E2);
            }
        }
        //[n3] we register x in the population
        Population.add(E.subject);
        System.out.println("Population : "+Population.size());
    }
    public static void death(Event E,ArrayList<Sim> Population,ArrayList<Sim> PA){
        System.out.println("This is Death Event");
        Population.remove(E.subject);
        PA.add(E.subject);
        //System.out.println("PA : "+ PA.toString());
    }
    public static void reproduction(Event E,PQ eventQ, ArrayList<Sim> Population){

        AgeModel M = new AgeModel();
        Random RND = new Random();

        System.out.println("This is Reproduction Event");
        Sim x = E.subject;
        int child = x.getChild();
        //System.out.println("Children Sucks : "+ child);
        if(x.getDeathTime() > E.time && child >0)
        {
            /*if(x.isMatingAge(E.time - x.getBirthTime()))
            {*/
                Sim y = null;
                Sim z;
                if(!x.isInARelationship(E.time) || RND.nextInt(100) > fidelite)
                {
                    do{
          //              System.out.println("this is ffing while"+(E.time-x.getBirthTime()));
                        z = Population.get( RND.nextInt(Population.size()) );
          //              System.out.println("Male not found : "+z.getSex()+" ,Mating time"+(E.time-z.getBirthTime()));
                        if(z.getSex() != x.getSex() && z.isMatingAge(E.time))
                        {
                            if(x.isInARelationship(E.time)||!z.isInARelationship(E.time) || RND.nextInt(100) > fidelite)
                            {
                                y = z;
                            }
                        }
                    }while(y==null);
                }
                else {
                    y = x.getMate();
                }
                //havingBaby
                Sim newBorn = new Sim(x,y,E.time+1,Sim.Sex.randomSex());
                x.setMate(y);
                y.setMate(x);
                //9 month ~= 1 year
                Event E1 = new Event(newBorn,Event.Type_of_Event.B,E.time+1);
                eventQ.insert(E1);
                child = child-1;
                x.setChild(child);
                //Two years gap for birth of child+ 1 year pregnancy = 3
                if(x.isMatingAge(E.time+3))
                {
                    Event E2 = new Event(x, Event.Type_of_Event.M, E.time + 3);
                    eventQ.insert(E2);
                }
                else {
                    x.setChild(0);
                }
            //}
            /*else
            {
                double random_wait = E.time+M.expectedParenthoodSpan(Sim.MIN_MATING_AGE_F, Sim.MAX_MATING_AGE_F);
                if(E.subject.isMatingAge(random_wait));
                {
                    Event E2 = new Event(E.subject,Event.Type_of_Event.M,random_wait);
                    eventQ.insert(E2);
                }
            }*/
        }
    }

}



