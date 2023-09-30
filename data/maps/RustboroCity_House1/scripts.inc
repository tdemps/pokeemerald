RustboroCity_House1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_House1_OnFrame
	.byte 0

RustboroCity_House1_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 9, Tanner_WeddingGiftScript_BowTie
	.2byte 0

Tanner_WeddingGiftScript_BowTie::
	lock
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, sText_BowTieThankYou
	applymovement 1, Tanner_GrabTie
	waitmovement 0
	msgbox sText_BowTieForYou, MSGBOX_DEFAULT
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, WeddingGift_NoBagSpace
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_AURORA_TICKET
	waitfanfare
	setvar VAR_UNUSED_0x40F7, 1
	@ We've gotten the bowtie
	clearflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 10
	setflag FLAG_HAS_MATCH_CALL
	waitmessage
	releaseall
	end

House_BowTieObtainedAlreadyText::
	.string "Ah here it is! You're gonna\n"
	.string "need this to look sharp!$\p"

House_BowTieObtainedAlready::
	msgbox sText_BowTieThankYou, MSGBOX_NPC
	end

Tanner_GrabTie:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	face_player
	step_end

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Huh? My POKéMON is cute?\n"
	.string "Sure, I knew that.\p"
	.string "But if you really want, I'm willing\n"
	.string "to trade it to you.\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Please be good to my POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.\n"
	.string "But my POKéMON is cute, you know…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Any POKéMON can be cute if you raise\n"
	.string "it with care and kindness.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "In all sorts of places, there are all\n"
	.string "sorts of POKéMON and people.\p"
	.string "I find that fascinating, so I go to all\n"
	.string "sorts of places.$"
