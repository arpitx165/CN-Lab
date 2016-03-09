//
// Generated file, do not edit! Created by nedtool 4.6 from D_pdu.msg.
//

#ifndef _D_PDU_M_H_
#define _D_PDU_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>D_pdu.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet D_pdu
 * {
 *     int id;
 *     int type;
 *     char a;
 * }
 * </pre>
 */
class D_pdu : public ::cPacket
{
  protected:
    int id_var;
    int type_var;
    char a_var;

  private:
    void copy(const D_pdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const D_pdu&);

  public:
    D_pdu(const char *name=NULL, int kind=0);
    D_pdu(const D_pdu& other);
    virtual ~D_pdu();
    D_pdu& operator=(const D_pdu& other);
    virtual D_pdu *dup() const {return new D_pdu(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getType() const;
    virtual void setType(int type);
    virtual char getA() const;
    virtual void setA(char a);
};

inline void doPacking(cCommBuffer *b, D_pdu& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, D_pdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef _D_PDU_M_H_

