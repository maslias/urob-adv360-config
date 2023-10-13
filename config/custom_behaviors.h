/*                                 ADVANTAGE 360 KEY MATRIX / LAYOUT MAPPING
 ╭────────────────────────────┬────────────────────────────╮ ╭────────────────────────────┬────────────────────────────╮
 │  0   1   2   3   4   5   6 │  7   8   9  10  11  12  13 │ │ LN5 LN4 LN3 LN2 LN1 LN0 -- │ --  RN0 RN1 RN2 RN3 RN4 RN5│
 │ 14  15  16  17  18  19  20 │ 21  22  23  24  25  26  27 │ │ LT5 LT4 LT3 LT2 LT1 LT0 -- │ --  RT0 RT1 RT2 RT3 RT4 RT5│
 │ 28  29  30  31  32  33  34 │ 35  36  37  38  39  40  41 │ │ LM5 LM4 LM3 LM2 LM1 LM0 -- │ --  RM0 RM1 RM2 RM3 RM4 RM5│
 │ 42  43  44  45  46  47 ╭───┴───╮ 48  49  50  51  52  53 │ │ LB5 LB4 LB3 LB2 LB1 LB0╭───┴───╮ RB0 RB1 RB2 RB3 RB4 RB5│
 │ 54  55  56  57  58╭────╯       ╰────╮59  60  61  62  63 │ │ --  --  --  --  --╭────╯       ╰────╮--  --  --  --  -- │
 ╰───────────────────┼────────┬────────┼───────────────────╯ ╰───────────────────┼────────┬────────┼───────────────────╯
                 ╭───╯ 64  65 │ 66  67 ╰───╮                                 ╭───╯ --  -- │ --  -- ╰───╮
                 │ 68  69  70 │ 71  72  73 │                                 │ LH1 LH0 -- │ --  RH0 RH1│
                 ╰───────╮ 74 │ 75 ╭───────╯                                 ╰───────╮ -- │ -- ╭───────╯
                         ╰────┴────╯                                                 ╰────┴────╯ */

#define QUICK_TAP_MS 175

&sk {  // sticky-key config
    release-after-ms = <900>;  // release after 0.6s
    quick-release;             // no double capitalization when rolling keys
};

&sl {  // sticky-layer config
    ignore-modifiers;          // allow chording sticky mods & layers
};

&lt {  // layer-tap config
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
};


#define KEYS_L LN5 LN4 LN3 LN2 LN1 LN0 LT5 LT4 LT3 LT2 LT1 LT0 LM5 LM4 LM3 LM2 LM1 LM0 LB5 LB4 LB3 LB2 LB1 LB0
#define KEYS_R RN5 RN4 RN3 RN2 RN1 RN0 RT5 RT4 RT3 RT2 RT1 RT0 RM5 RM4 RM3 RM2 RM1 RM0 RB5 RB4 RB3 RB2 RB1 RB0
#define THUMBS LH1 LH0 RH0 RH1


#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
  ZMK_BEHAVIOR(NAME, hold_tap, \
      flavor = "balanced"; \
      tapping-term-ms = <280>; \
      quick-tap-ms = <QUICK_TAP_MS>; \
      global-quick-tap-ms = <150>; \
      bindings = <HOLD>, <TAP>; \
      hold-trigger-key-positions = <TRIGGER_POS>; \
      hold-trigger-on-release; \
      )

#define MAKE_HRM_SHIFT(NAME, HOLD, TAP, TRIGGER_POS) \
  ZMK_BEHAVIOR(NAME, hold_tap, \
      flavor = "balanced"; \
      tapping-term-ms = <280>; \
      quick-tap-ms = <QUICK_TAP_MS>; \
      global-quick-tap-ms = <125>; \
      bindings = <HOLD>, <TAP>; \
      hold-trigger-key-positions = <TRIGGER_POS>; \
      hold-trigger-on-release; \
      )


MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM_SHIFT(hmls, &kp, &kp, KEYS_R THUMBS) // left-hand homerow mod for shift
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)  // right-hand
MAKE_HRM_SHIFT(hmrs, &kp, &kp, KEYS_L THUMBS) // right-hand homerow mod for shift


#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

&mt { MT_CORE };


// tap: sticky-shift | shift + tap/ double-tap: caps-word | hold: shift
ZMK_BEHAVIOR(smart_shft, mod_morph,
    bindings = <&sk LSHFT>, <&caps_word>;
    mods = <(MOD_LSFT)>;
)
&caps_word {  // mods deactivate caps-word, requires PR #1451
    /delete-property/ ignore-modifiers;
};

// tap: num-word | double-tap: sticky num-layer | hold: num-layer
#define SMART_NUM &smart_num NUM 0
ZMK_BEHAVIOR(smart_num, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&num_dance>;
)
ZMK_BEHAVIOR(num_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&num_word>, <&sl NUM>;  // reverse this for sticky-num on single tap
)
&num_word {  // num-word, requires PR #1451
    layers = <NUM>;
    continue-list = <BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL>;
};



// mods for combos


#define MAKE_SFTMORPH(NAME, TAP, MODTAP) \
ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <TAP>, <MODTAP>; \
    mods = <(MOD_LSFT|MOD_RSFT)>; \
)
MAKE_SFTMORPH(bs_del, &kp BSPC, &kp DEL) 


#define CANCEL      &kp K_CANCEL

