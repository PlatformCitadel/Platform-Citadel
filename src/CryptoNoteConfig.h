// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2016 SDN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 240; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0xd7; // addresses start with "0xc"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 6;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 3;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(858986905600000000);

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 32000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
// COIN - number of smallest units in one coin
const uint64_t COIN                                          = UINT64_C(100000000);  // pow(10, 8)
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);     // pow(10, 5)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);     // pow(10, 5)
//const uint64_t GENESIS_BLOCK_REWARD							 = UINT64_C(0);
const uint64_t MAX_TX_MIXIN_SIZE                             = 50;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 240; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 60;  // blocks
const size_t   DIFFICULTY_CUT                                = 30;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT                            = 150 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 11000;
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 11000;
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 77000;
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 107;
const uint64_t DEPOSIT_MAX_TOTAL_RATE_V2                     = 12;
const uint32_t DEPOSIT_MAX_TOTAL_RATE_CHANGE_HEIGHT          = 196000;
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); //seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 170500;
const uint32_t UPGRADE_HEIGHT_V4                             = 270000;
const uint32_t UPGRADE_HEIGHT_V5                             = 314020;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
const uint32_t EVIL_MAY_CRY_FIX                              =  235000;
} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(80) * parameters::COIN);
const uint64_t MIN_BLOCK_REWARD                              = (UINT64_C(5) * parameters::COIN);
const uint64_t REWARD_HALVING_INTERVAL                       = (UINT64_C(66000));

const char     CRYPTONOTE_NAME[]                             = "citadel";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010601ff000180a0d9e61d029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121019e2d1a633f2a54ff1a415e0051d5a699461d9c95479f67c8568446581c2e3782";
const uint32_t GENESIS_NONCE                                 = 70;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 55008;
const int      RPC_DEFAULT_PORT                              = 65084;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

   

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "85ae8734f90bc1ee295ceb0ec05a49852d4dbbc9d1c27a619b5f4bdf26a0196e";

const std::initializer_list<const char*> SEED_NODES = {
   
  "75.119.144.113:55008",
  "207.180.243.135:55008",
  "161.97.172.74:55008",
  "89.116.29.218:55008",
  "158.220.107.239:55008",
  "89.116.26.154:55008",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
        { 25000, "90abfcde8d541ab178a5b9b75d1f51ca1a1f10f474fe0b6e3825c05d23934d58" },
        { 50000, "86fba51a8b658b97a28657b886c5b75e0bd1767ac611bf1e5a5641068f46af19" },
        { 75000, "8b92ae320bad3860c6ab0ed54595e97b9610aae4775a6214a8cccd96ff3f7e1b" },
        { 100000, "0454f789f0867bf65cfc8f27ab227a68c2d4cd579a2de6d2352a3abec4a236e5" },
        { 125000, "f85ae759112e7f7a9cf6ba66aff0d9474df742ef394930fc74068931d14abce5" },
        { 150000, "65a02a68d90169cf8df149a8537a2d48f3cd1af804b81b18c0d26155c47738e8" },
        { 175000, "96325043d89f635e716bb956f8b106d6fae123d0d6b48c23138bab77a5dfb1f4" },
        { 200000, "d1808d85b3a7f1177c362592ee6fab56e0fdab5f5c6e439fa227e1ee8e2a369e" },
        { 225000, "274898f09249c31bd2a6b1c6a9140451578b9bf41d828d8073b1ec651558eca1" },
        { 250000, "8cd77a3f5ee17a4ae85ec8f4a4c705d1d5820cc1d971947c089a3b4a8eeff673" },
        { 275000, "0913e842554f45d7109d0361068f520666f064f482d2de163bbb19b359e55d5f" },
        { 300000, "ef94429b5545a9fde3dc195d013bd4dc7a0f5c09fea4f2652af3c1d763ad6424" },
        { 325000, "bda3bbfcb19223a84ccb79222bd9b646be228305e63f444ea55dd0296e30f895" },
        { 350000, "b9767292262f2d47cbab668682ae6414c89323b6ef8c9c1bce46d642106b081f" },
        { 375000, "97e956b5ca856e9a8f40d3bb9f08d1fcf09d83b1c4b6c260e29dea9176355223" },
        { 400000, "c749fe111aa8ecb51689506edc23a6edfad5cd07ba41afaa145f46d6464c53c3" },
        { 425000, "416151ef5c5ce1f7a927acfe3c0166315b805f958796d20fe4890de11f62887b" },
        { 450000, "c6dbe86a770857241f65d39c33986e828bf7eecf625bcae0a2418fdc9d27f842" },
        { 475000, "f4b27a05858235136d6220d6de907fb95087af2c7044270e9e1db1eb23d6a8a7" },
        { 500000, "5d6c9a7e8db555c822f7282b92e2a45edebe2e7af60c0ec7242d3d87477d97a9" },
        { 525000, "0ed41fefb44652732652776defa80a8ca0ae820c115ec4d9a2d05c43bcc29e96" },
        { 550000, "2a61638444d7bcb0eac654c7d29f743824e499489cd8a85b6704f0a6591c6ef6" },
        { 575000, "edb33778ba76454ab9ebdb9b204646076ed02ad0d31ece61e001893d429a8f6e" },
        { 600000, "6b90bd21a95cdb0a5951b5ece9f816834316456088d93b928909ae7f513c7a03" },
        { 625000, "3d4c0023d20c2f63a2cfe23b9ac2fcb05556fdc1e1f4acdec6f8313587d2cb86" },
        { 650000, "1fd1a44b381dfbb41cac61dfccdd264ad85d0ce271c98121a2083b2576e9577d" },
        { 675000, "9dca3e9166937a46887a0930eee2cb7d8c64be8d048a75a35be24b7a9f9e299e" },
        { 700000, "b5cda1218190415a646d8c9cacf81e257c71a5e24b56b4fa07314ede4b0aca5b" },
        { 725000, "ac4f39885a25e1f2ba1d771c98401807b0d055131b2ff7680599d7002f55f198" },
        { 750000, "535fdcbffcdd3b782f4ed2028ccdc06c031d4308ba49587630852f20278f6fed" },
        { 775000, "6c62c2e50a8a00adfc73612fade47deecf293defd4368182b0ed9be9c331016a" },
        { 800000, "434290751307532c52aff3eea3e92606c06b3310a5614b5a50cc77a763c2b24e" },
        { 825000, "41b49560e51d39be5f4d526bafb19381b392f61a4389482f699e0d4befe0c0ad" },
        { 850000, "c1c12b1f36233f7303a7cc87a633464d2e3231223bf10e85203d94e5002e3975" },
        { 875000, "ca4525a58a4864ac0a6037f5fc49c918f199661e0be3fce61f72853d0dc15d04" },
        { 900000, "77311008eed95d22f409955752fa4e0d3e2a4570e4ab9350a73a37e550c3c132" },
        { 925000, "ea44c506005848ed4ac79b90c02f2028f78d35b85bc2ec04b2d5d61e64893ce4" },
        { 950000, "90fc09e51f64d275155fad2ad0731b693941d83938c25cca4b528441c311f333" },
        { 975000, "2dc28014677ca852d295b3debacc33c545922bcc8ff19fdacccf1cef231c0499" },
        { 1000000, "22c2ddc1799fec59506f94bbf4bd5039379bde244ab9c257a8ab9fe0085139e8" },
        { 1025000, "a39edccd39997156adb5a0c40e3e1284e40d3e1c810a22cfb703646d16e92bb4" },
};


} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
