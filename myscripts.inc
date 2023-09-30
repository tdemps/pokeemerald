


@ @@@@@ bow tie stuff

Tanner_CheckBowTie:
    @ setvaddress WeddingGiftScript_BowTie
    @ vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, BowTie_Obtained
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, BowTie_Obtained
    lock
	faceplayer
    @ Need me walking up here
    applymovement VAR_LAST_TALKED, Tanner_CheckBowTie_SurprisedMovement
    message Tanner_CheckBowTieForgot_Text

Tanner_CheckBowTie_Obtained::
    end

Tanner_CheckBowTie_SurprisedMovement:
	jump_in_place_up_down
	delay_16
	emote_exclamation_mark
	delay_16
	step_end

Tanner_CheckBowTieLove_Text:
    .string "I know you are probably a ball of nerves,\n"
    .string "but you should know that you have so many\p"
    .string "friends and family members here beyond excited\l"
    .string "for you. We are all so happy for you and Johnna\l"
    .string "(and Ruby) to start this next chapter of your lives."
    .string "You're the best big brother ever.$"

Ceremony_Text_Ruby:
    .string "Woof woof!"

Ceremony_Text_Haley:
    .string "{COLOR RED}Haley{COLOR DARK_GRAY}:Told you I'd be able to\n"
    .string "Make it!$"

Ceremony_Text_Mom:
    .string "{COLOR RED}Mom{COLOR DARK_GRAY}:Love you Ty! If only Daisy\n"
    .string "could of gotten her passport\l"
    .string "in time..$"

Ceremony_Text_Dad:
    .string "{COLOR RED}Dad{COLOR DARK_GRAY}:Excited for you T! Also bought\n"
    .string "a grill to the hotet, not feeling\p"
    .string "this French food. Hope that's okay$"

Ceremony_Text_Conner:
    .string "{COLOR RED}Dad{COLOR DARK_GRAY}:Excited for you T! Also bought\n"
    .string "a grill to the hotet, not feeling\p"
    .string "this French food. Hope that's okay$"

Ceremony_Text_Mike:
    .string "{COLOR RED}Mike{COLOR DARK_GRAY}:Excited for you T! Also bought\n"
    .string "a grill to the hotet, not feeling\p"
    .string "this French food. Hope that's okay$"