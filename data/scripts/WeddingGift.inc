WeddingGiftScript_BowTie::
	setvaddress WeddingGiftScript_BowTie
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, BowTie_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, BowTie_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	@ setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	@ vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

BowTie_Obtained:
	vmessage sText_BowTieThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Ah here it is! You're gonna\n"
	.string "need this to look sharp!$\p"

sText_AuroraTicketUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_BowTieThankYou:
	.string "We better hurry up and get\n"
    .string "to the ceremony {PLAYER}!$"

sText_AuroraTicketBagFull:
	.string "Oh, I'm sorry, {PLAYER}.\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"