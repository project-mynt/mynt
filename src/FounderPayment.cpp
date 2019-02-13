/*
 * Copyright (c) 2018 The Pigeon Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * FounderPayment.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#include "FounderPayment.h"
//#include "standard.h";
#include "util.h"
#include "chainparams.h"
#include <boost/foreach.hpp>
#include "base58.h"

CAmount FounderPayment::getFounderPaymentAmount(int blockHeight, CAmount blockReward) {
	 if (blockHeight <= rewardStructure.blockHeight){
		 return 0;
	 }

	 return blockReward * rewardStructure.rewardPercentage / 100;
}

void FounderPayment::FillFounderPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward, CTxOut& txoutFounderRet) {
    // make sure it's not filled yet
	txoutFounderRet = CTxOut();
	CAmount founderPayment = getFounderPaymentAmount(nBlockHeight, blockReward);
	if(founderPayment == 0) {
		return; // don't fill block with founder for 0 founder reward
	}
    CScript payee;
    // fill payee with the founder address
    payee = GetScriptForDestination(DecodeDestination(founderAddress));
    // GET FOUNDER PAYMENT VARIABLES SETUP

    // split reward between miner ...
    txNew.vout[0].nValue -= founderPayment;
    txoutFounderRet = CTxOut(founderPayment, payee);
    txNew.vout.push_back(txoutFounderRet);
    LogPrintf("FounderPayment::FillFounderPayment -- Founder payment %lld to %s\n", founderPayment, founderAddress.c_str());
}

bool FounderPayment::IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockReward) {
	CScript payee;
	// fill payee with the founder address
	payee = GetScriptForDestination(DecodeDestination(founderAddress));
	const CAmount founderReward = getFounderPaymentAmount(height, blockReward);
	if(founderReward == 0) {
		return true; // transaction is valid without founder transaction if founder reward is 0
	}
	BOOST_FOREACH(const CTxOut& out, txNew.vout) {
		if(out.scriptPubKey == payee && out.nValue >= founderReward) {
			return true;
		}
	}

	return false;
}