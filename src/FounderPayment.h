/*
 * Copyright (c) 2018 The Pigeon Core developers
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * FounderPayment.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#ifndef SRC_FOUNDERPAYMENT_H_
#define SRC_FOUNDERPAYMENT_H_
#include <string>
#include "amount.h"
#include "primitives/transaction.h"
#include "script/standard.h"
using namespace std;

static const string DEFAULT_FOUNDER_ADDRESS = "MVT2AJDK7CYTtWo5fX9u48eQT5ynWPyFFd";
struct FounderRewardStrcuture {
	int blockHeight;
	int rewardPercentage;
};

class FounderPayment {
public:
	FounderPayment(FounderRewardStrcuture rewardStructure = {240000, 5}, const string &address = DEFAULT_FOUNDER_ADDRESS) {
		this->founderAddress = address;
		this->rewardStructure = rewardStructure;
	}
	~FounderPayment(){};
	CAmount getFounderPaymentAmount(int blockHeight, CAmount blockReward);
	void FillFounderPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward, CTxOut& txoutFounderRet);
	bool IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockReward);
	int getStartBlock(){return rewardStructure.blockHeight;}

private:
	string founderAddress;
	FounderRewardStrcuture rewardStructure;
};



#endif /* SRC_FOUNDERPAYMENT_H_ */
