#include "__cf_modelo2760.h"
#include <math.h>
#include "modelo2760_acc.h"
#include "modelo2760_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { ZCEventType zcEvent ;
boolean_T resetIntg ; boolean_T didZcEventOccur ; real_T * lastU ; real_T
dqzlhei05k ; real_T ibnzey0tq1 ; real_T ausxxd0w41 ; real_T b1qsad2btx ;
real_T mp0h44g5pf ; gs5ziytpge * _rtB ; htz2yn2nki * _rtP ; j5gsxufhrr * _rtX
; c2r2iavy5n * _rtZCE ; n1zoaldecr * _rtDW ; _rtDW = ( ( n1zoaldecr * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( c2r2iavy5n * ) _ssGetPrevZCSigState ( S
) ) ; _rtX = ( ( j5gsxufhrr * ) ssGetContStates ( S ) ) ; _rtP = ( (
htz2yn2nki * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( gs5ziytpge * )
_ssGetModelBlockIO ( S ) ) ; b1qsad2btx = _rtX -> lzn01n0jvy ; mp0h44g5pf =
_rtX -> bpqin3mp53 ; _rtB -> ia2f4vhb4h = _rtX -> oxv2lrdo03 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( _rtB -> ia2f4vhb4h > 0.0 ) { _rtDW ->
gxn1w3khsp = 1 ; } else if ( _rtB -> ia2f4vhb4h < 0.0 ) { _rtDW -> gxn1w3khsp
= - 1 ; } else { _rtDW -> gxn1w3khsp = 0 ; } _rtB -> gghv5v3hwv = _rtDW ->
gxn1w3khsp ; } _rtB -> mizqn4ixt5 = _rtB -> gghv5v3hwv * _rtX -> ibeinvyizk ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> aekavliliu , ( _rtB -> mizqn4ixt5 - _rtP
-> P_8 ) ) ; if ( _rtDW -> dsez2ov1ja == 0 ) { if ( zcEvent != NO_ZCEVENT ) {
_rtB -> czd5nwd1gf = ! _rtB -> czd5nwd1gf ; _rtDW -> dsez2ov1ja = 1 ; } else
{ if ( _rtB -> czd5nwd1gf && ( _rtB -> mizqn4ixt5 != _rtP -> P_8 ) ) { _rtB
-> czd5nwd1gf = false ; } } } else { if ( _rtB -> mizqn4ixt5 != _rtP -> P_8 )
{ _rtB -> czd5nwd1gf = false ; } _rtDW -> dsez2ov1ja = 0 ; } } _rtB ->
hsmfqwcg0h = ssGetT ( S ) ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
bonyc0ewa3 = ( _rtB -> hsmfqwcg0h > _rtP -> P_11 ) ; } if ( _rtDW ->
bonyc0ewa3 ) { _rtB -> li235j3oj3 = _rtX -> ibeinvyizk * _rtB -> mbmltcst3a ;
_rtB -> cg32zrk3o1 = _rtB -> li235j3oj3 ; } else { _rtB -> cg32zrk3o1 = _rtB
-> moqkwv3wkx ; } if ( ssIsMajorTimeStep ( S ) ) { resetIntg = false ;
didZcEventOccur = ( _rtB -> czd5nwd1gf && ( _rtZCE -> l5zr3rivfc != POS_ZCSIG
) ) ; _rtZCE -> l5zr3rivfc = _rtB -> czd5nwd1gf ; if ( didZcEventOccur || (
_rtDW -> hadafjjnwk != 0 ) ) { resetIntg = true ; _rtX -> ibeinvyizk = _rtB
-> cg32zrk3o1 ; } if ( resetIntg ) { ssSetSolverNeedsReset ( S ) ;
ssSetBlkStateChange ( S ) ; } if ( _rtX -> ibeinvyizk >= _rtP -> P_12 ) {
_rtX -> ibeinvyizk = _rtP -> P_12 ; } else { if ( _rtX -> ibeinvyizk <= _rtP
-> P_13 ) { _rtX -> ibeinvyizk = _rtP -> P_13 ; } } } _rtB -> poapjsg4bj =
_rtX -> ibeinvyizk ; dqzlhei05k = _rtP -> P_15 * _rtX -> cfcgrtxou0 ; _rtB ->
cb5ukqf3b3 = muDoubleScalarCos ( _rtB -> poapjsg4bj ) * dqzlhei05k + _rtB ->
dya14a5ees ; ibnzey0tq1 = _rtB -> ezifwmclew + _rtB -> cb5ukqf3b3 ; _rtB ->
pz35dx1tf2 = muDoubleScalarSin ( _rtB -> poapjsg4bj ) * dqzlhei05k + _rtB ->
bff0hhci0u ; dqzlhei05k = _rtB -> a4ict3kcnn + _rtB -> pz35dx1tf2 ; _rtB ->
dad3q0r0s0 = ibnzey0tq1 * _rtB -> htpmfyrgeh + dqzlhei05k * _rtB ->
m2eqvyulja ; _rtB -> csmn0ossyy = dqzlhei05k * _rtB -> htpmfyrgeh -
ibnzey0tq1 * _rtB -> m2eqvyulja ; _rtB -> bsvinq3ihr [ 0 ] = b1qsad2btx ;
_rtB -> bsvinq3ihr [ 1 ] = mp0h44g5pf ; _rtB -> bsvinq3ihr [ 2 ] = _rtB ->
dad3q0r0s0 ; _rtB -> bsvinq3ihr [ 3 ] = _rtB -> csmn0ossyy ;
ssCallAccelRunBlock ( S , 5 , 39 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> nxafqcmeyc
= _rtB -> aeaxqzqe5g * _rtX -> kcof43dofp ; if ( ssIsSampleHit ( S , 1 , 0 )
) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & _rtZCE -> bx2wjwzsia , (
_rtB -> nxafqcmeyc - _rtP -> P_21 ) ) ; if ( _rtDW -> cqsjt1j0cc == 0 ) { if
( zcEvent != NO_ZCEVENT ) { _rtB -> gr0dxb1jb3 = ! _rtB -> gr0dxb1jb3 ; _rtDW
-> cqsjt1j0cc = 1 ; } else { if ( _rtB -> gr0dxb1jb3 && ( _rtB -> nxafqcmeyc
!= _rtP -> P_21 ) ) { _rtB -> gr0dxb1jb3 = false ; } } } else { if ( _rtB ->
nxafqcmeyc != _rtP -> P_21 ) { _rtB -> gr0dxb1jb3 = false ; } _rtDW ->
cqsjt1j0cc = 0 ; } } _rtB -> a1telb4n1o = ssGetT ( S ) ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> jyi2g15b0f = ( _rtB -> a1telb4n1o > _rtP
-> P_24 ) ; } if ( _rtDW -> jyi2g15b0f ) { _rtB -> hgx42uvo3k = _rtX ->
kcof43dofp * _rtB -> bqirqjvohk ; _rtB -> gg5jkshhle = _rtB -> hgx42uvo3k ; }
else { _rtB -> gg5jkshhle = _rtB -> kvxl1zee13 ; } if ( ssIsMajorTimeStep ( S
) ) { resetIntg = false ; didZcEventOccur = ( _rtB -> gr0dxb1jb3 && ( _rtZCE
-> gjf5jhacpx != POS_ZCSIG ) ) ; _rtZCE -> gjf5jhacpx = _rtB -> gr0dxb1jb3 ;
if ( didZcEventOccur || ( _rtDW -> jmc450kfg2 != 0 ) ) { resetIntg = true ;
_rtX -> kcof43dofp = _rtB -> gg5jkshhle ; } if ( resetIntg ) {
ssSetSolverNeedsReset ( S ) ; ssSetBlkStateChange ( S ) ; } if ( _rtX ->
kcof43dofp >= _rtP -> P_25 ) { _rtX -> kcof43dofp = _rtP -> P_25 ; } else {
if ( _rtX -> kcof43dofp <= _rtP -> P_26 ) { _rtX -> kcof43dofp = _rtP -> P_26
; } } } b1qsad2btx = _rtX -> kcof43dofp ; _rtB -> knun3dv5ww [ 0 ] = _rtP ->
P_27 * _rtX -> kcof43dofp ; _rtB -> knun3dv5ww [ 1 ] = _rtP -> P_27 * _rtB ->
poapjsg4bj ; ssCallAccelRunBlock ( S , 5 , 52 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> ix2f000t5r = b1qsad2btx - _rtB -> dl4qlshyma ; ssCallAccelRunBlock ( S , 2
, 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ipnahoymdm = 0.0 ; _rtB -> ipnahoymdm
+= _rtP -> P_30 * _rtX -> j0bxzlc1tu ; mp0h44g5pf = _rtP -> P_32 * _rtX ->
hf2gh3ehtn + _rtP -> P_33 * _rtB -> ipnahoymdm ; _rtB -> ehoj0v20yg =
b1qsad2btx - _rtB -> dl4qlshyma ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> o5wfcu5ypn = _rtB -> ehoj0v20yg ; ssCallAccelRunBlock ( S , 3 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; ausxxd0w41 = _rtP -> P_34 * _rtB -> lhjqc5kocw ; }
_rtB -> jade131oby = _rtB -> bzb2iuw2ib - _rtB -> ipnahoymdm ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> jktxiqjsb3 = _rtB -> ipnahoymdm ;
_rtDW -> b0d2wzv5zh = ( _rtB -> jktxiqjsb3 - _rtP -> P_37 [ 1 ] * _rtDW ->
bpzowvgtdq ) / _rtP -> P_37 [ 0 ] ; _rtB -> jeohzskc3m = ( _rtP -> P_35 *
_rtB -> jade131oby + ausxxd0w41 ) - ( ( _rtP -> P_36 [ 0 ] * _rtDW ->
b0d2wzv5zh + _rtP -> P_36 [ 1 ] * _rtDW -> bpzowvgtdq ) + _rtP -> P_39 * _rtB
-> jktxiqjsb3 ) * _rtP -> P_40 ; } if ( ( int32_T ) _rtB -> gw05vc5lzv == 0 )
{ _rtB -> p4haxfpm3w = ( ( _rtB -> bzb2iuw2ib - _rtB -> ipnahoymdm ) * _rtP
-> P_2 + _rtP -> P_3 * _rtB -> jmndytucxg ) - ( _rtP -> P_0 * _rtB ->
ipnahoymdm + mp0h44g5pf ) * _rtP -> P_1 ; } else { _rtB -> p4haxfpm3w = _rtB
-> jeohzskc3m ; } _rtB -> m2xvqyd3vb [ 0 ] = _rtP -> P_41 * _rtB ->
ia2f4vhb4h ; _rtB -> m2xvqyd3vb [ 1 ] = _rtP -> P_41 * _rtB -> p4haxfpm3w ;
_rtB -> j2pvi42cwq [ 0 ] = _rtP -> P_42 * _rtB -> ipnahoymdm ; _rtB ->
j2pvi42cwq [ 1 ] = _rtP -> P_42 * _rtB -> bzb2iuw2ib ; _rtB -> p3qj5xuayo [ 0
] = _rtB -> knun3dv5ww [ 0 ] ; _rtB -> p3qj5xuayo [ 2 ] = _rtB -> m2xvqyd3vb
[ 0 ] ; _rtB -> p3qj5xuayo [ 4 ] = _rtB -> j2pvi42cwq [ 0 ] ; _rtB ->
p3qj5xuayo [ 1 ] = _rtB -> knun3dv5ww [ 1 ] ; _rtB -> p3qj5xuayo [ 3 ] = _rtB
-> m2xvqyd3vb [ 1 ] ; _rtB -> p3qj5xuayo [ 5 ] = _rtB -> j2pvi42cwq [ 1 ] ;
ssCallAccelRunBlock ( S , 5 , 75 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 76 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 77 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW ->
fcs4sh0kft >= ssGetT ( S ) ) && ( _rtDW -> ie1ana42c3 >= ssGetT ( S ) ) ) {
ausxxd0w41 = 0.0 ; } else { ausxxd0w41 = _rtDW -> fcs4sh0kft ; lastU = &
_rtDW -> bkzxmklzrk ; if ( _rtDW -> fcs4sh0kft < _rtDW -> ie1ana42c3 ) { if (
_rtDW -> ie1ana42c3 < ssGetT ( S ) ) { ausxxd0w41 = _rtDW -> ie1ana42c3 ;
lastU = & _rtDW -> d2sc4c4pzu ; } } else { if ( _rtDW -> fcs4sh0kft >= ssGetT
( S ) ) { ausxxd0w41 = _rtDW -> ie1ana42c3 ; lastU = & _rtDW -> d2sc4c4pzu ;
} } ausxxd0w41 = ( _rtB -> gptkglghjx - * lastU ) / ( ssGetT ( S ) -
ausxxd0w41 ) ; } _rtB -> bsvinq3ihr [ 0 ] = _rtP -> P_43 * _rtB -> poapjsg4bj
; _rtB -> bsvinq3ihr [ 1 ] = _rtP -> P_43 * _rtB -> ldu4omxyog ; _rtB ->
bsvinq3ihr [ 2 ] = _rtP -> P_43 * _rtB -> gptkglghjx ; _rtB -> bsvinq3ihr [ 3
] = _rtP -> P_43 * ausxxd0w41 ; ssCallAccelRunBlock ( S , 5 , 80 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 81 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 82 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 83 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> p1ybpdrwct = ssGetT ( S ) ;
ssCallAccelRunBlock ( S , 5 , 85 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> olmx3pqu0m = _rtB -> p4haxfpm3w >= _rtP
-> P_44 ? 1 : _rtB -> p4haxfpm3w > _rtP -> P_45 ? 0 : - 1 ; } _rtB ->
biiccya4bp = ( _rtDW -> olmx3pqu0m == 1 ? _rtP -> P_44 : _rtDW -> olmx3pqu0m
== - 1 ? _rtP -> P_45 : _rtB -> p4haxfpm3w ) - _rtB -> ia2f4vhb4h ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> h4rrfndigt = _rtB -> biiccya4bp >= _rtP
-> P_46 ? 1 : _rtB -> biiccya4bp > _rtP -> P_47 ? 0 : - 1 ; } _rtB ->
oy5c5mbaym = ( _rtDW -> h4rrfndigt == 1 ? _rtP -> P_46 : _rtDW -> h4rrfndigt
== - 1 ? _rtP -> P_47 : _rtB -> biiccya4bp ) * _rtP -> P_48 ;
UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID3 ( SimStruct * S ,
int_T tid ) { gs5ziytpge * _rtB ; htz2yn2nki * _rtP ; _rtP = ( ( htz2yn2nki *
) ssGetModelRtp ( S ) ) ; _rtB = ( ( gs5ziytpge * ) _ssGetModelBlockIO ( S )
) ; _rtB -> ezifwmclew = _rtP -> P_6 ; _rtB -> mbmltcst3a = _rtP -> P_9 ;
_rtB -> moqkwv3wkx = _rtP -> P_10 ; _rtB -> dya14a5ees = _rtP -> P_16 *
muDoubleScalarCos ( _rtP -> P_17 ) ; _rtB -> htpmfyrgeh = muDoubleScalarCos (
_rtP -> P_18 ) ; _rtB -> a4ict3kcnn = _rtP -> P_19 ; _rtB -> bff0hhci0u =
_rtP -> P_16 * muDoubleScalarSin ( _rtP -> P_17 ) ; _rtB -> m2eqvyulja =
muDoubleScalarSin ( _rtP -> P_18 ) ; _rtB -> bzb2iuw2ib = _rtP -> P_20 ; _rtB
-> aeaxqzqe5g = muDoubleScalarSign ( _rtB -> bzb2iuw2ib ) ; _rtB ->
bqirqjvohk = _rtP -> P_22 ; _rtB -> kvxl1zee13 = _rtP -> P_23 ; _rtB ->
gw05vc5lzv = _rtP -> P_28 ; _rtB -> muzjy1xkdl = _rtP -> P_49 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
gs5ziytpge * _rtB ; htz2yn2nki * _rtP ; j5gsxufhrr * _rtX ; n1zoaldecr *
_rtDW ; _rtDW = ( ( n1zoaldecr * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
j5gsxufhrr * ) ssGetContStates ( S ) ) ; _rtP = ( ( htz2yn2nki * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( gs5ziytpge * ) _ssGetModelBlockIO ( S ) )
; _rtDW -> hadafjjnwk = 0 ; if ( _rtX -> ibeinvyizk == _rtP -> P_12 ) {
switch ( _rtDW -> kpmukgr2ox ) { case 3 : if ( _rtB -> ipnahoymdm < 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> kpmukgr2ox = 1 ; } break ; case 1 : if
( _rtB -> ipnahoymdm >= 0.0 ) { _rtDW -> kpmukgr2ox = 3 ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> ipnahoymdm < 0.0 ) { _rtDW -> kpmukgr2ox = 1 ; } else { _rtDW
-> kpmukgr2ox = 3 ; } break ; } } else if ( _rtX -> ibeinvyizk == _rtP ->
P_13 ) { switch ( _rtDW -> kpmukgr2ox ) { case 4 : if ( _rtB -> ipnahoymdm >
0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> kpmukgr2ox = 2 ; } break ;
case 2 : if ( _rtB -> ipnahoymdm <= 0.0 ) { _rtDW -> kpmukgr2ox = 4 ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> ipnahoymdm > 0.0 ) { _rtDW -> kpmukgr2ox = 2 ; } else { _rtDW
-> kpmukgr2ox = 4 ; } break ; } } else { _rtDW -> kpmukgr2ox = 0 ; } _rtDW ->
jmc450kfg2 = 0 ; if ( _rtX -> kcof43dofp == _rtP -> P_25 ) { switch ( _rtDW
-> e54d34cr14 ) { case 3 : if ( _rtB -> bzb2iuw2ib < 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> e54d34cr14 = 1 ; } break ; case 1 : if
( _rtB -> bzb2iuw2ib >= 0.0 ) { _rtDW -> e54d34cr14 = 3 ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> bzb2iuw2ib < 0.0 ) { _rtDW -> e54d34cr14 = 1 ; } else { _rtDW
-> e54d34cr14 = 3 ; } break ; } } else if ( _rtX -> kcof43dofp == _rtP ->
P_26 ) { switch ( _rtDW -> e54d34cr14 ) { case 4 : if ( _rtB -> bzb2iuw2ib >
0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> e54d34cr14 = 2 ; } break ;
case 2 : if ( _rtB -> bzb2iuw2ib <= 0.0 ) { _rtDW -> e54d34cr14 = 4 ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> bzb2iuw2ib > 0.0 ) { _rtDW -> e54d34cr14 = 2 ; } else { _rtDW
-> e54d34cr14 = 4 ; } break ; } } else { _rtDW -> e54d34cr14 = 0 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> bpzowvgtdq = _rtDW -> b0d2wzv5zh ; }
if ( _rtDW -> fcs4sh0kft == ( rtInf ) ) { _rtDW -> fcs4sh0kft = ssGetT ( S )
; lastU = & _rtDW -> bkzxmklzrk ; } else if ( _rtDW -> ie1ana42c3 == ( rtInf
) ) { _rtDW -> ie1ana42c3 = ssGetT ( S ) ; lastU = & _rtDW -> d2sc4c4pzu ; }
else if ( _rtDW -> fcs4sh0kft < _rtDW -> ie1ana42c3 ) { _rtDW -> fcs4sh0kft =
ssGetT ( S ) ; lastU = & _rtDW -> bkzxmklzrk ; } else { _rtDW -> ie1ana42c3 =
ssGetT ( S ) ; lastU = & _rtDW -> d2sc4c4pzu ; } * lastU = _rtB -> gptkglghjx
; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { gs5ziytpge * _rtB ; htz2yn2nki
* _rtP ; j5gsxufhrr * _rtX ; gwoqhhn3tz * _rtXdis ; erbqkrlzqi * _rtXdot ;
n1zoaldecr * _rtDW ; _rtDW = ( ( n1zoaldecr * ) ssGetRootDWork ( S ) ) ;
_rtXdot = ( ( erbqkrlzqi * ) ssGetdX ( S ) ) ; _rtXdis = ( ( gwoqhhn3tz * )
ssGetContStateDisabled ( S ) ) ; _rtX = ( ( j5gsxufhrr * ) ssGetContStates (
S ) ) ; _rtP = ( ( htz2yn2nki * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
gs5ziytpge * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot -> lzn01n0jvy = _rtB ->
cb5ukqf3b3 ; _rtXdot -> bpqin3mp53 = _rtB -> pz35dx1tf2 ; _rtXdot ->
oxv2lrdo03 = _rtB -> oy5c5mbaym ; if ( ( _rtDW -> kpmukgr2ox != 3 ) && (
_rtDW -> kpmukgr2ox != 4 ) ) { _rtXdot -> ibeinvyizk = _rtB -> ipnahoymdm ;
_rtXdis -> ibeinvyizk = false ; } else { _rtXdot -> ibeinvyizk = 0.0 ; if ( (
_rtDW -> kpmukgr2ox == 3 ) || ( _rtDW -> kpmukgr2ox == 4 ) ) { _rtXdis ->
ibeinvyizk = true ; } } _rtXdot -> cfcgrtxou0 = 0.0 ; _rtXdot -> cfcgrtxou0
+= _rtP -> P_14 * _rtX -> cfcgrtxou0 ; _rtXdot -> cfcgrtxou0 += _rtB ->
muzjy1xkdl ; if ( ( _rtDW -> e54d34cr14 != 3 ) && ( _rtDW -> e54d34cr14 != 4
) ) { _rtXdot -> kcof43dofp = _rtB -> bzb2iuw2ib ; _rtXdis -> kcof43dofp =
false ; } else { _rtXdot -> kcof43dofp = 0.0 ; if ( ( _rtDW -> e54d34cr14 ==
3 ) || ( _rtDW -> e54d34cr14 == 4 ) ) { _rtXdis -> kcof43dofp = true ; } }
_rtXdot -> j0bxzlc1tu = 0.0 ; _rtXdot -> j0bxzlc1tu += _rtP -> P_29 * _rtX ->
j0bxzlc1tu ; _rtXdot -> j0bxzlc1tu += _rtB -> ia2f4vhb4h ; _rtXdot ->
hf2gh3ehtn = 0.0 ; _rtXdot -> hf2gh3ehtn += _rtP -> P_31 * _rtX -> hf2gh3ehtn
; _rtXdot -> hf2gh3ehtn += _rtB -> ipnahoymdm ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { boolean_T anyStateSaturated
; gs5ziytpge * _rtB ; htz2yn2nki * _rtP ; j5gsxufhrr * _rtX ; calid1p23t *
_rtZCSV ; n1zoaldecr * _rtDW ; _rtDW = ( ( n1zoaldecr * ) ssGetRootDWork ( S
) ) ; _rtZCSV = ( ( calid1p23t * ) ssGetSolverZcSignalVector ( S ) ) ; _rtX =
( ( j5gsxufhrr * ) ssGetContStates ( S ) ) ; _rtP = ( ( htz2yn2nki * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( gs5ziytpge * ) _ssGetModelBlockIO ( S ) )
; _rtZCSV -> jgeegiygw0 = _rtB -> ia2f4vhb4h ; _rtZCSV -> khk5gr5pwz = _rtB
-> mizqn4ixt5 - _rtP -> P_8 ; if ( _rtDW -> dsez2ov1ja == 0 ) { _rtZCSV ->
pckbahrgdz = ( ( _rtB -> mizqn4ixt5 - _rtP -> P_8 ) * ( real_T ) _rtB ->
czd5nwd1gf != 0.0 ) ; } else { _rtZCSV -> pckbahrgdz = ssGetT ( S ) -
ssGetTimeOfLastOutput ( S ) ; } _rtZCSV -> hkcnt0m1oi = _rtB -> hsmfqwcg0h -
_rtP -> P_11 ; if ( ( _rtDW -> kpmukgr2ox == 1 ) && ( _rtX -> ibeinvyizk >=
_rtP -> P_12 ) ) { _rtZCSV -> iz41wahk0n = 0.0 ; } else { _rtZCSV ->
iz41wahk0n = _rtX -> ibeinvyizk - _rtP -> P_12 ; } if ( ( _rtDW -> kpmukgr2ox
== 2 ) && ( _rtX -> ibeinvyizk <= _rtP -> P_13 ) ) { _rtZCSV -> k2kv55mdci =
0.0 ; } else { _rtZCSV -> k2kv55mdci = _rtX -> ibeinvyizk - _rtP -> P_13 ; }
anyStateSaturated = false ; if ( ( _rtDW -> kpmukgr2ox == 3 ) || ( _rtDW ->
kpmukgr2ox == 4 ) ) { anyStateSaturated = true ; } if ( anyStateSaturated ) {
_rtZCSV -> pgy4b4hc50 = _rtB -> ipnahoymdm ; } else { _rtZCSV -> pgy4b4hc50 =
0.0 ; } _rtZCSV -> oegrv1kyer = _rtB -> nxafqcmeyc - _rtP -> P_21 ; if (
_rtDW -> cqsjt1j0cc == 0 ) { _rtZCSV -> o3hcaijtiz = ( ( _rtB -> nxafqcmeyc -
_rtP -> P_21 ) * ( real_T ) _rtB -> gr0dxb1jb3 != 0.0 ) ; } else { _rtZCSV ->
o3hcaijtiz = ssGetT ( S ) - ssGetTimeOfLastOutput ( S ) ; } _rtZCSV ->
nlgq3eimzk = _rtB -> a1telb4n1o - _rtP -> P_24 ; if ( ( _rtDW -> e54d34cr14
== 1 ) && ( _rtX -> kcof43dofp >= _rtP -> P_25 ) ) { _rtZCSV -> hvehj0omuy =
0.0 ; } else { _rtZCSV -> hvehj0omuy = _rtX -> kcof43dofp - _rtP -> P_25 ; }
if ( ( _rtDW -> e54d34cr14 == 2 ) && ( _rtX -> kcof43dofp <= _rtP -> P_26 ) )
{ _rtZCSV -> fm2bosci3r = 0.0 ; } else { _rtZCSV -> fm2bosci3r = _rtX ->
kcof43dofp - _rtP -> P_26 ; } _rtZCSV -> lmihcqbno4 = _rtB -> p4haxfpm3w -
_rtP -> P_44 ; _rtZCSV -> iqfibhc0ex = _rtB -> p4haxfpm3w - _rtP -> P_45 ;
_rtZCSV -> bviburim0u = _rtB -> biiccya4bp - _rtP -> P_46 ; _rtZCSV ->
dgdwmntats = _rtB -> biiccya4bp - _rtP -> P_47 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 1505804759U
) ; ssSetChecksumVal ( S , 1 , 807440493U ) ; ssSetChecksumVal ( S , 2 ,
1039678487U ) ; ssSetChecksumVal ( S , 3 , 2381632945U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.7" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( n1zoaldecr ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( gs5ziytpge ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
htz2yn2nki ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & eb0ttazf02 ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
