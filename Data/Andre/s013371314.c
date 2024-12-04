/************************************************************************************
 * MODULE    : 双方向連結リスト作成処理
 * FILENAME  : ALDS1_3_C.c
 * REMARKS   :
 * HISTORY   : 
 * ID -- DATE ------- NAME -------- NOTE -------------------------------------------
 * [00]  2018/08/21   S.Hayashi     初期作成
************************************************************************************/


/*------------------------------------------------------------------------------*/
/*  Include Files                                                               */
/*------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*------------------------------------------------------------------------------*/
/*  Definition & Macro                                                          */
/*------------------------------------------------------------------------------*/
#define CMD_LENGTH_MAX		8				/* コマンド数の文字列の最大長(NULL文字含む) */
#define OPE_COUNT_MIN		1				/* 命令回数の下限 */
#define OPE_COUNT_MAX		2000000			/* 命令回数の上限 */
#define OPE_LENGTH_MAX		24				/* ★命令の文字列の長さ上限(NULL文字含む) */
//#define OPE_LENGTH_MAX		23				/* ★命令の文字列の長さ上限(NULL文字含む) */
#define KEY_VALUE_MIN		0				/* キーの値の下限 */
#define KEY_VALUE_MAX		10000000000		/* キーの値の上限(AIZUのテストケースの都合で、ゼロを1つ足している) */
#define KEY_LENGTH_MAX		12				/* ★キーの長さの上限(NULL文字含む) */
//#define KEY_LENGTH_MAX		11				/* ★キーの長さの上限(NULL文字含む) */
#define LIST_SIZE_MAX		1000000			/* リストサイズの上限 */
#define DELETE_OPE_MAX		20				/* deleteコマンドの回数の上限 */
#define OK					0				/* 正常終了 */
#define NG					1				/* 異常終了 */


/*------------------------------------------------------------------------------*/
/*  Typedef                                                                     */
/*------------------------------------------------------------------------------*/
typedef unsigned int	U32;
typedef signed	 int	S32;
typedef signed	 char	S08;
typedef unsigned char	U08;
typedef char			C08;

struct st_key_info{							/* キー情報を保持する構造体 */
	U32 u32_value;							/* キーの値 */
	struct st_key_info *stp_prev_key;		/* 前の構造体のポインタ */
	struct st_key_info *stp_next_key;		/* 次の構造体のポインタ */
};
typedef struct st_key_info ST_KEY_INFO;


/*------------------------------------------------------------------------------*/
/*  Prototype declaration                                                       */
/*------------------------------------------------------------------------------*/
static U32  InsertNum_U32(U32 u32_key_value);
static void DeleteNum_Void(U32 u32_key_value);
static void DispKeyValue_Void(void);
static void FreeMalloc_Void(void);

/*------------------------------------------------------------------------------*/
/*  Variables                                                                   */
/*------------------------------------------------------------------------------*/
U32 U32_List_Size = 0;						/* リストサイズ */
ST_KEY_INFO *Stp_List_Top  = NULL;			/* 構造体リストの先頭のポインタ */
ST_KEY_INFO *Stp_List_Last = NULL;			/* 構造体リストの末端のポインタ */


