#ifndef __ONCSSUB_IDINTTV0_H__
#define __ONCSSUB_IDINTTV0_H__

#include "oncsSubevent.h"
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdint.h>


#ifndef __CINT__
class WINDOWSEXPORT oncsSub_idinttv0 : public  oncsSubevent_w2 {
#else
class  oncsSub_idinttv0 : public  oncsSubevent_w2 {
#endif

public:
  oncsSub_idinttv0( subevtdata_ptr);
  ~oncsSub_idinttv0();

  //int    iValue(const int fee, const int ch, const int sample);
  //  int    iValue(const int fee, const int ch, const int sample, const char *what);
  int    iValue(const int hit, const int field);
  long long    lValue(const int hit, const int field);

  int    iValue(const int , const int, const char * what);

  int    iValue(const int hit,const char * what);
  long long    lValue(const int hit,const char * what);

  void  dump ( OSTREAM& os = COUT) ;


protected:
  int intt_decode ();

  static const int MAX_FEECOUNT =16;
  
  unsigned short reverseBits(const unsigned short x) const;
  unsigned short crc16(const unsigned int fee, const unsigned int index, const int  l) const;

  int _broken;
  
  int _is_decoded;

  struct intt_hit
  {
    uint64_t bco;
    uint16_t fee;
    uint16_t channel_id;
    uint16_t chip_id;
    uint16_t adc;
    uint16_t FPHX_BCO;
    uint16_t full_FPHX;
    uint16_t full_ROC;
    uint16_t amplitude;
    uint16_t full_fphx;
    uint32_t word;
  };

    
  std::vector<unsigned int> fee_data[MAX_FEECOUNT];
  std::vector<intt_hit *> intt_hits;

};

 
#endif /* __ONCSSUB_IDINTTV0_H__ */
