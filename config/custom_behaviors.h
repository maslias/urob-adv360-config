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

#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

&mt { MT_CORE };

#define MO_NAVI &mo NAVI

#define KEYS_L LN5 LN4 LN3 LN2 LN1 LN0 LT5 LT4 LT3 LT2 LT1 LT0 LM5 LM4 LM3 LM2 LM1 LM0 LB5 LB4 LB3 LB2 LB1 LB0
#define KEYS_R RN5 RN4 RN3 RN2 RN1 RN0 RT5 RT4 RT3 RT2 RT1 RT0 RM5 RM4 RM3 RM2 RM1 RM0 RB5 RB4 RB3 RB2 RB1 RB0
#define THUMBS LH1 LH0 RH0 RH1


#define CANCEL &kp K_CANCEL

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

#define MAKE_MORPH_SHIFT(NAME, TAP, MODTAP) \
ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <TAP>, <MODTAP>; \
    mods = <(MOD_LSFT|MOD_RSFT)>; \
)
#define MAKE_MORPH_CTL(NAME, TAP, MODTAP) \
ZMK_BEHAVIOR(NAME, mod_morph, \
    bindings = <TAP>, <MODTAP>; \
    mods = <(MOD_LCTL|MOD_RCTL)>; \
)


    
#define MAKE_HTAP(NAME, HOLD, TAP) \
ZMK_BEHAVIOR(NAME, hold_tap, \
    flavor = "balanced"; \
    tapping-term-ms = <200>; \
    quick-tap-ms = <QUICK_TAP_MS>; \
global-quick-tap-ms = <150>; \
    bindings = <HOLD>, <TAP>; \
    hold-trigger-on-release; \
)

#define MAKE_HTAP_L(NAME, HOLD, TAP) \
ZMK_BEHAVIOR(NAME, hold_tap, \
    flavor = "balanced"; \
    tapping-term-ms = <280>; \
    quick-tap-ms = <QUICK_TAP_MS>; \
    bindings = <HOLD>, <TAP>; \
    global-quick-tap-ms = <150>; \
    hold-trigger-on-release; \
)




MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM_SHIFT(hmls, &kp, &kp, KEYS_R THUMBS) // left-hand homerow mod for shift
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)  // right-hand
MAKE_HRM_SHIFT(hmrs, &kp, &kp, KEYS_L THUMBS) // right-hand homerow mod for shift

MAKE_HRM(hml_layer, &mo, &kp, KEYS_R THUMBS)
MAKE_HRM(hmr_layer, &mo, &kp, KEYS_L THUMBS)


// MAKE_HRM(hmr_num, &kp, &num_word, KEYS_L THUMBS)  // right-hand


#define SMART_SHFT2 &smart_shft_urob
// urbo smart shift
MAKE_MORPH_SHIFT(smart_shft_urob, &sk LSHFT, &caps_word) 
    &caps_word {  // mods deactivate caps-word, requires PR #1451
        // /delete-property/ ignore-modifiers;
        continue-list = <MINUS UNDER UNDERSCORE>;
    };


MAKE_MORPH_CTL(smart_ctl_urob, &sk LCTRL, &num_word) 
&num_word {  // num-word, requires PR #1451
    layers = <NUM>;
    continue-list = <BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL>;
};



// urob smart num
#define SMART_NUM &smart_num NUM 0
MAKE_HTAP_L(smart_num, &mo, &num_dance)
ZMK_BEHAVIOR(num_dance, tap_dance,
             tapping-term-ms = <270>;
             bindings = <&num_word>, <&sl NUM>;  // reverse this for sticky-num on single tap
             )
&num_word {  // num-word, requires PR #1451
    layers = <NUM>;
    continue-list = <BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL>;
};

#define SMART_SHFT &smart_shft LSHFT 0
MAKE_HTAP_L(smart_shft, &kp, &shft_dance)
ZMK_BEHAVIOR(shft_dance, tap_dance,
             tapping-term-ms = <270>;
             bindings = <&sk LSHFT>, <&caps_word>;  // reverse this for sticky-num on single tap
             )
&caps_word {  // mods deactivate caps-word, requires PR #1451
        /delete-property/ ignore-modifiers;
        continue-list = <MINUS UNDER UNDERSCORE>;
    };


#define SMART_CTL &smart_ctl LCTRL 0
MAKE_HTAP_L(smart_ctl, &kp, &ctl_dance)
ZMK_BEHAVIOR(ctl_dance, tap_dance,
             tapping-term-ms = <270>;
             bindings = <&sk LCTRL>, <&num_word>;  // reverse this for sticky-num on single tap
             )
&num_word {  // num-word, requires PR #1451
    layers = <NUM>;
    continue-list = <BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL>;
};

#define SMART_CTL2 &smart_ctl LCTRL LCTRL
MAKE_HTAP_L(smart_ctl, &kp, &sk)


ZMK_BEHAVIOR(copy_paste_dance, tap_dance,
             tapping-term-ms = <270>;
             bindings = <&kp LC(INS)>, <&kp LC(V)>;  // reverse this for sticky-num on single tap
             )



// combo stuff
MAKE_MORPH_SHIFT(bs_del, &kp BSPC, &kp DEL) 
MAKE_MORPH_SHIFT(comma_semi, &kp COMMA, &kp SEMI)
MAKE_MORPH_SHIFT(dot_colon, &kp DOT, &kp COLON)
MAKE_MORPH_SHIFT(qmark_excl, &kp QMARK, &kp EXCL)


// thumbs stuff
MAKE_MORPH_SHIFT(home_end, &kp HOME, &kp END)
MAKE_MORPH_SHIFT(pg_up_dn, &kp PG_UP, &kp PG_DN)

                 
// german stuff
MAKE_HTAP(a_de_ae,&de_ae, &kp)
MAKE_HTAP(u_de_ue,&de_ue, &kp)
MAKE_HTAP(o_de_oe,&de_oe, &kp)
MAKE_HTAP(s_de_esz,&de_eszett, &kp)
MAKE_HTAP(e_de_eur,&euro_sign, &kp)


ZMK_UNICODE_SINGLE(euro_sign, N2, N0, A, C)  // €





#define SMART_MACRO &smart_macro 0 0
ZMK_BEHAVIOR(smart_macro, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&windows_navi_hold>, <&macro_dance>;
)
ZMK_BEHAVIOR(macro_dance, tap_dance,
    tapping-term-ms = <300>;
    bindings = <&windows_tab_alt_shft>, <&windows_tab>;  
)

ZMK_BEHAVIOR(windows_tab, macro,
    bindings
                = <&macro_press &kp LGUI>
                , <&macro_tap &kp TAB>
                , <&macro_release &kp LGUI>
		, <&macro_tap &navi_word>
                ;
)

ZMK_BEHAVIOR(windows_tab_alt_shft, macro,
    bindings
                = <&macro_press &kp RSHFT>
		, <&macro_press &kp RCTRL>
		, <&macro_press &kp LALT>
		, <&macro_tap &kp TAB>
		, <&macro_release &kp LALT>
		, <&macro_release &kp RCTRL>
		, <&macro_release &kp RSHFT>
                , <&macro_tap &navi_word>
                ;
)

ZMK_BEHAVIOR(windows_navi_hold, macro,
    bindings
                = <&macro_press &kp LGUI>
                , <&macro_press &kp LCTRL>
		, <&macro_press &mo NAVI>
                , <&macro_pause_for_release>
		, <&macro_release &mo NAVI>
                , <&macro_release &kp LCTRL>
		, <&macro_release &kp LGUI>
                ;
)