/***********************************************************************************
 ++module <main>
 ++outline
	メイン関数
 ++arguments
	<>	<>	[戻り値]
 ++supp
	<戻り値>
		OK：正常終了
		NG：異常終了
	<引数>
		なし
	<補足説明>
		コマンドの優先度は、deleteを一番最後に持っていく
		(deleteFirst, deleteLastと区別するため)
 ++end_module
************************************************************************************/
int main(void)
{
																			/* コマンド入力回数(C08型) */
	C08 c08a_cmd_str[CMD_LENGTH_MAX] = {'\0'};								/* 変数定義 */
	U32 u32_cmd_num = 0;													/* コマンド入力回数(U32型) */
	C08 c08a_ope_str[OPE_LENGTH_MAX] = {'\0'};								/* コマンドの文字列 */
	C08 c08a_key_str[KEY_LENGTH_MAX] = {'\0'};								/* キーの文字列(この変数に格納した文字列を数値に変換する) */
	U32 u32_key_value = 0;													/* キーの値 */
	U08 u08_delete_ope_count = (U08)0;										/* deleteコマンドの回数 */
	U32 u32_i = 0;															/* ループ変数 */
	U32 u32_return_val = OK;												/* 戻り値 */
	
	fgets(c08a_cmd_str, CMD_LENGTH_MAX, stdin);								/* コマンド入力回数の取得(文字列) */
	u32_cmd_num = atoi(c08a_cmd_str);										/* コマンド入力回数を文字列から数値に変換 */
	
	if( (u32_cmd_num < OPE_COUNT_MIN) || (OPE_COUNT_MAX < u32_cmd_num) )	/* 入力値が範囲外の場合 */
	{
		u32_return_val = NG;												/* 戻り値にNGを設定 */
	}
	else
	{
		for(u32_i = 0; u32_i < u32_cmd_num; u32_i++)								/* コマンド数だけループ */
		{
			fgets(c08a_ope_str, OPE_LENGTH_MAX, stdin);								/* コマンドの入力 */
			
			/* コマンドによる分岐処理 */
			if( 0 == strncmp(c08a_ope_str, "insert", 6) )							/* キーの挿入 */
			{
				if(LIST_SIZE_MAX == U32_List_Size)									/* リストサイズの上限に達している場合 */
				{
					FreeMalloc_Void();												/* メモリ解放 */
					u32_return_val = NG;											/* 戻り値をNGに設定 */
					break;
				}
				else
				{
					/* 何もしない */
				}
				
				strncpy(c08a_key_str, c08a_ope_str + 7, KEY_LENGTH_MAX - 1);		/* 数値の部分を抜き出し */
				c08a_key_str[KEY_LENGTH_MAX - 1] = '\0';							/* 末端にNULL文字を設定 */
				u32_key_value = atoi(c08a_key_str);									/* 数値変換 */
				
				if( (u32_key_value < KEY_VALUE_MIN) || (KEY_VALUE_MAX < u32_key_value) )	/* 入力値が範囲外の場合 */
				{
					if(0 != U32_List_Size)											/* リストが空ではない場合 */
					{
						FreeMalloc_Void();											/* メモリ解放 */
					}
					else
					{
						/* 何もしない */
					}
					u32_return_val = NG;											/* 戻り値にNGを設定 */
					break;
				}
				else
				{
					u32_return_val = InsertNum_U32(u32_key_value);					/* キーの挿入 */
					
					if(NG == u32_return_val)										/* 処理結果がNGの場合 */
					{
						if(0 != U32_List_Size)										/* リストが空ではない場合 */
						{
							FreeMalloc_Void();										/* メモリ解放 */
						}
						else
						{
							/* 何もしない */
						}
						break;
					}
					else
					{
						U32_List_Size++;											/* リストサイズをプラス1 */
					}
				}
			}
			else if( 0 == strncmp(c08a_ope_str, "deleteFirst", 11) )				/* 先頭のキーの削除 */
			{
				if(0 == U32_List_Size)												/* リストが空の場合 */
				{
					u32_return_val = NG;											/* 戻り値にNGを設定 */
					break;
				}
//				else if(NULL != Stp_List_Top->stp_next_key)							/* 後ろにキーがある場合 */
				else if(1 < U32_List_Size)											/* 後ろにキーがある場合 */
				{
					Stp_List_Top = Stp_List_Top->stp_next_key;						/* 解放するキーから移動 */
					free(Stp_List_Top->stp_prev_key);								/* キーの解放 */
				}
				else
				{
					free(Stp_List_Top);												/* キーの解放 */
					Stp_List_Top  = NULL;											/* 先頭のアドレスをNULLにする */
					Stp_List_Last = NULL;											/* 末端のアドレスをNULLにする */
				}
				U32_List_Size--;													/* リストサイズをマイナス1 */
			}
			else if( 0 == strncmp(c08a_ope_str, "deleteLast", 10) )					/* 末端のキーの削除 */
			{
				if(0 == U32_List_Size)												/* リストが空の場合 */
				{
					u32_return_val = NG;											/* 戻り値にNGを設定 */
					break;
				}
//				else if(NULL != Stp_List_Last->stp_prev_key)						/* 前にキーがある場合 */
				else if(1 < U32_List_Size)											/* 前にキーがある場合 */
				{
					Stp_List_Last = Stp_List_Last->stp_prev_key;					/* 解放するキーから移動 */
					free(Stp_List_Last->stp_next_key);								/* キーの解放 */
				}
				else
				{
					free(Stp_List_Last);											/* キーの解放 */
					Stp_List_Top  = NULL;											/* 先頭のアドレスをNULLにする */
					Stp_List_Last = NULL;											/* 末端のアドレスをNULLにする */
				}
				
				U32_List_Size--;													/* リストサイズをマイナス1 */
			}
			else if( 0 == strncmp(c08a_ope_str, "delete", 6) )						/* 指定したキーの削除 */
			{
				if(0 == U32_List_Size)												/* リストが空の場合 */
				{
					u32_return_val = NG;											/* 戻り値にNGを設定 */
					break;
				}
				else if(DELETE_OPE_MAX == u08_delete_ope_count)						/* deleteコマンドの回数の上限に達している場合 */
				{
					if(NULL != Stp_List_Top)										/* リストが空ではない場合 */
					{
						FreeMalloc_Void();											/* メモリ解放 */
					}
					else
					{
						/* 何もしない */
					}
					u32_return_val = NG;											/* 戻り値にNGを設定 */
					break;
				}
				else
				{
					strncpy(c08a_key_str, c08a_ope_str + 7, KEY_LENGTH_MAX - 1);	/* 数値の部分を抜き出し */
					c08a_key_str[KEY_LENGTH_MAX - 1] = '\0';						/* 末端にNULL文字を設定 */
					u32_key_value = atoi(c08a_key_str);								/* 数値変換 */
					
					if( (u32_key_value < KEY_VALUE_MIN) || (KEY_VALUE_MAX < u32_key_value) )	/* 入力値が範囲外の場合 */
					{
						if(NULL != Stp_List_Top)									/* リストが空ではない場合 */
						{
							FreeMalloc_Void();										/* メモリ解放 */
						}
						else
						{
							/* 何もしない */
						}
						u32_return_val = NG;										/* 戻り値にNGを設定 */
						break;
					}
					DeleteNum_Void(u32_key_value);									/* 数値の削除 */
					u08_delete_ope_count++;											/* deleteコマンドの回数をプラス1 */
				}
			}
			else
			{
				/* 何もしない */
			}
			memset(&c08a_ope_str[0], '\0', sizeof(c08a_ope_str));					/* コマンドの文字列の初期化 */
			memset(&c08a_key_str[0], '\0', sizeof(c08a_key_str));					/* キーの文字列の初期化 */
		}
		
		if(OK == u32_return_val)			/* 処理結果がOKの場合 */
		{
			DispKeyValue_Void();			/* リスト内の数値を表示 */
			FreeMalloc_Void();				/* メモリ解放 */
		}
		else
		{
			/* 何もしない */
		}
	}
	
	return u32_return_val;
}


