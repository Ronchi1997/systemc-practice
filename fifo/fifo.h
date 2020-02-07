#ifndef _FIFO_H
#define _FIFO_H

#include "systemc.h"
#define MAX 5
class read_interface:
virtual public sc_interface {
  public:
    virtual void read_data(int &data) = 0;
};
class write_interface:
virtual public sc_interface {
  public:
    virtual void write_data(int data) = 0;
};

class fifo:
public read_interface, public write_interface, public sc_channel {
  public:
    fifo(sc_module_name name):sc_channel(name), num(0), head(0) {}
    void read_data(int &data) {
      if (num == 0) {
        cout << "the fifo is empty!" << endl;
        wait(write_event);
      }
      data = all_data[head];
      num--;
      head = (head + 1) % MAX;
      read_event.notify();
    }
    void write_data(int data) {
      if (num == MAX) {
        cout << "the fifo is full!" << endl;
        wait(read_event);
      }
      all_data[(head + num) % MAX] = data;
      num++;
      write_event.notify();
    }
  private:
    int all_data[MAX];
    int head, num;
    sc_event read_event, write_event;
};

#endif
