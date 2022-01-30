package pedigree;

import java.util.Random;

public class Event {
    //E.subject: subject of the event, a sim
    public Sim subject;
    //type of event: birth, death or mating
    public enum Type_of_Event {B, D, M};
    //E.time: time of the event, a non-negative floating-point number
    public double time,lifespan;
    public Type_of_Event type_of_event;
    public Event(Sim subject,Type_of_Event type_of_event,double time){

        this.subject = subject;
        this.type_of_event = type_of_event;
        this.time = time;

    }

}