/***********************************************************************************
 ++module <InsertNum_U32>
 ++outline
	リストに数値を格納する関数
 ++arguments
	<>	<>				[処理結果]
	<>	<u32_key_value>	[挿入する数値]
 ++supp
	<戻り値>
		OK：正常終了
		NG：異常終了
	<引数>
		u32_key_value：挿入する数値
	<補足説明>
		なし
 ++end_module
************************************************************************************/
static U32 InsertNum_U32(U32 u32_key_value)
{
										/* 一時的に構造体のアドレスを保持する変数 */
	ST_KEY_INFO *stp_tmp = NULL;		/* 変数定義 */
	U32 u32_return_val   = OK;			/* 戻り値用変数 */
	
	stp_tmp = (ST_KEY_INFO *)malloc(sizeof(ST_KEY_INFO));							/* 数値を挿入するための領域確保 */
	
	if(NULL == stp_tmp)
	{
		u32_return_val = NG;														/* 戻り値にNGを設定 */
	}
	else
	{
		stp_tmp->u32_value = u32_key_value;											/* 数値の挿入 */
		
		if(0 == U32_List_Size)														/* リストが空の場合 */
		{
			Stp_List_Top  = stp_tmp;												/* 先頭のアドレスの更新 */
			Stp_List_Last = stp_tmp;												/* 末端のアドレスの更新 */
		}
		else
		{
			Stp_List_Top->stp_prev_key = stp_tmp;									/* 新しい先頭のアドレスを保持 */
			stp_tmp->stp_next_key      = Stp_List_Top;								/* 古い先頭のアドレスを保持 */
			Stp_List_Top = stp_tmp;													/* 先頭のアドレスを更新 */
		}
	}
	
	return u32_return_val;
}


