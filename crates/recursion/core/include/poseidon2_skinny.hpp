#pragma once

#include "prelude.hpp"

namespace sp1_recursion_core_sys::poseidon2_skinny {
constexpr size_t OUTPUT_ROUND_IDX = NUM_EXTERNAL_ROUNDS + 2;
constexpr size_t INTERNAL_ROUND_IDX = NUM_EXTERNAL_ROUNDS / 2 + 1;

constexpr uint32_t RC_16_30_U32[30][16] = {
    {
        2110014213U,
        3964964605U,
        2190662774U,
        2732996483U,
        640767983U,
        3403899136U,
        1716033721U,
        1606702601U,
        3759873288U,
        1466015491U,
        1498308946U,
        2844375094U,
        3042463841U,
        1969905919U,
        4109944726U,
        3925048366U,
    },
    {
        3706859504U,
        759122502U,
        3167665446U,
        1131812921U,
        1080754908U,
        4080114493U,
        893583089U,
        2019677373U,
        3128604556U,
        580640471U,
        3277620260U,
        842931656U,
        548879852U,
        3608554714U,
        3575647916U,
        81826002U,
    },
    {
        4289086263U,
        1563933798U,
        1440025885U,
        184445025U,
        2598651360U,
        1396647410U,
        1575877922U,
        3303853401U,
        137125468U,
        765010148U,
        633675867U,
        2037803363U,
        2573389828U,
        1895729703U,
        541515871U,
        1783382863U,
    },
    {
        2641856484U,
        3035743342U,
        3672796326U,
        245668751U,
        2025460432U,
        201609705U,
        286217151U,
        4093475563U,
        2519572182U,
        3080699870U,
        2762001832U,
        1244250808U,
        606038199U,
        3182740831U,
        73007766U,
        2572204153U,
    },
    {
        1196780786U,
        3447394443U,
        747167305U,
        2968073607U,
        1053214930U,
        1074411832U,
        4016794508U,
        1570312929U,
        113576933U,
        4042581186U,
        3634515733U,
        1032701597U,
        2364839308U,
        3840286918U,
        888378655U,
        2520191583U,
    },
    {
        36046858U,
        2927525953U,
        3912129105U,
        4004832531U,
        193772436U,
        1590247392U,
        4125818172U,
        2516251696U,
        4050945750U,
        269498914U,
        1973292656U,
        891403491U,
        1845429189U,
        2611996363U,
        2310542653U,
        4071195740U,
    },
    {
        3505307391U,
        786445290U,
        3815313971U,
        1111591756U,
        4233279834U,
        2775453034U,
        1991257625U,
        2940505809U,
        2751316206U,
        1028870679U,
        1282466273U,
        1059053371U,
        834521354U,
        138721483U,
        3100410803U,
        3843128331U,
    },
    {
        3878220780U,
        4058162439U,
        1478942487U,
        799012923U,
        496734827U,
        3521261236U,
        755421082U,
        1361409515U,
        392099473U,
        3178453393U,
        4068463721U,
        7935614U,
        4140885645U,
        2150748066U,
        1685210312U,
        3852983224U,
    },
    {
        2896943075U,
        3087590927U,
        992175959U,
        970216228U,
        3473630090U,
        3899670400U,
        3603388822U,
        2633488197U,
        2479406964U,
        2420952999U,
        1852516800U,
        4253075697U,
        979699862U,
        1163403191U,
        1608599874U,
        3056104448U,
    },
    {
        3779109343U,
        536205958U,
        4183458361U,
        1649720295U,
        1444912244U,
        3122230878U,
        384301396U,
        4228198516U,
        1662916865U,
        4082161114U,
        2121897314U,
        1706239958U,
        4166959388U,
        1626054781U,
        3005858978U,
        1431907253U,
    },
    {
        1418914503U,
        1365856753U,
        3942715745U,
        1429155552U,
        3545642795U,
        3772474257U,
        1621094396U,
        2154399145U,
        826697382U,
        1700781391U,
        3539164324U,
        652815039U,
        442484755U,
        2055299391U,
        1064289978U,
        1152335780U,
    },
    {
        3417648695U,
        186040114U,
        3475580573U,
        2113941250U,
        1779573826U,
        1573808590U,
        3235694804U,
        2922195281U,
        1119462702U,
        3688305521U,
        1849567013U,
        667446787U,
        753897224U,
        1896396780U,
        3143026334U,
        3829603876U,
    },
    {
        859661334U,
        3898844357U,
        180258337U,
        2321867017U,
        3599002504U,
        2886782421U,
        3038299378U,
        1035366250U,
        2038912197U,
        2920174523U,
        1277696101U,
        2785700290U,
        3806504335U,
        3518858933U,
        654843672U,
        2127120275U,
    },
    {
        1548195514U,
        2378056027U,
        390914568U,
        1472049779U,
        1552596765U,
        1905886441U,
        1611959354U,
        3653263304U,
        3423946386U,
        340857935U,
        2208879480U,
        139364268U,
        3447281773U,
        3777813707U,
        55640413U,
        4101901741U,
    },
    {104929687U, 1459980974U, 1831234737U, 457139004U, 2581487628U, 2112044563U,
     3567013861U, 2792004347U, 576325418U, 41126132U, 2713562324U, 151213722U,
     2891185935U, 546846420U, 2939794919U, 2543469905U},
    {
        2191909784U,
        3315138460U,
        530414574U,
        1242280418U,
        1211740715U,
        3993672165U,
        2505083323U,
        3845798801U,
        538768466U,
        2063567560U,
        3366148274U,
        1449831887U,
        2408012466U,
        294726285U,
        3943435493U,
        924016661U,
    },
    {
        3633138367U,
        3222789372U,
        809116305U,
        30100013U,
        2655172876U,
        2564247117U,
        2478649732U,
        4113689151U,
        4120146082U,
        2512308515U,
        650406041U,
        4240012393U,
        2683508708U,
        951073977U,
        3460081988U,
        339124269U,
    },
    {
        130182653U,
        2755946749U,
        542600513U,
        2816103022U,
        1931786340U,
        2044470840U,
        1709908013U,
        2938369043U,
        3640399693U,
        1374470239U,
        2191149676U,
        2637495682U,
        4236394040U,
        2289358846U,
        3833368530U,
        974546524U,
    },
    {
        3306659113U,
        2234814261U,
        1188782305U,
        223782844U,
        2248980567U,
        2309786141U,
        2023401627U,
        3278877413U,
        2022138149U,
        575851471U,
        1612560780U,
        3926656936U,
        3318548977U,
        2591863678U,
        188109355U,
        4217723909U,
    },
    {
        1564209905U,
        2154197895U,
        2459687029U,
        2870634489U,
        1375012945U,
        1529454825U,
        306140690U,
        2855578299U,
        1246997295U,
        3024298763U,
        1915270363U,
        1218245412U,
        2479314020U,
        2989827755U,
        814378556U,
        4039775921U,
    },
    {
        1165280628U,
        1203983801U,
        3814740033U,
        1919627044U,
        600240215U,
        773269071U,
        486685186U,
        4254048810U,
        1415023565U,
        502840102U,
        4225648358U,
        510217063U,
        166444818U,
        1430745893U,
        1376516190U,
        1775891321U,
    },
    {
        1170945922U,
        1105391877U,
        261536467U,
        1401687994U,
        1022529847U,
        2476446456U,
        2603844878U,
        3706336043U,
        3463053714U,
        1509644517U,
        588552318U,
        65252581U,
        3696502656U,
        2183330763U,
        3664021233U,
        1643809916U,
    },
    {
        2922875898U,
        3740690643U,
        3932461140U,
        161156271U,
        2619943483U,
        4077039509U,
        2921201703U,
        2085619718U,
        2065264646U,
        2615693812U,
        3116555433U,
        246100007U,
        4281387154U,
        4046141001U,
        4027749321U,
        111611860U,
    },
    {
        2066954820U,
        2502099969U,
        2915053115U,
        2362518586U,
        366091708U,
        2083204932U,
        4138385632U,
        3195157567U,
        1318086382U,
        521723799U,
        702443405U,
        2507670985U,
        1760347557U,
        2631999893U,
        1672737554U,
        1060867760U,
    },
    {
        2359801781U,
        2800231467U,
        3010357035U,
        1035997899U,
        1210110952U,
        1018506770U,
        2799468177U,
        1479380761U,
        1536021911U,
        358993854U,
        579904113U,
        3432144800U,
        3625515809U,
        199241497U,
        4058304109U,
        2590164234U,
    },
    {
        1688530738U,
        1580733335U,
        2443981517U,
        2206270565U,
        2780074229U,
        2628739677U,
        2940123659U,
        4145206827U,
        3572278009U,
        2779607509U,
        1098718697U,
        1424913749U,
        2224415875U,
        1108922178U,
        3646272562U,
        3935186184U,
    },
    {
        820046587U,
        1393386250U,
        2665818575U,
        2231782019U,
        672377010U,
        1920315467U,
        1913164407U,
        2029526876U,
        2629271820U,
        384320012U,
        4112320585U,
        3131824773U,
        2347818197U,
        2220997386U,
        1772368609U,
        2579960095U,
    },
    {
        3544930873U,
        225847443U,
        3070082278U,
        95643305U,
        3438572042U,
        3312856509U,
        615850007U,
        1863868773U,
        803582265U,
        3461976859U,
        2903025799U,
        1482092434U,
        3902972499U,
        3872341868U,
        1530411808U,
        2214923584U,
    },
    {
        3118792481U,
        2241076515U,
        3983669831U,
        3180915147U,
        3838626501U,
        1921630011U,
        3415351771U,
        2249953859U,
        3755081630U,
        486327260U,
        1227575720U,
        3643869379U,
        2982026073U,
        2466043731U,
        1982634375U,
        3769609014U,
    },
    {
        2195455495U,
        2596863283U,
        4244994973U,
        1983609348U,
        4019674395U,
        3469982031U,
        1458697570U,
        1593516217U,
        1963896497U,
        3115309118U,
        1659132465U,
        2536770756U,
        3059294171U,
        2618031334U,
        2040903247U,
        3799795076U,
    }};

static const bb31_t POSEIDON2_INTERNAL_MATRIX_DIAG_16_BABYBEAR_MONTY[16] = {
    bb31_t::from_canonical_u32(0x78000001u - 2),  // BabyBear::ORDER_U32 - 2
    bb31_t::from_canonical_u32(1),                // 1
    bb31_t::from_canonical_u32(1 << 1),           // 1 << 1
    bb31_t::from_canonical_u32(1 << 2),           // 1 << 2
    bb31_t::from_canonical_u32(1 << 3),           // 1 << 3
    bb31_t::from_canonical_u32(1 << 4),           // 1 << 4
    bb31_t::from_canonical_u32(1 << 5),           // 1 << 5
    bb31_t::from_canonical_u32(1 << 6),           // 1 << 6
    bb31_t::from_canonical_u32(1 << 7),           // 1 << 7
    bb31_t::from_canonical_u32(1 << 8),           // 1 << 8
    bb31_t::from_canonical_u32(1 << 9),           // 1 << 9
    bb31_t::from_canonical_u32(1 << 10),          // 1 << 10
    bb31_t::from_canonical_u32(1 << 11),          // 1 << 11
    bb31_t::from_canonical_u32(1 << 12),          // 1 << 12
    bb31_t::from_canonical_u32(1 << 13),          // 1 << 13
    bb31_t::from_canonical_u32(1 << 15),          // 1 << 15
};

template <class F>
__SP1_HOSTDEV__ __SP1_INLINE__ void external_linear_layer(F* state_var) {
  for (size_t j = 0; j < WIDTH; j += 4) {
    F t01 = state_var[j + 0] + state_var[j + 1];
    F t23 = state_var[j + 2] + state_var[j + 3];
    F t0123 = t01 + t23;
    F t01123 = t0123 + state_var[j + 1];
    F t01233 = t0123 + state_var[j + 3];

    // The order here is important. Need to overwrite x[0] and x[2] after x[1] and x[3].
    state_var[j + 3] =
        t01233 +
        (state_var[j + 0] + state_var[j + 0]);  // 3*x[0] + x[1] + x[2] + 2*x[3]
    state_var[j + 1] =
        t01123 +
        (state_var[j + 2] + state_var[j + 2]);  // x[0] + 2*x[1] + 3*x[2] + x[3]
    state_var[j + 0] = t01123 + t01;            // 2*x[0] + 3*x[1] + x[2] + x[3]
    state_var[j + 2] = t01233 + t23;            // x[0] + x[1] + 2*x[2] + 3*x[3]
  }

  F sums[4] = {F::zero(), F::zero(), F::zero(), F::zero()};
  for (size_t k = 0; k < 4; k++) {
    for (size_t j = 0; j < WIDTH; j += 4) {
      sums[k] = sums[k] + state_var[j + k];
    }
  }

  for (size_t j = 0; j < WIDTH; j++) {
    state_var[j] = state_var[j] + sums[j % 4];
  }
}

template <class F>
__SP1_HOSTDEV__ __SP1_INLINE__ void populate_external_round(F* round_state,
                                                            size_t r,
                                                            F* next_state_var) {
  size_t round =
      (r < NUM_EXTERNAL_ROUNDS / 2) ? r : r + NUM_INTERNAL_ROUNDS - 1;

  for (size_t i = 0; i < WIDTH; i++) {
    F add_rc = round_state[i] + F(F::to_monty(RC_16_30_U32[round][i]));

    F sbox_deg_3 = add_rc * add_rc * add_rc;
    next_state_var[i] = sbox_deg_3 * sbox_deg_3 * add_rc;
  }

  external_linear_layer<F>(next_state_var);
}

template <class F>
__SP1_HOSTDEV__ __SP1_INLINE__ void internal_linear_layer(F* state) {
  F matmul_constants[WIDTH];
  for (size_t i = 0; i < WIDTH; i++) {
    matmul_constants[i] = F(F::to_monty(F::from_monty(
        POSEIDON2_INTERNAL_MATRIX_DIAG_16_BABYBEAR_MONTY[i].val)));
  }

  F sum = F::zero();
  for (size_t i = 0; i < WIDTH; i++) {
    sum = sum + state[i];
  }

  for (size_t i = 0; i < WIDTH; i++) {
    state[i] = state[i] * matmul_constants[i];
    state[i] = state[i] + sum;
  }

  F monty_inverse = F(F::to_monty(F::from_monty(1)));
  for (size_t i = 0; i < WIDTH; i++) {
    state[i] = state[i] * monty_inverse;
  }
}

template <class F>
__SP1_HOSTDEV__ __SP1_INLINE__ void populate_internal_rounds(
    F* state, F* internal_rounds_s0, F* next_state_var) {
  for (size_t i = 0; i < WIDTH; i++) {
    next_state_var[i] = state[i];
  }

  for (size_t r = 0; r < NUM_INTERNAL_ROUNDS; r++) {
    size_t round = r + NUM_EXTERNAL_ROUNDS / 2;
    F add_rc = next_state_var[0] + F(F::to_monty(RC_16_30_U32[round][0]));

    F sbox_deg_3 = add_rc * add_rc * add_rc;
    F sbox_deg_7 = sbox_deg_3 * sbox_deg_3 * add_rc;

    next_state_var[0] = sbox_deg_7;
    internal_linear_layer<F>(next_state_var);

    if (r < NUM_INTERNAL_ROUNDS - 1) {
      internal_rounds_s0[r] = next_state_var[0];
    }
  }
}

template <class F>
__SP1_HOSTDEV__ void event_to_row(const Poseidon2Event<F>& event, size_t len,
                                  Poseidon2<F>* cols) {
  Poseidon2<F>& first_row = cols[0];
  for (size_t i = 0; i < 16; i++) {
    first_row.state_var[i] = event.input[i];
  }

  Poseidon2<F>& second_row = cols[1];
  for (size_t i = 0; i < 16; i++) {
    second_row.state_var[i] = event.input[i];
  }

  external_linear_layer<F>(second_row.state_var);

  for (size_t i = 1; i < OUTPUT_ROUND_IDX; i++) {
    Poseidon2<F>& col = cols[i];
    Poseidon2<F>& next_row_cols = cols[i + 1];

    if (i != INTERNAL_ROUND_IDX) {
      populate_external_round<F>(col.state_var, i - 1, next_row_cols.state_var);
    } else {
      populate_internal_rounds<F>(col.state_var, col.internal_rounds_s0,
                                  next_row_cols.state_var);
    }
  }
}

template <class F>
__SP1_HOSTDEV__ void instr_to_row(const Poseidon2Instr<F>& instr, size_t i,
                                  size_t len,
                                  Poseidon2PreprocessedColsSkinny<F>* cols) {}
}  // namespace sp1_recursion_core_sys::poseidon2_skinny
