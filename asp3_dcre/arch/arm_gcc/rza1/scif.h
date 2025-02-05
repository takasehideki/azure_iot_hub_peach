/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2001-2011 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2007-2016 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *  $Id$
 */

/*
 *		FIFO内蔵シリアルコミュニケーションインタフェースに関する定義
 */

#ifndef TOPPERS_SCIF_H
#define TOPPERS_SCIF_H

/*
 *  SCIFレジスタの番地の定義
 */
#define SCIF_SCSMR(base)		((uint16_t *)(base + 0x00U))
#define SCIF_SCBRR(base)		((uint8_t *)(base + 0x04U))
#define SCIF_SCSCR(base)		((uint16_t *)(base + 0x08U))
#define SCIF_SCFTDR(base)		((uint8_t *)(base + 0x0cU))
#define SCIF_SCFSR(base)		((uint16_t *)(base + 0x10U))
#define SCIF_SCFRDR(base)		((uint8_t *)(base + 0x14U))
#define SCIF_SCFCR(base)		((uint16_t *)(base + 0x18U))
#define SCIF_SCFDR(base)		((uint16_t *)(base + 0x1cU))
#define SCIF_SCSPTR(base)		((uint16_t *)(base + 0x20U))
#define SCIF_SCLSR(base)		((uint16_t *)(base + 0x24U))
#define SCIF_SCEMR(base)		((uint16_t *)(base + 0x28U))

/*
 *  シリアルモードレジスタ（SCIF_SCSMR）の設定値
 */
#define SCIF_SCSMR_SYNC		0x0080U		/* クロック同期式モード */
#define SCIF_SCSMR_7BIT		0x0040U		/* 7ビットデータ */
#define SCIF_SCSMR_PARITY	0x0020U		/* パリティビットの付加 */
#define SCIF_SCSMR_ODD		0x0010U		/* 奇数パリティ */
#define SCIF_SCSMR_2STOP	0x0008U		/* 2ストッピビット */
#define SCIF_SCSMR_CKS1		0x0000U		/* P1φクロック1 */
#define SCIF_SCSMR_CKS4		0x0001U		/* P1φ/4クロック */
#define SCIF_SCSMR_CKS16	0x0002U		/* P1φ/16クロック */
#define SCIF_SCSMR_CKS64	0x0003U		/* P1φ/64クロック */

/*
 *  シリアルコントロールレジスタ（SCIF_SCSCR）の設定値
 */
#define SCIF_SCSCR_TIE		0x0080U		/* 送信割込み許可 */
#define SCIF_SCSCR_RIE		0x0040U		/* 受信割込み等許可 */
#define SCIF_SCSCR_TE		0x0020U		/* 送信許可 */
#define SCIF_SCSCR_RE		0x0010U		/* 受信許可 */
#define SCIF_SCSCR_REIE		0x0008U		/* 受信エラー割込み等許可 */
#define SCIF_SCSCR_INTCLK	0x0000U		/* 内部クロック，CKS端子は無視 */
										/*		  （調歩同期式の場合） */

/*
 *  シリアルステータスレジスタ（SCIF_SCFSR）の参照値
 */
#define SCIF_SCFSR_PER_MASK		0xf000U	/* パリティエラー数抽出マスク */
#define SCIF_SCFSR_PER_SHIFT	12		/* パリティエラー数抽出右シフト数 */
#define SCIF_SCFSR_FER_MASK		0x0f00U	/* フレーミングエラー数抽出マスク */
#define SCIF_SCFSR_FER_SHIFT	8		/* フレーミングエラー数抽出右シフト数 */
#define SCIF_SCFSR_ER		0x0080U		/* 受信エラー */
#define SCIF_SCFSR_TEND		0x0040U		/* 送信完了 */
#define SCIF_SCFSR_TDFE		0x0020U		/* 送信FIFOデータエンプティ */
#define SCIF_SCFSR_BRK		0x0010U		/* ブレーク検出 */
#define SCIF_SCFSR_FER		0x0008U		/* フレーミングエラー検出 */
#define SCIF_SCFSR_PER		0x0004U		/* パリティエラー検出 */
#define SCIF_SCFSR_RDF		0x0002U		/* 受信FIFOデータフル */
#define SCIF_SCFSR_DR		0x0001U		/* 受信データレディ */