/***********************************************************************************
 ++module <DeleteNum_Void>
 ++outline
	指定した数値をリストから削除する関数
 ++arguments
	<>	<>					[]
	<>	<u32_key_value>		[削除する数値]
 ++supp
	<戻り値>
		なし
	<引数>
		u32_key_value ：削除する数値
	<補足説明>
		リスト内に指定した数値がない場合、何もしない
 ++end_module
************************************************************************************/
static void DeleteNum_Void(U32 u32_key_value)
{
																/* 一時的に構造体のアドレスを保持する変数 */
	ST_KEY_INFO *stp_tmp  = NULL;								/* 変数定義 */
	ST_KEY_INFO *stp_tmp2 = NULL;								/* 一時的に構造体のアドレスを保持する変数2 */
	U32 u32_i = 0;												/* ループ変数 */
	
	stp_tmp = Stp_List_Top;										/* リストの先頭アドレスを取得 */
	
	for(u32_i = 0; u32_i < U32_List_Size; u32_i++)				/* リストの末端までループ */
	{
		if(stp_tmp->u32_value == u32_key_value)					/* 指定した数値が見つかった場合 */
		{
			if(1 == U32_List_Size)								/* キーが1つの場合 */
			{
				free(stp_tmp);									/* メモリ解放 */
				Stp_List_Top  = NULL;							/* 先頭のアドレスをNULLにする */
				Stp_List_Last = NULL;							/* 末端のアドレスをNULLにする */
			}
			else if(u32_i < U32_List_Size - 1)					/* キーが2つ以上で、末端以外で一致した場合 */
			{
//				if(stp_tmp == Stp_List_Top)						/* リストの先頭で一致した場合 */
				if(0 == u32_i)									/* リストの先頭で一致した場合 */
				{
					Stp_List_Top = Stp_List_Top->stp_next_key;	/* リストの先頭を更新 */
					free(Stp_List_Top->stp_prev_key);			/* メモリ解放 */
				}
				else											/* リストの先頭以外で一致した場合 */
				{
					stp_tmp2 = stp_tmp->stp_prev_key;			/* 前のキーのアドレスを取得 */
					stp_tmp = stp_tmp->stp_next_key;			/* 次のキーに移動 */
					stp_tmp2->stp_next_key = stp_tmp;			/* 次のキーのアドレスを更新 */
					free(stp_tmp->stp_prev_key);				/* メモリ解放 */
					stp_tmp->stp_prev_key  = stp_tmp2;			/* 前のキーのアドレスを更新 */
				}
			}
			else												/* 末端で一致した場合 */
			{
				Stp_List_Last = Stp_List_Last->stp_prev_key;	/* リストの末端を更新 */
				free(Stp_List_Last->stp_next_key);				/* メモリ解放 */
			}
			
			U32_List_Size--;									/* リストサイズをマイナス1 */
			break;
		}
		else
		{
			stp_tmp = stp_tmp->stp_next_key;				/* 次のキーに移動 */
		}
	}
}


/***********************************************************************************
 ++module <DispKeyValue_Void>
 ++outline
	リストのキーを表示する関数
 ++arguments
	<>	<>	[]
 ++supp
	<戻り値>
		なし
	<引数>
		なし
	<補足説明>
		なし
 ++end_module
************************************************************************************/
static void DispKeyValue_Void(void)
{
															/* 一時的に構造体のアドレスを保持する変数 */
	ST_KEY_INFO *stp_tmp = NULL;							/* 変数定義 */
	U32 u32_i = 0;											/* ループ変数 */
	
	stp_tmp = Stp_List_Top;									/* リストの先頭アドレスを取得 */
	
	for(u32_i = 0; u32_i < U32_List_Size; u32_i++)			/* リストの末端までループ */
	{
		printf("%d", stp_tmp->u32_value);					/* キーの表示 */
		
		if(u32_i < U32_List_Size - 1)						/* リストの末端ではない場合 */
		{
			printf(" ");									/* 半角スペースを表示 */
			stp_tmp = stp_tmp->stp_next_key;				/* 次のキーへ移動 */
		}
		else
		{
			printf("\n");									/* 改行 */
		}
	}
}



/***********************************************************************************
 ++module <FreeMalloc_Void>
 ++outline
	動的に確保したメモリを解放する関数
 ++arguments
	<>	<>	[]
 ++supp
	<戻り値>
		なし
	<引数>
		なし
	<補足説明>
		なし
 ++end_module
************************************************************************************/
static void FreeMalloc_Void(void)
{
													/* 一時的に構造体のアドレスを保持する変数 */
	ST_KEY_INFO *stp_tmp = NULL;					/* 変数定義 */
	U32 u32_i = 1;
	
	stp_tmp = Stp_List_Top;							/* リストの先頭アドレスを取得 */
	
	while(u32_i <= U32_List_Size)					/* 全てのキーを解放するまでループ */
	{
		if(u32_i == U32_List_Size)					/* リストの末端に達した場合 */
		{
			free(stp_tmp);							/* 現在のアドレスのキーを解放 */
		}
		else
		{
			stp_tmp = stp_tmp->stp_next_key;		/* 解放対象から移動 */
			free(stp_tmp->stp_prev_key);			/* 1つ前のキーを解放 */
		}
		u32_i++;
	}
}
