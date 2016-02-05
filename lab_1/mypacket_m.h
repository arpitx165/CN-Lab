//
// Generated file, do not edit! Created by nedtool 4.6 from mypacket.msg.
//

#ifndef _MYPACKET_M_H_
#define _MYPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>mypacket.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet Mypacket
 * {
 *     int id;
 *     int type;
 * 
 * }
 * </pre>
 */
class Mypacket : public ::cPacket
{
  protected:
    int id_var;
    int type_var;

  private:
    void copy(const Mypacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Mypacket&);

  public:
    Mypacket(const char *name=NULL, int kind=0);
    Mypacket(const Mypacket& other);
    virtual ~Mypacket();
    Mypacket& operator=(const Mypacket& other);
    virtual Mypacket *dup() const {return new Mypacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getType() const;
    virtual void setType(int type);
};

inline void doPacking(cCommBuffer *b, Mypacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Mypacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _MYPACKET_M_H_
