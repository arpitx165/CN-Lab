//
// Generated file, do not edit! Created by nedtool 4.6 from npdu.msg.
//

#ifndef _NPDU_M_H_
#define _NPDU_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>npdu.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet Npdu
 * {
 *     int id;
 *     int type;
 *     int src;
 *     int dest;
 *     simtime_t del;
 * }
 * </pre>
 */
class Npdu : public ::cPacket
{
  protected:
    int id_var;
    int type_var;
    int src_var;
    int dest_var;
    simtime_t del_var;

  private:
    void copy(const Npdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Npdu&);

  public:
    Npdu(const char *name=NULL, int kind=0);
    Npdu(const Npdu& other);
    virtual ~Npdu();
    Npdu& operator=(const Npdu& other);
    virtual Npdu *dup() const {return new Npdu(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getType() const;
    virtual void setType(int type);
    virtual int getSrc() const;
    virtual void setSrc(int src);
    virtual int getDest() const;
    virtual void setDest(int dest);
    virtual simtime_t getDel() const;
    virtual void setDel(simtime_t del);
};

inline void doPacking(cCommBuffer *b, Npdu& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Npdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef _NPDU_M_H_

