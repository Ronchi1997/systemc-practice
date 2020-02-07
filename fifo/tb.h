#ifndef _TB_H
#define _TB_H

#include "systemc.h"
#include "fifo.h"
SC_MODULE(tb) {
  public:
    sc_port<read_interface> read_port;
    sc_port<write_interface> write_port;

    SC_CTOR(tb) {
      SC_THREAD(read);
      SC_THREAD(write);
    }

    void read() {
      int data;
      while (true) {
        read_port->read_data(data);
        cout << "read data: " << data << endl;
      }
    }

    void write() {
      wait(1, SC_NS);
      write_port->write_data(1);
      wait(1, SC_NS);
      write_port->write_data(2);
      write_port->write_data(3);
      write_port->write_data(4);
      write_port->write_data(5);
      wait(2, SC_NS);
      write_port->write_data(6);
      write_port->write_data(7);
      write_port->write_data(8);
      write_port->write_data(9);
      write_port->write_data(1);
      write_port->write_data(2);
      write_port->write_data(3);
      write_port->write_data(4);
      sc_stop();
    }
};

#endif
