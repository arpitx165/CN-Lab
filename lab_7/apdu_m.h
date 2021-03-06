//
// Generated file, do not edit! Created by nedtool 4.6 from apdu.msg.
//

#ifndef _APDU_M_H_
#define _APDU_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>apdu.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet Apdu
 * {
 *     int id;
 *     int type;
 * }
 * </pre>
 */
class Apdu : public ::cPacket
{
  protected:
    int id_var;
    int type_var;

  private:
    void copy(const Apdu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Apdu&);

  public:
    Apdu(const char *name=NULL, int kind=0);
    Apdu(const Apdu& other);
    virtual ~Apdu();
    Apdu& operator=(const Apdu& other);
    virtual Apdu *dup() const {return new Apdu(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual int getType() const;
    virtual void setType(int type);
};

inline void doPacking(cCommBuffer *b, Apdu& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, Apdu& obj) {obj.parsimUnpack(b);}


#endif // ifndef _APDU_M_H_

