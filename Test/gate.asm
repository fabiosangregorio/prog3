asm gate

import StandardLibrary

//declare universes and functions
		
signature:

// domains 
	domain Tickets subsetof Natural
    enum domain Status = { WAITING_TICKET | WAITING_PAYMENT | WAITING_CAR_PASS }
    enum domain Bar = { OPENED | CLOSED }

// functions

	dynamic monitored ticketInserted : Tickets
	dynamic monitored moneyInserted : Natural

	dynamic controlled toPay : Natural
	dynamic controlled balance : Natural
	dynamic controlled gateStatus : Status

	dynamic out bar : Bar
	dynamic out message : Any

// static functions

	derived ticketPrice : Tickets -> Natural


// definitions

definitions:

	domain Tickets = {1n,2n,3n,4n}

	function ticketPrice($n in Tickets) =
		switch($n)
			case (1n) : 3n
			case (2n) : 8n
			case (3n) : 12n
			case (4n) : 17n
		endswitch

//Rules

	rule r_InsertTicket =
		if (gateStatus = WAITING_TICKET) then
			seq
				balance := 0n
				gateStatus := WAITING_PAYMENT
				toPay := ticketPrice(ticketInserted)
				message := toPay
			endseq
		endif

	rule r_InsertMoney =
		if (gateStatus = WAITING_PAYMENT) then
			seq
				balance := balance + moneyInserted
				message := balance
			endseq
		endif

	rule r_DoneInsertingMoney =
		if (gateStatus = WAITING_PAYMENT) then
			if (balance >= toPay) then
				par
					gateStatus := WAITING_CAR_PASS
					bar := OPENED
					message := "Thank you!"
				endpar
			else
				message := "Please insert more money"
			endif
		endif

	rule r_CarPassed =
		if (gateStatus = WAITING_CAR_PASS) then
			par
				toPay := 0n
				balance := 0n
				bar := CLOSED
				gateStatus := WAITING_TICKET
				message := "Insert ticket"
			endpar
		endif


//Main Rule

	main rule r_Main =
		seq
			r_InsertTicket[]
			r_InsertMoney[]
			r_DoneInsertingMoney[]
			r_CarPassed[]
		endseq
 
//define the initial state

default init initial_state:
	
	function toPay = 0n
	function bar = CLOSED
	function gateStatus = WAITING_TICKET
	function message = "Insert ticket"
		