/*
 *  FIFOコントロールレジスタ（SCIF_SCFCR）の設定値
 */
#define SCIF_SCFCR_RSTRG_15	0x0000U		/* RTS#出力アクティブトリガ：15 */
#define SCIF_SCFCR_RSTRG_1	0x0100U		/* RTS#出力アクティブトリガ：1 */
#define SCIF_SCFCR_RSTRG_4	0x0200U		/* RTS#出力アクティブトリガ：4 */
#define SCIF_SCFCR_RSTRG_6	0x0300U		/* RTS#出力アクティブトリガ：6 */
#define SCIF_SCFCR_RSTRG_8	0x0400U		/* RTS#出力アクティブトリガ：8 */
#define SCIF_SCFCR_RSTRG_10	0x0500U		/* RTS#出力アクティブトリガ：10 */
#define SCIF_SCFCR_RSTRG_12	0x0600U		/* RTS#出力アクティブトリガ：12 */
#define SCIF_SCFCR_RSTRG_14	0x0700U		/* RTS#出力アクティブトリガ：14 */
#define SCIF_SCFCR_RTRG_1	0x0000U		/* 受信FIFOデータ数トリガ：1 */
#define SCIF_SCFCR_RTRG_4	0x0040U		/* 受信FIFOデータ数トリガ：4 */
#define SCIF_SCFCR_RTRG_8	0x0080U		/* 受信FIFOデータ数トリガ：8 */
#define SCIF_SCFCR_RTRG_14	0x00C0U		/* 受信FIFOデータ数トリガ：14 */
#define SCIF_SCFCR_TTRG_8	0x0000U		/* 送信FIFOデータ数トリガ：8 */
#define SCIF_SCFCR_TTRG_4	0x0010U		/* 送信FIFOデータ数トリガ：4 */
#define SCIF_SCFCR_TTRG_2	0x0020U		/* 送信FIFOデータ数トリガ：2 */
#define SCIF_SCFCR_TTRG_0	0x0030U		/* 送信FIFOデータ数トリガ：0 */
#define SCIF_SCFCR_MCE		0x0008U		/* CTS#,RTS#許可 */
#define SCIF_SCFCR_TFRST	0x0004U		/* 送信FIFOデータレジスタリセット */
#define SCIF_SCFCR_RFRST	0x0002U		/* 受信FIFOデータレジスタリセット */
#define SCIF_SCFCR_LOOP		0x0001U		/* ループバックテスト */

/*
 *  FIFOデータカウントレジスタ（SCIF_SCFDR）の参照値
 */
#define SCIF_SCFDR_T_MASK	0x1f00U		/* 未送信データ数抽出マスク */
#define SCIF_SCFDR_T_SHIFT	8			/* 未送信データ数抽出右シフト数 */
#define SCIF_SCFDR_R_MASK	0x001fU		/* 受信データ数抽出マスク */
#define SCIF_SCFDR_R_SHIFT	0			/* 受信データ数抽出右シフト数 */

/*
 *  ラインステータスレジスタ（SCIF_SCLSR）の参照値
 */
#define SCIF_SCLSR_ORER		0x0001U		/* オーバーランエラー */

/*
 *  シリアル拡張モードレジスタ（SCIF_SCEMR）の設定値
 */
#define SCIF_SCEMR_BGDM		0x0080U		/* ボーレートジェネレータ倍速モード */
#define SCIF_SCEMR_ABCS16	0x0000U		/* ビットレートの16倍の基本クロック */
#define SCIF_SCEMR_ABCS8	0x0001U		/* ビットレートの8倍の基本クロック */

#endif /* TOPPERS_SCIF_H */
