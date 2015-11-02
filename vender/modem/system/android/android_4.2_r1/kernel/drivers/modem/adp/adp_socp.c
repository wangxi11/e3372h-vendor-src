 /*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include "bsp_socp.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ENABLE_BUILD_SOCP /* do not build socp, stub */
/*****************************************************************************
* �� �� ��  : DRV_SOCP_INIT
*
* ��������  : ģ���ʼ������
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : ��ʼ���ɹ��ı�ʶ��
*****************************************************************************/
BSP_S32 DRV_SOCP_INIT()
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CORDER_SET_SRC_CHAN
 ��������  : �˽ӿ����SOCP������Դͨ���ķ��䣬���ݱ�����Դͨ����������ͨ�����ԣ�����Ŀ��ͨ�������غ���ִ�н����
 �������  : pSrcAttr:������Դͨ�������ṹ��ָ�롣
             pSrcChanID:���뵽��Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Դͨ������ɹ���
             SOCP_ERROR:����Դͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_CORDER_SET_SRC_CHAN(SOCP_CODER_SRC_ENUM_U32 enSrcChanID, SOCP_CODER_SRC_CHAN_S *pSrcAttr)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CODER_SET_DEST_CHAN_ATTR
 ��������  : �˽ӿ����ĳһ����Ŀ��ͨ�������ã����غ���ִ�еĽ����
 �������  : u32DestChanID:SOCP��������Ŀ��ͨ��ID��
             pDestAttr:SOCP������Ŀ��ͨ�������ṹ��ָ�롣
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Ŀ��ͨ�����óɹ���
             SOCP_ERROR:����Ŀ��ͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_CODER_SET_DEST_CHAN_ATTR(BSP_U32 u32DestChanID, SOCP_CODER_DEST_CHAN_S *pDestAttr)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_SET_DEST_CHAN
 ��������  : �˽ӿ����SOCP������Ŀ��ͨ���ķ��䣬
             ���ݽ���Ŀ��ͨ����������ͨ�����ԣ�
             ������Դͨ�������غ���ִ�н����
 �������  : pAttr:������Ŀ��ͨ�������ṹ��ָ��
             pDestChanID:���뵽��Ŀ��ͨ��ID
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Ŀ��ͨ������ɹ���
             SOCP_ERROR:����Ŀ��ͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_SET_DEST_CHAN(SOCP_DECODER_DST_ENUM_U32 enDestChanID, SOCP_DECODER_DEST_CHAN_S *pAttr)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_SET_SRC_CHAN_ATTR
 ��������  : �˽ӿ����ĳһ����Դͨ�������ã����غ���ִ�еĽ����
 �������  : u32SrcChanID:������Դͨ��ID
             pInputAttr:������Դͨ�������ṹ��ָ��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Դͨ�����óɹ�
             SOCP_ERROR:����Դͨ������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_SET_SRC_CHAN_ATTR ( BSP_U32 u32SrcChanID,SOCP_DECODER_SRC_CHAN_S *pInputAttr)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_GET_ERR_CNT
 ��������  :�˽ӿڸ�������ͨ���������쳣����ļ���ֵ��
 �������  : u32ChanID:������ͨ��ID
                         pErrCnt:�������쳣�����ṹ��ָ��
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:�����쳣�����ɹ�
                             SOCP_ERROR:�����쳣����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_GET_ERR_CNT (BSP_U32 u32ChanID, SOCP_DECODER_ERROR_CNT_S *pErrCnt)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_FREE_CHANNEL
 ��������  : �˽ӿڸ���ͨ��ID�ͷŷ���ı����ͨ����
 �������  : u32ChanID:ͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ͨ���ͷųɹ���
             SOCP_ERROR:ͨ���ͷ�ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_FREE_CHANNEL(BSP_U32 u32ChanID)
{
    return 0;
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_CLEAN_ENCSRC_CHAN
*
* ��������  : ��ձ���Դͨ����ͬ��V9 SOCP�ӿ�
*
* �������  : enSrcChanID       ����ͨ����
*
* �������  : ��
*
* �� �� ֵ  : BSP_OK
*****************************************************************************/
BSP_U32 DRV_SOCP_CLEAN_ENCSRC_CHAN(SOCP_CODER_SRC_ENUM_U32 enSrcChanID)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_REGISTER_EVENT_CB
 ��������  : �˽ӿ�Ϊ����ͨ��ע���¼��ص�������
 �������  : u32ChanID:ͨ��ID��
             EventCB:�¼��ص��������ο�socp_event_cb��������
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע���¼��ص������ɹ���
             SOCP_ERROR:ע���¼��ص�����ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_EVENT_CB(BSP_U32 u32ChanID, socp_event_cb EventCB)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_START
 ��������  : �˽ӿ�����Դͨ��������������߽��롣
 �������  : u32SrcChanID:Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�������������ɹ���
             SOCP_ERROR:������������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_START(BSP_U32 u32SrcChanID)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_STOP
 ��������  : �˽ӿ�����Դͨ����ֹͣ������߽��롣
 �������  : u32SrcChanID:Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��������ֹͣ�ɹ���
             SOCP_ERROR:��������ֹͣʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_STOP(BSP_U32 u32SrcChanID)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_TIMEOUT
 ��������  : �˽ӿ����ó�ʱ��ֵ��
 �������  : u32Timeout:��ʱ��ֵ

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���ó�ʱʱ����ֵ�ɹ���
             SOCP_ERROR:���ó�ʱʱ����ֵʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_TIMEOUT (SOCP_TIMEOUT_EN_E eTmOutEn, BSP_U32 u32Timeout)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_DEC_PKT_LGTH
 ��������  : ���ý�������ȼ���ֵ
 �������  : pPktlgth:��������ȼ�ֵ

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���óɹ���
             ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_DEC_PKT_LGTH(SOCP_DEC_PKTLGTH_S *pPktlgth)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_DEBUG
 ��������  : ���ý���Դͨ����debugģʽ
 �������  : u32ChanID:ͨ��ID
             u32DebugEn: debug��ʶ
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���óɹ���
             ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_DEBUG(BSP_U32 u32DestChanID, BSP_U32 u32DebugEn)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CHAN_SOFT_RESET
 ��������  : Դͨ������λ
 �������  : u32ChanID:ͨ��ID
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�踴λ�ɹ���
             ����ֵ:��λʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_CHAN_SOFT_RESET(BSP_U32 u32ChanID)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_WRITE_BUFF
 ��������  : �˽ӿ����ڻ�ȡд����buffer��
 �������  : u32SrcChanID:Դͨ��ID
             pBuff:           :д����buffer

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡд����buffer�ɹ���
             SOCP_ERROR:��ȡд����bufferʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_WRITE_BUFF( BSP_U32 u32SrcChanID, SOCP_BUFFER_RW_S *pBuff)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_WRITE_DONE
 ��������  : �ýӿ��������ݵ�д�������ṩд�����ݵĳ��ȡ�
 �������  : u32SrcChanID:Դͨ��ID
             u32WrtSize:   ��д�����ݵĳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:д�����ݳɹ���
             SOCP_ERROR:д������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_WRITE_DONE(BSP_U32 u32SrcChanID, BSP_U32 u32WrtSize)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_REGISTER_RD_CB
 ��������  : �ýӿ�����ע���RD�������ж�ȡ���ݵĻص�������
 �������  : u32SrcChanID:Դͨ��ID
             RdCB:  �¼��ص�����
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע��RD���λ����������ݻص������ɹ���
             SOCP_ERROR:ע��RD���λ����������ݻص�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_RD_CB(BSP_U32 u32SrcChanID, socp_rd_cb RdCB)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_RD_BUFFER
 ��������  : �ô˽ӿ����ڻ�ȡRD buffer������ָ�롣
 �������  : u32SrcChanID:Դͨ��ID
             pBuff:  RD buffer
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡRD���λ������ɹ�
             SOCP_ERROR:��ȡRD���λ�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_RD_BUFFER( BSP_U32 u32SrcChanID,SOCP_BUFFER_RW_S *pBuff)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : bsp_socp_read_rd_done
 ��������  : �˽ӿ������ϲ�֪ͨSOCP��������RD buffer��ʵ�ʶ�ȡ�����ݡ�
 �������  : u32SrcChanID:Դͨ��ID
             u32RDSize:  ��RD buffer��ʵ�ʶ�ȡ�����ݳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡRDbuffer�е����ݳɹ�
             SOCP_ERROR:��ȡRDbuffer�е�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_READ_RD_DONE(BSP_U32 u32SrcChanID, BSP_U32 u32RDSize)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : bsp_socp_register_read_cb
 ��������  : �ýӿ�����ע������ݵĻص�������
 �������  : u32DestChanID:Ŀ��ͨ��ID
             ReadCB: �¼��ص�����
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע������ݻص������ɹ�
             SOCP_ERROR:ע������ݻص�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_READ_CB( BSP_U32 u32DestChanID, socp_read_cb ReadCB)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_READ_BUFF
 ��������  : �ô˽ӿ����ڻ�ȡ�����ݻ�����ָ�롣
 �������  : u32DestChanID:Ŀ��ͨ��ID
             ReadCB: ������buffer
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡ�����ݻ������ɹ���
             SOCP_ERROR:��ȡ�����ݻ������ɹ���
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_READ_BUFF(BSP_U32 u32DestChanID,SOCP_BUFFER_RW_S *pBuffer)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_READ_DATA_DONE
 ��������  : �ýӿ������ϲ����SOCP��������Ŀ��ͨ���ж��ߵ�ʵ�����ݡ�
 �������  : u32DestChanID:Ŀ��ͨ��ID
             u32ReadSize: �Ѷ������ݵĳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�����ݳɹ���
             SOCP_ERROR:������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_READ_DATA_DONE(BSP_U32 u32DestChanID,BSP_U32 u32ReadSize)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_BBP_ENABLE
 ��������  : ʹ�ܻ�ֹͣBBPͨ����
 �������  : bEnable:ͨ��ID
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:���óɹ���
                   ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_BBP_ENABLE(int bEnable)
{
    return 0;
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_BBP_DS_MODE
 ��������  : ����BBP DSͨ�������������ģʽ��
 �������  : eDsMode:DSͨ���������ʱ����ģʽ����
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:���óɹ���
                   ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_BBP_DS_MODE(SOCP_BBP_DS_MODE_E eDsMode)
{
    return 0;
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_GET_STATE
*
* ��������  : ��ȡSOCP״̬
*
* �� �� ֵ  : SOCP_IDLE    ����
*             SOCP_BUSY    æµ
*****************************************************************************/
SOCP_STATE_ENUM_UINT32 DRV_SOCP_GET_STATE()
{
    return 0;
}

/*****************************************************************************
* �� �� ��  : bsp_socp_enc_dst_buf_flush
* ��������  : SOCP����Ŀ��buffer���������������
* �������  : ��
* �������  : ��
* �� �� ֵ  :
*****************************************************************************/

BSP_S32 DRV_SOCP_ENC_DST_BUF_FLUSH(void)
{
	return 0;
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_VOTE
* ��������  : SOCPͶƱ�ӿڣ�����ͶƱ�������SOCP�Ƿ�˯�ߣ��ýӿ�ֻ��A���ṩ
* �������  : id --- ͶƱ���ID��type --- ͶƱ����
* �������  : ��
* �� �� ֵ  : BSP_S32 0 --- ͶƱ�ɹ���0xFFFFFFFF --- ͶƱʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_VOTE(SOCP_VOTE_ID_ENUM_U32 id, SOCP_VOTE_TYPE_ENUM_U32 type)
{
    return 0;
}

#else
/*****************************************************************************
* �� �� ��  : DRV_SOCP_INIT
*
* ��������  : ģ���ʼ������
*
* �������  : ��
*
* �������  : ��
*
* �� �� ֵ  : ��ʼ���ɹ��ı�ʶ��
*****************************************************************************/
BSP_S32 DRV_SOCP_INIT()
{
    return socp_init();
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CORDER_SET_SRC_CHAN
 ��������  : �˽ӿ����SOCP������Դͨ���ķ��䣬���ݱ�����Դͨ����������ͨ�����ԣ�����Ŀ��ͨ�������غ���ִ�н����
 �������  : pSrcAttr:������Դͨ�������ṹ��ָ�롣
             pSrcChanID:���뵽��Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Դͨ������ɹ���
             SOCP_ERROR:����Դͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_CORDER_SET_SRC_CHAN(SOCP_CODER_SRC_ENUM_U32 enSrcChanID, SOCP_CODER_SRC_CHAN_S *pSrcAttr)
{
    return bsp_socp_coder_set_src_chan(enSrcChanID, pSrcAttr);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CODER_SET_DEST_CHAN_ATTR
 ��������  : �˽ӿ����ĳһ����Ŀ��ͨ�������ã����غ���ִ�еĽ����
 �������  : u32DestChanID:SOCP��������Ŀ��ͨ��ID��
             pDestAttr:SOCP������Ŀ��ͨ�������ṹ��ָ�롣
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Ŀ��ͨ�����óɹ���
             SOCP_ERROR:����Ŀ��ͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_CODER_SET_DEST_CHAN_ATTR(BSP_U32 u32DestChanID, SOCP_CODER_DEST_CHAN_S *pDestAttr)
{
    return bsp_socp_coder_set_dest_chan_attr(u32DestChanID, pDestAttr);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_SET_DEST_CHAN
 ��������  : �˽ӿ����SOCP������Ŀ��ͨ���ķ��䣬
             ���ݽ���Ŀ��ͨ����������ͨ�����ԣ�
             ������Դͨ�������غ���ִ�н����
 �������  : pAttr:������Ŀ��ͨ�������ṹ��ָ��
             pDestChanID:���뵽��Ŀ��ͨ��ID
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Ŀ��ͨ������ɹ���
             SOCP_ERROR:����Ŀ��ͨ������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_SET_DEST_CHAN(SOCP_DECODER_DST_ENUM_U32 enDestChanID, SOCP_DECODER_DEST_CHAN_S *pAttr)
{
    return bsp_socp_decoder_set_dest_chan(enDestChanID, pAttr);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_SET_SRC_CHAN_ATTR
 ��������  : �˽ӿ����ĳһ����Դͨ�������ã����غ���ִ�еĽ����
 �������  : u32SrcChanID:������Դͨ��ID
             pInputAttr:������Դͨ�������ṹ��ָ��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:����Դͨ�����óɹ�
             SOCP_ERROR:����Դͨ������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_SET_SRC_CHAN_ATTR ( BSP_U32 u32SrcChanID,SOCP_DECODER_SRC_CHAN_S *pInputAttr)
{
    return bsp_socp_decoder_set_src_chan_attr(u32SrcChanID, pInputAttr);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_DECODER_GET_ERR_CNT
 ��������  :�˽ӿڸ�������ͨ���������쳣����ļ���ֵ��
 �������  : u32ChanID:������ͨ��ID
                         pErrCnt:�������쳣�����ṹ��ָ��
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:�����쳣�����ɹ�
                             SOCP_ERROR:�����쳣����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_DECODER_GET_ERR_CNT (BSP_U32 u32ChanID, SOCP_DECODER_ERROR_CNT_S *pErrCnt)
{
    return bsp_socp_decoder_get_err_cnt(u32ChanID, pErrCnt);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_FREE_CHANNEL
 ��������  : �˽ӿڸ���ͨ��ID�ͷŷ���ı����ͨ����
 �������  : u32ChanID:ͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ͨ���ͷųɹ���
             SOCP_ERROR:ͨ���ͷ�ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_FREE_CHANNEL(BSP_U32 u32ChanID)
{
    return bsp_socp_free_channel(u32ChanID);
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_CLEAN_ENCSRC_CHAN
*
* ��������  : ��ձ���Դͨ����ͬ��V9 SOCP�ӿ�
*
* �������  : enSrcChanID       ����ͨ����
*
* �������  : ��
*
* �� �� ֵ  : BSP_OK
*****************************************************************************/
BSP_U32 DRV_SOCP_CLEAN_ENCSRC_CHAN(SOCP_CODER_SRC_ENUM_U32 enSrcChanID)
{
    return bsp_socp_clean_encsrc_chan(enSrcChanID);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_REGISTER_EVENT_CB
 ��������  : �˽ӿ�Ϊ����ͨ��ע���¼��ص�������
 �������  : u32ChanID:ͨ��ID��
             EventCB:�¼��ص��������ο�socp_event_cb��������
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע���¼��ص������ɹ���
             SOCP_ERROR:ע���¼��ص�����ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_EVENT_CB(BSP_U32 u32ChanID, socp_event_cb EventCB)
{
    return bsp_socp_register_event_cb(u32ChanID, EventCB);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_START
 ��������  : �˽ӿ�����Դͨ��������������߽��롣
 �������  : u32SrcChanID:Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�������������ɹ���
             SOCP_ERROR:������������ʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_START(BSP_U32 u32SrcChanID)
{
    return bsp_socp_start(u32SrcChanID);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_STOP
 ��������  : �˽ӿ�����Դͨ����ֹͣ������߽��롣
 �������  : u32SrcChanID:Դͨ��ID��
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��������ֹͣ�ɹ���
             SOCP_ERROR:��������ֹͣʧ�ܡ�
*****************************************************************************/
BSP_S32 DRV_SOCP_STOP(BSP_U32 u32SrcChanID)
{
    return bsp_socp_stop(u32SrcChanID);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_TIMEOUT
 ��������  : �˽ӿ����ó�ʱ��ֵ��
 �������  : u32Timeout:��ʱ��ֵ

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���ó�ʱʱ����ֵ�ɹ���
             SOCP_ERROR:���ó�ʱʱ����ֵʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_TIMEOUT (SOCP_TIMEOUT_EN_E eTmOutEn, BSP_U32 u32Timeout)
{
    return bsp_socp_set_timeout(eTmOutEn, u32Timeout);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_DEC_PKT_LGTH
 ��������  : ���ý�������ȼ���ֵ
 �������  : pPktlgth:��������ȼ�ֵ

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���óɹ���
             ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_DEC_PKT_LGTH(SOCP_DEC_PKTLGTH_S *pPktlgth)
{
    return bsp_socp_set_dec_pkt_lgth(pPktlgth);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_DEBUG
 ��������  : ���ý���Դͨ����debugģʽ
 �������  : u32ChanID:ͨ��ID
             u32DebugEn: debug��ʶ
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:���óɹ���
             ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_DEBUG(BSP_U32 u32DestChanID, BSP_U32 u32DebugEn)
{
    return bsp_socp_set_debug(u32DestChanID, u32DebugEn);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_CHAN_SOFT_RESET
 ��������  : Դͨ������λ
 �������  : u32ChanID:ͨ��ID
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�踴λ�ɹ���
             ����ֵ:��λʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_CHAN_SOFT_RESET(BSP_U32 u32ChanID)
{
    return bsp_socp_chan_soft_reset(u32ChanID);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_WRITE_BUFF
 ��������  : �˽ӿ����ڻ�ȡд����buffer��
 �������  : u32SrcChanID:Դͨ��ID
             pBuff:           :д����buffer

 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡд����buffer�ɹ���
             SOCP_ERROR:��ȡд����bufferʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_WRITE_BUFF( BSP_U32 u32SrcChanID, SOCP_BUFFER_RW_S *pBuff)
{
    return bsp_socp_get_write_buff(u32SrcChanID, pBuff);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_WRITE_DONE
 ��������  : �ýӿ��������ݵ�д�������ṩд�����ݵĳ��ȡ�
 �������  : u32SrcChanID:Դͨ��ID
             u32WrtSize:   ��д�����ݵĳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:д�����ݳɹ���
             SOCP_ERROR:д������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_WRITE_DONE(BSP_U32 u32SrcChanID, BSP_U32 u32WrtSize)
{
    return bsp_socp_write_done(u32SrcChanID, u32WrtSize);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_REGISTER_RD_CB
 ��������  : �ýӿ�����ע���RD�������ж�ȡ���ݵĻص�������
 �������  : u32SrcChanID:Դͨ��ID
             RdCB:  �¼��ص�����
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע��RD���λ����������ݻص������ɹ���
             SOCP_ERROR:ע��RD���λ����������ݻص�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_RD_CB(BSP_U32 u32SrcChanID, socp_rd_cb RdCB)
{
    return bsp_socp_register_rd_cb(u32SrcChanID, RdCB);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_RD_BUFFER
 ��������  : �ô˽ӿ����ڻ�ȡRD buffer������ָ�롣
 �������  : u32SrcChanID:Դͨ��ID
             pBuff:  RD buffer
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡRD���λ������ɹ�
             SOCP_ERROR:��ȡRD���λ�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_RD_BUFFER( BSP_U32 u32SrcChanID,SOCP_BUFFER_RW_S *pBuff)
{
    return bsp_socp_get_rd_buffer(u32SrcChanID, pBuff);
}

/*****************************************************************************
 �� �� ��  : bsp_socp_read_rd_done
 ��������  : �˽ӿ������ϲ�֪ͨSOCP��������RD buffer��ʵ�ʶ�ȡ�����ݡ�
 �������  : u32SrcChanID:Դͨ��ID
             u32RDSize:  ��RD buffer��ʵ�ʶ�ȡ�����ݳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡRDbuffer�е����ݳɹ�
             SOCP_ERROR:��ȡRDbuffer�е�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_READ_RD_DONE(BSP_U32 u32SrcChanID, BSP_U32 u32RDSize)
{
    return bsp_socp_read_rd_done(u32SrcChanID, u32RDSize);
}

/*****************************************************************************
 �� �� ��  : bsp_socp_register_read_cb
 ��������  : �ýӿ�����ע������ݵĻص�������
 �������  : u32DestChanID:Ŀ��ͨ��ID
             ReadCB: �¼��ص�����
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:ע������ݻص������ɹ�
             SOCP_ERROR:ע������ݻص�����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_REGISTER_READ_CB( BSP_U32 u32DestChanID, socp_read_cb ReadCB)
{
    return bsp_socp_register_read_cb(u32DestChanID, ReadCB);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_GET_READ_BUFF
 ��������  : �ô˽ӿ����ڻ�ȡ�����ݻ�����ָ�롣
 �������  : u32DestChanID:Ŀ��ͨ��ID
             ReadCB: ������buffer
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:��ȡ�����ݻ������ɹ���
             SOCP_ERROR:��ȡ�����ݻ������ɹ���
*****************************************************************************/
BSP_S32 DRV_SOCP_GET_READ_BUFF(BSP_U32 u32DestChanID,SOCP_BUFFER_RW_S *pBuffer)
{
    return bsp_socp_get_read_buff(u32DestChanID, pBuffer);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_READ_DATA_DONE
 ��������  : �ýӿ������ϲ����SOCP��������Ŀ��ͨ���ж��ߵ�ʵ�����ݡ�
 �������  : u32DestChanID:Ŀ��ͨ��ID
             u32ReadSize: �Ѷ������ݵĳ���
 �������  : �ޡ�
 �� �� ֵ  : SOCP_OK:�����ݳɹ���
             SOCP_ERROR:������ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_READ_DATA_DONE(BSP_U32 u32DestChanID,BSP_U32 u32ReadSize)
{
    return bsp_socp_read_data_done(u32DestChanID, u32ReadSize);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_BBP_ENABLE
 ��������  : ʹ�ܻ�ֹͣBBPͨ����
 �������  : bEnable:ͨ��ID
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:���óɹ���
                   ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_BBP_ENABLE(int bEnable)
{
    return bsp_socp_set_bbp_enable(bEnable);
}

/*****************************************************************************
 �� �� ��  : DRV_SOCP_SET_BBP_DS_MODE
 ��������  : ����BBP DSͨ�������������ģʽ��
 �������  : eDsMode:DSͨ���������ʱ����ģʽ����
 �������  : �ޡ�
 �� �� ֵ      : SOCP_OK:���óɹ���
                   ����ֵ:����ʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_SET_BBP_DS_MODE(SOCP_BBP_DS_MODE_E eDsMode)
{
    return bsp_socp_set_bbp_ds_mode(eDsMode);
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_GET_STATE
*
* ��������  : ��ȡSOCP״̬
*
* �� �� ֵ  : SOCP_IDLE    ����
*             SOCP_BUSY    æµ
*****************************************************************************/
SOCP_STATE_ENUM_UINT32 DRV_SOCP_GET_STATE()
{
    return bsp_socp_get_state();
}

/*****************************************************************************
* �� �� ��  : bsp_socp_enc_dst_buf_flush
* ��������  : SOCP����Ŀ��buffer���������������
* �������  : ��
* �������  : ��
* �� �� ֵ  :
*****************************************************************************/

BSP_S32 DRV_SOCP_ENC_DST_BUF_FLUSH(void)
{
	return bsp_socp_enc_dst_buf_flush();
}

/*****************************************************************************
* �� �� ��  : DRV_SOCP_VOTE
* ��������  : SOCPͶƱ�ӿڣ�����ͶƱ�������SOCP�Ƿ�˯�ߣ��ýӿ�ֻ��A���ṩ
* �������  : id --- ͶƱ���ID��type --- ͶƱ����
* �������  : ��
* �� �� ֵ  : BSP_S32 0 --- ͶƱ�ɹ���0xFFFFFFFF --- ͶƱʧ��
*****************************************************************************/
BSP_S32 DRV_SOCP_VOTE(SOCP_VOTE_ID_ENUM_U32 id, SOCP_VOTE_TYPE_ENUM_U32 type)
{
#if(FEATURE_SOCP_ON_DEMAND == FEATURE_ON)
    return bsp_socp_vote(id, type);
#else
    return 0;
#endif
}

#endif /* ENABLE_BUILD_SOCP */

BSP_VOID BSP_SOCP_RefreshSDLogCfg(BSP_U32 ulTimerLen)
{
	return;
}

#ifdef __cplusplus
}
#endif

