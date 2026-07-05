// pseudo-c export driven by kernel-01.03.01.89.embedded-kallsyms.txt
// decompiler: pdg
// analysis mode: aaa
// kallsyms remap mode: none
// kallsyms source mode: embedded
// subset file: kallsyms-sitronix.txt

// ----- BEGIN sitronix_ts_input_dev_init (t) [.kernel] file=0xc043c2c4 runtime=0xc043c2c4 -----

int sym.sitronix_ts_input_dev_init(int32_t arg1)

{
    int iVar1;
    uint *puVar2;
    size_t n;
    int iVar3;
    int iVar4;
    uint noname_1;
    
    puVar2 = sym.input_allocate_device();
    *(arg1 + 8) = puVar2;
    iVar3 = *0xc043c650;
    if (puVar2 == NULL) {
        iVar3 = -0xc;
    }
    else {
        iVar4 = 0;
        *puVar2 = *arg1;
        *(*(arg1 + 8) + 0xc) = **(arg1 + 0x10);
        *(*(arg1 + 8) + 0x10) = 0;
        *(*(arg1 + 8) + 0x12) = 0;
        *(*(arg1 + 8) + 0x1f8) = *(*(arg1 + 4) + 0x58);
        *(*(arg1 + 8) + 0x214) = arg1;
        sym._set_bit(0,*(arg1 + 8) + 0x18);
        sym._set_bit(1,*(arg1 + 8) + 0x18);
        sym._set_bit(3,*(arg1 + 8) + 0x18);
        sym._set_bit(0x14a,*(arg1 + 8) + 0x1c);
        sym.input_set_capability(*(arg1 + 8),1,0x74);
        sym.input_set_capability(*(arg1 + 8),1,0x16);
        sym.input_set_capability(*(arg1 + 8),1,0x67);
        sym.input_set_capability(*(arg1 + 8),1,0x6c);
        sym.input_set_capability(*(arg1 + 8),1,0x69);
        sym.input_set_capability(*(arg1 + 8),1,0x6a);
        sym.input_set_capability(*(arg1 + 8),1,0x18);
        sym.input_set_capability(*(arg1 + 8),1,0x12);
        sym.input_set_capability(*(arg1 + 8),1,0x32);
        sym.input_set_capability(*(arg1 + 8),1,0x26);
        sym.input_set_capability(*(arg1 + 8),1,0x11);
        sym.input_set_capability(*(arg1 + 8),1,0x1f);
        sym.input_set_capability(*(arg1 + 8),1,0x2f);
        sym.input_set_capability(*(arg1 + 8),1,0x2c);
        sym.input_set_capability(*(arg1 + 8),1,0x2e);
        sym._set_bit(0x74,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x6a,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x69,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x67,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x6c,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x16,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x18,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x12,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x32,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x11,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x26,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x1f,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x2f,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x2c,*(arg1 + 8) + 0x1c);
        sym._set_bit(0x2e,*(arg1 + 8) + 0x1c);
        sym.input_mt_init_slots(*(arg1 + 8),*(arg1 + 0x1e),2);
        sym._set_bit(1,*(arg1 + 8) + 0x14);
        sym.input_set_abs_params(*(arg1 + 8),0x30,0,0xff);
        sym.input_set_abs_params(*(arg1 + 8),0x3a,0,0xff);
        sym.input_set_abs_params(*(arg1 + 8),0x39,0,*(arg1 + 0x1e));
        sym.input_set_abs_params(*(arg1 + 8),0x35,0,*(arg1 + 0x20) - 1);
        sym.input_set_abs_params(*(arg1 + 8),0x36,0,*(arg1 + 0x22) - 1);
        sym._set_bit(1,*(arg1 + 8) + 0x18);
        do {
            iVar1 = iVar4 * 4;
            iVar4 = iVar4 + 1;
            sym._set_bit(*(iVar3 + iVar1),*(arg1 + 8) + 0x1c);
        } while (iVar4 != 3);
        iVar3 = sym.input_register_device(*(arg1 + 8),noname_1,n);
        if (iVar3 != 0) {
            sym.input_free_device(*(arg1 + 8));
            *(arg1 + 8) = 0;
        }
    }
    return iVar3;
}

// ----- END sitronix_ts_input_dev_init -----

// ----- BEGIN sitronix_ts_remove (t) [.kernel] file=0xc043c654 runtime=0xc043c654 -----

uint sym.sitronix_ts_remove(int32_t arg1)

{
    size_t *psVar1;
    size_t arg1_00;
    
    arg1_00 = *(arg1 + 0x74);
    if (arg1_00 != 0) {
        sym.sitronix_mt_stop();
        sym.sitronix_remove_proc();
        sym.sitronix_remove_st_dev(arg1_00);
        sym.sitronix_remove_sysfs(arg1_00);
        if (*(arg1_00 + 0x30) != 0) {
            sym.destroy_workqueue(*(arg1_00 + 0x30));
        }
        sym.fb_unregister_client(arg1_00 + 0x58);
        if (0 < *(arg1_00 + 100)) {
            sym.free_irq(*(arg1_00 + 100),arg1_00);
        }
        if (*(arg1_00 + 0xc) != 0) {
            sym.input_unregister_device(*(arg1_00 + 0xc));
            sym.input_free_device(*(arg1_00 + 0xc));
        }
        if (*(arg1_00 + 8) != 0) {
            sym.input_unregister_device(*(arg1_00 + 8));
            sym.input_free_device(*(arg1_00 + 8));
        }
        sym.mutex_destroy(arg1_00 + 0x70);
    }
    psVar1 = *0xc043c72c;
    if (**0xc043c72c != 0) {
        sym.kfree(**0xc043c72c);
        *psVar1 = 0;
    }
    if (psVar1[1] != 0) {
        sym.kfree(psVar1[1]);
        psVar1[1] = 0;
    }
    if (arg1_00 != 0) {
        sym.kfree(arg1_00);
    }
    return 0;
}

// ----- END sitronix_ts_remove -----

// ----- BEGIN sitronix_ts_pen_up (t) [.kernel] file=0xc043c730 runtime=0xc043c730 -----

void sym.sitronix_ts_pen_up(int32_t arg1,int32_t arg2)

{
    int iVar1;
    uint32_t uVar2;
    uint32_t *puVar3;
    int16_t *arg1_00;
    uint uVar4;
    
    sym.input_event(arg1,3,0x2f,arg2);
    uVar4 = sym.input_mt_report_slot_state(arg1,0,0);
    sym.input_report_abs(uVar4,0x30,0);
    iVar1 = sym.is_event_supported(3,arg1 + 0x18,0x1f);
    if (iVar1 == 0) {
        return;
    }
    arg1_00 = arg1 + 0x18c;
    uVar4 = sym._raw_spin_lock_irqsave(arg1_00);
    sym.input_handle_event(arg1,3,0x3a,0);
    DataMemoryBarrier(0xb);
    *arg1_00 = *arg1_00 + 1;
    sym.dsb_sev(arg1_00,uVar4);
    sym.preempt_count_sub(1);
    if ((&stack0xfffffff8 & 0xffffe000)[1] == 0) {
        uVar2 = *(&stack0xfffffff8 & 0xffffe000) >> 1;
    }
    else {
        uVar2 = 0;
    }
    if ((uVar2 & 1) != 0) {
        if (*((&stack0xfffffffc & 0xffffe000) + 4) != 0) {
            return;
        }
        puVar3 = &stack0xfffffff0 & 0xffffe000;
        do {
            puVar3[1] = puVar3[1] + 1;
            sym.preempt_latency_start(1);
            sym.__schedule(1);
            puVar3[1] = puVar3[1] - 1;
        } while ((*puVar3 & 2) != 0);
        return;
    }
    return;
}

// ----- END sitronix_ts_pen_up -----

// ----- BEGIN sitronix_ts_pen_allup (t) [.kernel] file=0xc043c77c runtime=0xc043c77c -----

void sym.sitronix_ts_pen_allup(int32_t arg1)

{
    uint uVar1;
    int arg1_00;
    uint32_t uVar2;
    uint32_t *puVar3;
    int16_t *arg1_01;
    int iVar4;
    
    for (iVar4 = 0; iVar4 < *(arg1 + 0x1e); iVar4 = iVar4 + 1) {
        sym.sitronix_ts_pen_up(*(arg1 + 8),iVar4);
    }
    sym.input_event(*(arg1 + 8),1,0x14a,0);
    arg1_00 = *(arg1 + 8);
    iVar4 = sym.is_event_supported(0,arg1_00 + 0x18,0x1f);
    if (iVar4 != 0) {
        arg1_01 = arg1_00 + 0x18c;
        uVar1 = sym._raw_spin_lock_irqsave(arg1_01);
        sym.input_handle_event(arg1_00,0,0,0);
        DataMemoryBarrier(0xb);
        *arg1_01 = *arg1_01 + 1;
        sym.dsb_sev(arg1_01,uVar1);
        sym.preempt_count_sub(1);
        if ((&stack0xfffffff8 & 0xffffe000)[1] == 0) {
            uVar2 = *(&stack0xfffffff8 & 0xffffe000) >> 1;
        }
        else {
            uVar2 = 0;
        }
        if ((uVar2 & 1) != 0) {
            if (*((&stack0xfffffffc & 0xffffe000) + 4) != 0) {
                return;
            }
            puVar3 = &stack0xfffffff0 & 0xffffe000;
            do {
                puVar3[1] = puVar3[1] + 1;
                sym.preempt_latency_start(1);
                sym.__schedule(1);
                puVar3[1] = puVar3[1] - 1;
            } while ((*puVar3 & 2) != 0);
            return;
        }
        return;
    }
    return;
}

// ----- END sitronix_ts_pen_allup -----

// ----- BEGIN sitronix_ts_irq_enable (T) [.kernel] file=0xc043c7c8 runtime=0xc043c7c8 -----

uint sym.sitronix_ts_irq_enable(int32_t arg1,int32_t arg2)

{
    int iVar1;
    
    iVar1 = *0xc043c80c;
    if (arg2 == 0) {
        if (*(*0xc043c80c + 0xa0) != '\0') {
            sym.disable_irq_nosync(*(arg1 + 100));
        }
    }
    else if (*(*0xc043c80c + 0xa0) == '\0') {
        sym.enable_irq(*(arg1 + 100));
    }
    *(iVar1 + 0xa0) = arg2;
    return 0;
}

// ----- END sitronix_ts_irq_enable -----

// ----- BEGIN sitronix_fb_notifier_callback (t) [.kernel] file=0xc043c810 runtime=0xc043c810 -----

uint sym.sitronix_fb_notifier_callback(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int iVar1;
    int iVar2;
    int32_t extraout_r1;
    int32_t arg2_00;
    int32_t arg2_01;
    int32_t extraout_r1_00;
    
    if (arg3 != 0) {
        if ((*(arg3 + 4) != NULL && arg2 == 9) && (**(arg3 + 4) == 0)) {
            sym.queue_work_on(2,*(arg1 + -0x28),arg1 + -0x20);
        }
        iVar2 = *0xc043c980;
        if ((*(arg3 + 4) != NULL && arg2 == 9) && (**(arg3 + 4) == 4)) {
            sym.cancel_work_sync(arg1 + -0x20);
            iVar1 = *(iVar2 + 8);
            *(iVar1 + 0x89) = 0;
            sym.mutex_lock(iVar1 + 0x70);
            if ((*(*(iVar2 + 8) + 400) == '\0') || (*(*(iVar2 + 8) + 0x8b) != '\0')) {
                sym.sitronix_mt_suspend();
            }
            iVar1 = *(iVar2 + 8);
            if ((*(iVar1 + 400) == '\0') && (*(iVar1 + 0x8b) == '\0')) {
                sym.sitronix_ts_set_smart_wake_up(iVar1,0);
                sym.sitronix_ts_irq_enable(*(iVar2 + 8),0);
                arg2_00 = extraout_r1_00;
            }
            else {
                sym.sitronix_ts_set_smart_wake_up(iVar1,1);
                sym.irq_set_irq_wake(*(*(iVar2 + 8) + 100),1);
                *(*(iVar2 + 8) + 0x191) = 1;
                arg2_00 = extraout_r1;
            }
            sym.msleep(0x14,arg2_00);
            sym.sitronix_ts_powerdown(*(iVar2 + 8),1);
            sym.msleep(10,arg2_01);
            sym.sitronix_ts_pen_allup(*(iVar2 + 8));
            if ((*(*(iVar2 + 8) + 400) != '\0') && (*(*(iVar2 + 8) + 0x191) != '\0')) {
                sym.sitronix_mode_restore();
                sym.sitronix_swk_config_restore();
            }
            iVar2 = *(iVar2 + 8);
            *(iVar2 + 0x6c) = 1;
            sym.mutex_unlock(iVar2 + 0x70);
        }
    }
    return 0;
}

// ----- END sitronix_fb_notifier_callback -----

// ----- BEGIN sitronix_ts_reset_device (T) [.kernel] file=0xc043c984 runtime=0xc043c984 -----

uint sym.sitronix_ts_reset_device(int32_t arg1)

{
    int32_t iVar1;
    int32_t arg2;
    int32_t arg2_00;
    
    iVar1 = sym.gpio_to_desc(*(*(arg1 + 0x10) + 0xc));
    sym.gpiod_direction_output_raw(iVar1,0);
    sym.msleep(1,arg2);
    iVar1 = sym.gpio_to_desc(*(*(arg1 + 0x10) + 0xc));
    sym.gpiod_direction_output_raw(iVar1,1);
    sym.msleep(100,arg2_00);
    return 0;
}

// ----- END sitronix_ts_reset_device -----

// ----- BEGIN sitronix_ts_probe (t) [.kernel] file=0xc043c9cc runtime=0xc043c9cc -----

uint sym.sitronix_ts_probe(int32_t arg1)

{
    size_t *psVar1;
    uchar uVar2;
    uint *arg1_00;
    void *s;
    size_t sVar3;
    int iVar4;
    int32_t arg1_01;
    uint32_t arg1_02;
    uint *puVar5;
    size_t n;
    uint uVar6;
    int iVar7;
    uint noname_1;
    
    psVar1 = *0xc043cd5c;
    iVar7 = *(arg1 + 0x70);
    (*0xc043cd5c)[1] = 0;
    *psVar1 = 0;
    iVar4 = *0xc043cd60;
    if (iVar7 == 0) {
        return 0xffffffea;
    }
    arg1_00 = sym.kmem_cache_alloc(*(*0xc043cd60 + 0x28),0xdc0);
    if (arg1_00 == NULL) {
        return 0xfffffff4;
    }
    sym.__mutex_init(arg1_00 + 0x1c);
    *(arg1_00 + 0x89) = 1;
    uVar6 = *arg1;
    *(arg1 + 0x74) = arg1_00;
    arg1_00[4] = iVar7;
    *arg1_00 = uVar6;
    arg1_00[1] = arg1;
    *(arg1_00 + 0x1b) = 0;
    *(arg1_00 + 0x1c3) = 2;
    *(arg1_00 + 0x2df) = 0;
    *(arg1_00 + 0xb8) = 0;
    arg1_00[0xc] = 0;
    arg1_00[0xb] = 0;
    s = *(iVar4 + 0x34);
    psVar1[2] = arg1_00;
    sVar3 = sym.kmem_cache_alloc(s,0xdc0);
    psVar1[1] = sVar3;
    if (sVar3 != 0) {
        sVar3 = sym.kmem_cache_alloc(*(iVar4 + 0x34),0xdc0);
        *psVar1 = sVar3;
        if (sVar3 != 0) {
            sym.sitronix_ts_reset_device(arg1_00);
            uVar2 = sym.sitronix_get_chip_id();
            *(psVar1[2] + 0x14) = uVar2;
            uVar2 = sym.sitronix_get_ic_sfrver();
            *(psVar1[2] + 0x29) = uVar2;
            sym.sitronix_set_default_test_criteria();
            sym.sitronix_replace_dump_buf(0);
            sym.sitronix_ts_reset_device(arg1_00);
            sym.sitronix_ts_get_device_status(arg1_00);
            sym.sitronix_ts_get_device_info(arg1_00);
            iVar4 = sym.sitronix_ts_input_dev_init(arg1_00);
            if (iVar4 == 0) {
                if (*(arg1_00 + 0x8a) == '\0') {
code_r0xc043cbc8:
                    arg1_01 = sym.gpio_to_desc(*(iVar7 + 4));
                    arg1_02 = sym.gpiod_to_irq(arg1_01);
                    arg1_00[0x19] = arg1_02;
                    if (-1 < arg1_02) {
                        arg1_00[0x1a] = 0x2008;
                        iVar4 = sym.request_threaded_irq(arg1_02,0,*0xc043cd68,0x2008);
                        if (-1 < iVar4) {
                            iVar4 = sym.alloc_workqueue(*0xc043cd74,*0xc043cd70);
                            arg1_00[0xc] = iVar4;
                            if (iVar4 == 0) goto code_r0xc043cd54;
                            arg1_00[0xe] = 0xffffffe0;
                            arg1_00[0xf] = arg1_00 + 0xf;
                            arg1_00[0x10] = arg1_00 + 0xf;
                            arg1_00[0x11] = *0xc043cd78;
                            arg1_00[0x16] = *0xc043cd7c;
                            iVar4 = sym.fb_register_client(arg1_00 + 0x16);
                            if ((((iVar4 == 0) && (iVar4 = sym.sitronix_create_sysfs(arg1_00), iVar4 == 0)) &&
                                (iVar4 = sym.sitronix_create_proc(), iVar4 == 0)) &&
                               (iVar4 = sym.sitronix_create_st_dev(arg1_00), iVar4 == 0)) {
                                sym.sitronix_mode_backup();
                                sym.sitronix_swk_config_backup();
                                *(arg1_00 + 0xfe) = 1;
                                arg1_00[0x42] = *0xc043cd80;
                                sym.sitronix_mt_start(10000);
                                return 0;
                            }
                        }
                    }
                }
                else {
                    puVar5 = sym.input_allocate_device();
                    arg1_00[3] = puVar5;
                    if (puVar5 != NULL) {
                        *puVar5 = *0xc043cd84;
                        *(arg1_00[3] + 0xc) = *arg1_00[4];
                        *(arg1_00[3] + 0x1f8) = *(arg1_00[1] + 0x58);
                        sym._set_bit(0,arg1_00[3] + 0x18);
                        sym._set_bit(5,arg1_00[3] + 0x18);
                        sym._set_bit(1,arg1_00[3] + 0x14);
                        sym.input_set_abs_params(arg1_00[3],0x19,0,0xff);
                        *(arg1_00[3] + 0x214) = arg1_00;
                        iVar4 = sym.input_register_device(arg1_00[3],noname_1,n);
                        if (iVar4 == 0) goto code_r0xc043cbc8;
                    }
                }
            }
            uVar6 = 0xffffffea;
            goto code_r0xc043cae8;
        }
    }
code_r0xc043cd54:
    uVar6 = 0xfffffff4;
code_r0xc043cae8:
    sym.sitronix_remove_st_dev(arg1_00);
    sym.sitronix_remove_proc();
    sym.sitronix_remove_sysfs(arg1_00);
    if (arg1_00[0xc] != 0) {
        sym.destroy_workqueue(arg1_00[0xc]);
    }
    sym.fb_unregister_client(arg1_00 + 0x16);
    sym.sitronix_mt_stop();
    if (0 < arg1_00[0x19]) {
        sym.free_irq(arg1_00[0x19],arg1_00);
    }
    if (arg1_00[3] != 0) {
        sym.input_unregister_device(arg1_00[3]);
        sym.input_free_device(arg1_00[3]);
        arg1_00[3] = 0;
    }
    if (arg1_00[2] != 0) {
        sym.input_unregister_device(arg1_00[2]);
        sym.input_free_device(arg1_00[2]);
        arg1_00[2] = 0;
    }
    if (*psVar1 != 0) {
        sym.kfree(*psVar1);
        *psVar1 = 0;
    }
    if (psVar1[1] != 0) {
        sym.kfree(psVar1[1]);
        psVar1[1] = 0;
    }
    sym.mutex_destroy(arg1_00 + 0x1c);
    *(arg1 + 0x74) = 0;
    sym.kfree(arg1_00);
    psVar1[2] = 0;
    return uVar6;
}

// ----- END sitronix_ts_probe -----

// ----- BEGIN sitronix_ts_resume_work (t) [.kernel] file=0xc043cd88 runtime=0xc043cd88 -----

void sym.sitronix_ts_resume_work(uint noname_0,int32_t arg1)

{
    int iVar1;
    int iVar2;
    uint32_t arg1_00;
    ulong uVar3;
    
    iVar1 = *0xc043ce44;
    if (*(*(*0xc043ce44 + 8) + 0x89) != '\0') {
        *(*(*0xc043ce44 + 8) + 0x89) = 0;
        return;
    }
    sym.msleep(200,arg1);
    sym.mutex_lock(*(iVar1 + 8) + 0x70);
    sym.sitronix_ts_reset_device(*(iVar1 + 8));
    sym.sitronix_ts_powerdown(*(iVar1 + 8),0);
    iVar2 = *(iVar1 + 8);
    if (*(iVar2 + 400) == '\0') {
        sym.sitronix_ts_irq_enable(iVar2,1);
    }
    else {
        sym.irq_set_irq_wake(*(iVar2 + 100),0);
    }
    iVar2 = *(iVar1 + 8);
    *(iVar2 + 0x191) = 0;
    *(iVar2 + 0x6c) = 0;
    sym.sitronix_mode_restore();
    sym.sitronix_swk_config_restore();
    uVar3 = sym.mutex_unlock(*(iVar1 + 8) + 0x70);
    arg1_00 = *(*(iVar1 + 8) + 400);
    if ((arg1_00 != 0) && (*(*(iVar1 + 8) + 0x8b) == '\0')) {
        return;
    }
    sym.sitronix_mt_pause_one(uVar3,uVar3 >> 0x20,arg1_00);
    *(**0xc0440924 + 0xfd) = 0;
    return;
}

// ----- END sitronix_ts_resume_work -----

// ----- BEGIN sitronix_ts_report_swu (T) [.kernel] file=0xc043ce48 runtime=0xc043ce48 -----

void sym.sitronix_ts_report_swu(int32_t arg1,int32_t arg2)

{
    uint uVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t *puVar4;
    int16_t *arg1_00;
    
    iVar2 = sym.sitronix_ts_get_swu_keycode(arg2);
    if (iVar2 == 0) {
        return;
    }
    sym.input_event(arg1,1,iVar2,1);
    sym.input_sync(arg1);
    sym.input_event(arg1,1,iVar2,0);
    iVar2 = sym.is_event_supported(0,arg1 + 0x18,0x1f);
    if (iVar2 != 0) {
        arg1_00 = arg1 + 0x18c;
        uVar1 = sym._raw_spin_lock_irqsave(arg1_00);
        sym.input_handle_event(arg1,0,0,0);
        DataMemoryBarrier(0xb);
        *arg1_00 = *arg1_00 + 1;
        sym.dsb_sev(arg1_00,uVar1);
        sym.preempt_count_sub(1);
        if ((&stack0xfffffff8 & 0xffffe000)[1] == 0) {
            uVar3 = *(&stack0xfffffff8 & 0xffffe000) >> 1;
        }
        else {
            uVar3 = 0;
        }
        if ((uVar3 & 1) != 0) {
            if (*((&stack0xfffffffc & 0xffffe000) + 4) != 0) {
                return;
            }
            puVar4 = &stack0xfffffff0 & 0xffffe000;
            do {
                puVar4[1] = puVar4[1] + 1;
                sym.preempt_latency_start(1);
                sym.__schedule(1);
                puVar4[1] = puVar4[1] - 1;
            } while ((*puVar4 & 2) != 0);
            return;
        }
        return;
    }
    return;
}

// ----- END sitronix_ts_report_swu -----

// ----- BEGIN sitronix_ts_report_palm (T) [.kernel] file=0xc043ce9c runtime=0xc043ce9c -----

void sym.sitronix_ts_report_palm(int32_t arg1)

{
    int iVar1;
    uint uVar2;
    uint32_t uVar3;
    uint32_t *puVar4;
    int16_t *arg1_00;
    
    sym.input_event(arg1,1,0x74,1);
    sym.input_sync(arg1);
    sym.input_event(arg1,1,0x74,0);
    iVar1 = sym.is_event_supported(0,arg1 + 0x18,0x1f);
    if (iVar1 == 0) {
        return;
    }
    arg1_00 = arg1 + 0x18c;
    uVar2 = sym._raw_spin_lock_irqsave(arg1_00);
    sym.input_handle_event(arg1,0,0,0);
    DataMemoryBarrier(0xb);
    *arg1_00 = *arg1_00 + 1;
    sym.dsb_sev(arg1_00,uVar2);
    sym.preempt_count_sub(1);
    if ((&stack0xfffffff8 & 0xffffe000)[1] == 0) {
        uVar3 = *(&stack0xfffffff8 & 0xffffe000) >> 1;
    }
    else {
        uVar3 = 0;
    }
    if ((uVar3 & 1) != 0) {
        if (*((&stack0xfffffffc & 0xffffe000) + 4) != 0) {
            return;
        }
        puVar4 = &stack0xfffffff0 & 0xffffe000;
        do {
            puVar4[1] = puVar4[1] + 1;
            sym.preempt_latency_start(1);
            sym.__schedule(1);
            puVar4[1] = puVar4[1] - 1;
        } while ((*puVar4 & 2) != 0);
        return;
    }
    return;
}

// ----- END sitronix_ts_report_palm -----

// ----- BEGIN sitronix_ts_report_proximity_demo (T) [.kernel] file=0xc043cedc runtime=0xc043cedc -----

//WARNING: Removing unreachable block (ram,0xc043f550)
//WARNING: Removing unreachable block (ram,0xc043f534)
//WARNING: Removing unreachable block (ram,0xc043f554)

uint sym.sitronix_ts_report_proximity_demo(uint noname_0,int32_t arg1)

{
    int iVar1;
    int *piVar2;
    uint in_r0;
    uint uVar3;
    int32_t arg2;
    int32_t arg2_00;
    int32_t arg2_01;
    uint uStack_14;
    uint uStack_10;
    int iStack_c;
    
    iVar1 = *0xc043cf78;
    if (arg1 != 3) {
        if (arg1 == 5) {
            sym.sitronix_write_driver_cmd(0x29,*(*0xc043cf78 + 4),0);
            sym.msleep(0x78,arg2_01);
            uVar3 = sym.sitronix_ts_powerdown(*(iVar1 + 8),0);
            *(*(iVar1 + 8) + 0x8c) = 0;
            return uVar3;
        }
        return in_r0;
    }
    sym.sitronix_write_driver_cmd(0x28,*(*0xc043cf78 + 4),0);
    sym.sitronix_write_driver_cmd(0x10,*(iVar1 + 4),0);
    sym.msleep(0x14,arg2);
    sym.sitronix_ts_powerdown(*(iVar1 + 8),1);
    sym.msleep(0x14,arg2_00);
    piVar2 = *0xc043f57c;
    iStack_c = **0xc043f57c;
    uStack_14 = 0;
    uStack_10 = 0;
    sym.sitronix_write_driver_cmd(0x11,&uStack_14,0);
    if (iStack_c == *piVar2) {
        return 0;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_report_proximity_demo -----

// ----- BEGIN sitronix_ts_report_proximity (T) [.kernel] file=0xc043cf7c runtime=0xc043cf7c -----

void sym.sitronix_ts_report_proximity(int32_t arg1,int32_t arg2)

{
    uint uVar1;
    uchar uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t *puVar5;
    int16_t *arg1_00;
    uint in_s0;
    
    if (arg2 == 3) {
        uVar2 = 1;
        iVar3 = *(*0xc043cfd8 + 8);
    }
    else {
        if (arg2 == 4) goto code_r0xc0438b90;
        if (arg2 != 5) {
            return;
        }
        uVar2 = 0;
        iVar3 = *(*0xc043cfd8 + 8);
    }
    *(iVar3 + 0x8e) = uVar2;
code_r0xc0438b90:
    sym.input_report_abs(in_s0,0x19,arg2);
    iVar3 = sym.is_event_supported(0,arg1 + 0x18,0x1f);
    if (iVar3 == 0) {
        return;
    }
    arg1_00 = arg1 + 0x18c;
    uVar1 = sym._raw_spin_lock_irqsave(arg1_00);
    sym.input_handle_event(arg1,0,0,0);
    DataMemoryBarrier(0xb);
    *arg1_00 = *arg1_00 + 1;
    sym.dsb_sev(arg1_00,uVar1);
    sym.preempt_count_sub(1);
    if ((&stack0xfffffff8 & 0xffffe000)[1] == 0) {
        uVar4 = *(&stack0xfffffff8 & 0xffffe000) >> 1;
    }
    else {
        uVar4 = 0;
    }
    if ((uVar4 & 1) != 0) {
        if (*((&stack0xfffffffc & 0xffffe000) + 4) != 0) {
            return;
        }
        puVar5 = &stack0xfffffff0 & 0xffffe000;
        do {
            puVar5[1] = puVar5[1] + 1;
            sym.preempt_latency_start(1);
            sym.__schedule(1);
            puVar5[1] = puVar5[1] - 1;
        } while ((*puVar5 & 2) != 0);
        return;
    }
    return;
}

// ----- END sitronix_ts_report_proximity -----

// ----- BEGIN sitronix_ts_irq_handler (t) [.kernel] file=0xc043cfdc runtime=0xc043cfdc -----

uint sym.sitronix_ts_irq_handler(int32_t arg1,int32_t arg2)

{
    uint8_t uVar1;
    uint8_t uVar2;
    uint8_t uVar3;
    uint8_t uVar4;
    int *piVar5;
    int iVar6;
    int iVar7;
    char cVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int32_t arg4;
    uint32_t uVar11;
    int iVar12;
    int32_t iVar13;
    bool bVar14;
    uint in_s0;
    uint extraout_s0;
    uint uVar15;
    uint extraout_s0_00;
    uint in_s1;
    uint16_t uStack_2e;
    int iStack_2c;
    
    piVar5 = *0xc043d418;
    iStack_2c = **0xc043d418;
    uVar1 = *(arg2 + 0x1e);
    uStack_2e = 0x5a;
    if (*(arg2 + 0x298) == 0x14) {
        *(arg2 + 0x2a8) = 1;
        sym.__wake_up(arg2 + 0x29c,1,1,0);
        goto code_r0xc043d028;
    }
    uVar2 = *(arg2 + 0x25);
    sym.sitronix_mt_pause_one(in_s0,in_s1,*(arg2 + 0x298));
    sym.mutex_lock(arg2 + 0x70U);
    if ((*(arg2 + 0x191) == '\0') || (*(arg2 + 0x8b) != '\0')) {
        uVar11 = uVar1 * 7 + 5 & 0xff;
        iVar7 = (**(*(arg2 + 0x10) + 0x18))(0x10,arg2 + 0x1c6U,uVar11,*(*(arg2 + 0x10) + 0x14));
        if (-1 < iVar7) {
            uVar15 = extraout_s0;
            if (*(arg2 + 0x1c6) < '\0') {
                sym.sitronix_ts_pen_allup(arg2);
                uVar15 = sym.sitronix_ts_reset_device(arg2);
            }
            if (*(arg2 + 0x2e0) != '\0') {
                uVar15 = sym.sitronix_ts_get_exdiff(arg2,arg2 + 0x2e8);
            }
            if ((((*(arg2 + 0x8a) == '\0') || (*(arg2 + 0x8b) == '\0')) || ((*(arg2 + 0x1c6) & 4) == 0)) ||
               (iVar7 = (**(*(arg2 + 0x10) + 0x18))(0x5a,arg2 + 0x216,uVar2 * 4 + 1,*(*(arg2 + 0x10) + 0x14)),
               uVar15 = extraout_s0_00, -1 < iVar7)) {
                if (*(arg2 + 0x8f) != '\0') {
                    uVar15 = sym.STChecksumCalculation(&uStack_2e,arg2 + 0x1c6U,4);
                    if ((*(arg2 + 0x1c6) & 8) != 0) {
                        uVar15 = sym.STChecksumCalculation(&uStack_2e,arg2 + 0x1ca,*(arg2 + 0x1e) * 7);
                    }
                    cVar8 = *(arg2 + uVar11 + 0x1c5);
                    if (((*(arg2 + 0x8a) != '\0') && (*(arg2 + 0x8b) != '\0')) && ((*(arg2 + 0x1c6) & 4) != 0)) {
                        uVar1 = *(arg2 + 0x216);
                        uVar11 = *(arg2 + 0x25);
                        bVar14 = (uVar1 & 1) != 0;
                        if (bVar14) {
                            uVar1 = *(arg2 + 0x24);
                        }
                        if (bVar14) {
                            uVar11 = uVar11 + uVar1;
                        }
                        iVar7 = uVar11 * 2 + 1;
                        uVar15 = sym.STChecksumCalculation(&uStack_2e,arg2 + 0x216,iVar7);
                        cVar8 = *(arg2 + iVar7 + 0x216);
                    }
                    bVar14 = cVar8 != uStack_2e;
                    uStack_2e = uStack_2e & 0xff;
                    if (bVar14) goto code_r0xc043d094;
                }
                if ((*(arg2 + 0x8a) != '\0') && (*(arg2 + 0x8b) != '\0')) {
                    uVar11 = *(arg2 + 0x1c6) << 0x19;
                    uVar9 = uVar11 >> 0x1d;
                    if ((uVar9 != 0) && (*(arg2 + 0x8c) != uVar9)) {
                        *(arg2 + 0x8c) = uVar11 >> 0x1d;
                        if (*(arg2 + 0x8d) != '\0') {
                            sym.sitronix_ts_report_proximity_demo(uVar15,uVar9);
                        }
                        sym.sitronix_ts_report_proximity(*(arg2 + 0xc),uVar9);
                    }
                }
                if (*(arg2 + 0x6c) == '\0') {
                    iVar12 = arg2 + 0x1d1;
                    cVar8 = '\0';
                    for (iVar7 = 0; iVar6 = *0xc043d41c, iVar7 < *(arg2 + 0x1e); iVar7 = iVar7 + 1) {
                        uVar1 = *(iVar12 + -7);
                        if ((uVar1 & 0x80) == 0) {
                            sym.sitronix_ts_pen_up(*(arg2 + 8),iVar7);
                        }
                        else {
                            uVar2 = *(iVar12 + -5);
                            uVar3 = *(iVar12 + -6);
                            iVar13 = *(arg2 + 8);
                            uVar4 = *(iVar12 + -4);
                            sym.input_event(iVar13,3,0x2f,iVar7);
                            uVar15 = sym.input_mt_report_slot_state(iVar13,0,1);
                            uVar15 = sym.input_report_abs(uVar15,0x35,uVar3 | (uVar1 & 0x3f) << 8);
                            uVar15 = sym.input_report_abs(uVar15,0x36,uVar4 | (uVar2 & 0x3f) << 8);
                            cVar8 = cVar8 + '\x01';
                            uVar15 = sym.input_report_abs(uVar15,0x30,1);
                            sym.input_report_abs(uVar15,0x3a,0xff);
                        }
                        iVar12 = iVar12 + 7;
                    }
                    sym.input_event(*(arg2 + 8),1,0x14a,cVar8 != '\0');
                    sym.input_sync(*(arg2 + 8));
                    iVar7 = *0xc043d420;
                    iVar13 = *(arg2 + 8);
                    uVar11 = 0;
                    uVar1 = *(arg2 + 0x1c9);
                    do {
                        uVar9 = 1 << (uVar11 & 0xff) & 0xff;
                        uVar10 = uVar9 & uVar1;
                        if ((uVar9 & *(iVar6 + 0xc)) == 0) {
                            if (uVar10 != 0) {
                                arg4 = 1;
code_r0xc043d3f8:
                                sym.input_event(iVar13,1,*(iVar7 + uVar11 * 4),arg4);
                                sym.input_sync(iVar13);
                            }
                        }
                        else {
                            arg4 = 0;
                            if (uVar10 == 0) goto code_r0xc043d3f8;
                        }
                        uVar11 = uVar11 + 1;
                    } while (uVar11 != 3);
                    *(iVar6 + 0xc) = uVar1;
                }
            }
        }
    }
    else {
        iVar7 = sym.sitronix_ts_get_swu_gesture(arg2);
        if ((-1 < iVar7) && (*(arg2 + 0x88) != 0)) {
            sym.sitronix_ts_report_swu(*(arg2 + 8),*(arg2 + 0x88));
        }
    }
code_r0xc043d094:
    if (*(arg2 + 0x298) == '\x15') {
        *(arg2 + 0x2a8) = 1;
        sym.__wake_up(arg2 + 0x29c,1,1,0);
    }
    sym.mutex_unlock(arg2 + 0x70U);
code_r0xc043d028:
    if (iStack_2c == *piVar5) {
        return 1;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_irq_handler -----

// ----- BEGIN sitronix_ts_reset_input_dev (T) [.kernel] file=0xc043d424 runtime=0xc043d424 -----

int sym.sitronix_ts_reset_input_dev(void)

{
    int iVar1;
    uint *puVar2;
    int iVar3;
    uint *puVar4;
    size_t n;
    int iVar5;
    uint noname_1;
    
    iVar5 = *0xc043d464;
    iVar3 = *(*0xc043d464 + 8);
    if (*(iVar3 + 8) != 0) {
        sym.sitronix_ts_get_device_info(iVar3);
        sym.input_unregister_device(*(*(iVar5 + 8) + 8));
        sym.input_free_device(*(*(iVar5 + 8) + 8));
        puVar4 = *(iVar5 + 8);
        puVar2 = sym.input_allocate_device();
        puVar4[2] = puVar2;
        iVar5 = *0xc043c650;
        if (puVar2 == NULL) {
            iVar5 = -0xc;
        }
        else {
            iVar3 = 0;
            *puVar2 = *puVar4;
            *(puVar4[2] + 0xc) = *puVar4[4];
            *(puVar4[2] + 0x10) = 0;
            *(puVar4[2] + 0x12) = 0;
            *(puVar4[2] + 0x1f8) = *(puVar4[1] + 0x58);
            *(puVar4[2] + 0x214) = puVar4;
            sym._set_bit(0,puVar4[2] + 0x18);
            sym._set_bit(1,puVar4[2] + 0x18);
            sym._set_bit(3,puVar4[2] + 0x18);
            sym._set_bit(0x14a,puVar4[2] + 0x1c);
            sym.input_set_capability(puVar4[2],1,0x74);
            sym.input_set_capability(puVar4[2],1,0x16);
            sym.input_set_capability(puVar4[2],1,0x67);
            sym.input_set_capability(puVar4[2],1,0x6c);
            sym.input_set_capability(puVar4[2],1,0x69);
            sym.input_set_capability(puVar4[2],1,0x6a);
            sym.input_set_capability(puVar4[2],1,0x18);
            sym.input_set_capability(puVar4[2],1,0x12);
            sym.input_set_capability(puVar4[2],1,0x32);
            sym.input_set_capability(puVar4[2],1,0x26);
            sym.input_set_capability(puVar4[2],1,0x11);
            sym.input_set_capability(puVar4[2],1,0x1f);
            sym.input_set_capability(puVar4[2],1,0x2f);
            sym.input_set_capability(puVar4[2],1,0x2c);
            sym.input_set_capability(puVar4[2],1,0x2e);
            sym._set_bit(0x74,puVar4[2] + 0x1c);
            sym._set_bit(0x6a,puVar4[2] + 0x1c);
            sym._set_bit(0x69,puVar4[2] + 0x1c);
            sym._set_bit(0x67,puVar4[2] + 0x1c);
            sym._set_bit(0x6c,puVar4[2] + 0x1c);
            sym._set_bit(0x16,puVar4[2] + 0x1c);
            sym._set_bit(0x18,puVar4[2] + 0x1c);
            sym._set_bit(0x12,puVar4[2] + 0x1c);
            sym._set_bit(0x32,puVar4[2] + 0x1c);
            sym._set_bit(0x11,puVar4[2] + 0x1c);
            sym._set_bit(0x26,puVar4[2] + 0x1c);
            sym._set_bit(0x1f,puVar4[2] + 0x1c);
            sym._set_bit(0x2f,puVar4[2] + 0x1c);
            sym._set_bit(0x2c,puVar4[2] + 0x1c);
            sym._set_bit(0x2e,puVar4[2] + 0x1c);
            sym.input_mt_init_slots(puVar4[2],*(puVar4 + 0x1e),2);
            sym._set_bit(1,puVar4[2] + 0x14);
            sym.input_set_abs_params(puVar4[2],0x30,0,0xff);
            sym.input_set_abs_params(puVar4[2],0x3a,0,0xff);
            sym.input_set_abs_params(puVar4[2],0x39,0,*(puVar4 + 0x1e));
            sym.input_set_abs_params(puVar4[2],0x35,0,*(puVar4 + 8) - 1);
            sym.input_set_abs_params(puVar4[2],0x36,0,*(puVar4 + 0x22) - 1);
            sym._set_bit(1,puVar4[2] + 0x18);
            do {
                iVar1 = iVar3 * 4;
                iVar3 = iVar3 + 1;
                sym._set_bit(*(iVar5 + iVar1),puVar4[2] + 0x1c);
            } while (iVar3 != 3);
            iVar5 = sym.input_register_device(puVar4[2],noname_1,n);
            if (iVar5 != 0) {
                sym.input_free_device(puVar4[2]);
                puVar4[2] = 0;
            }
        }
        return iVar5;
    }
    return iVar3;
}

// ----- END sitronix_ts_reset_input_dev -----

// ----- BEGIN sitronix_ts_i2c_dev_release (t) [.kernel] file=0xc043d468 runtime=0xc043d468 -----

void sym.sitronix_ts_i2c_dev_release(void)

{
    return;
}

// ----- END sitronix_ts_i2c_dev_release -----

// ----- BEGIN sitronix_ts_i2c_init (T) [.kernel] file=0xc043d46c runtime=0xc043d46c -----

int sym.sitronix_ts_i2c_init(void)

{
    int arg2;
    uint uVar1;
    int iVar2;
    
    uVar1 = *0xc044fa04;
    arg2 = *0xc043d478;
    if (**0xc044f9fc == '\0') {
        iVar2 = -0xb;
        sym.warn_slowpath_fmt(*0xc044fa00,0x6ae,9,NULL);
    }
    else {
        *(*0xc043d478 + 0x28) = 0;
        *(arg2 + 0x24) = uVar1;
        *(arg2 + 0x9c) = arg2 + 0x9c;
        *(arg2 + 0xa0) = arg2 + 0x9c;
        iVar2 = sym.driver_register(arg2 + 0x20,arg2);
        if (iVar2 == 0) {
            sym.i2c_for_each_dev(arg2,*0xc044fa08);
        }
    }
    return iVar2;
}

// ----- END sitronix_ts_i2c_init -----

// ----- BEGIN sitronix_ts_i2c_remove (t) [.kernel] file=0xc043d47c runtime=0xc043d47c -----

uint sym.sitronix_ts_i2c_remove(void)

{
    int iVar1;
    
    iVar1 = *(*0xc043d4c0 + 0x118);
    if (iVar1 != 0) {
        if (*(iVar1 + 4) < 0x1a0) {
            sym.gpio_free(*(iVar1 + 4));
        }
        if (*(iVar1 + 0xc) < 0x1a0) {
            sym.gpio_free(*(iVar1 + 0xc));
        }
        sym.platform_device_unregister(*0xc043d4c4);
    }
    return 0;
}

// ----- END sitronix_ts_i2c_remove -----

// ----- BEGIN sitronix_ts_i2c_awrite (t) [.kernel] file=0xc043d4c8 runtime=0xc043d4c8 -----

int32_t sym.sitronix_ts_i2c_awrite(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int *piVar1;
    int iVar2;
    ulong uVar3;
    ushort uStack_20;
    ushort uStack_1e;
    int16_t iStack_1c;
    int32_t iStack_18;
    int iStack_14;
    
    piVar1 = *0xc043d548;
    iVar2 = *arg3;
    iStack_1c = arg2 + 1;
    iStack_14 = **0xc043d548;
    uStack_20 = 0x28;
    *arg1 = 0;
    uStack_1e = 0;
    iStack_18 = arg1;
    uVar3 = sym.i2c_transfer(*(iVar2 + 0x18),&uStack_20,1);
    if (uVar3 != 1) {
        sym.msleep(0x14,uVar3 >> 0x20);
        arg2 = -5;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg2;
}

// ----- END sitronix_ts_i2c_awrite -----

// ----- BEGIN sitronix_ts_i2c_aread (t) [.kernel] file=0xc043d54c runtime=0xc043d54c -----

uint sym.sitronix_ts_i2c_aread(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    int *piVar1;
    int iVar2;
    ulong uVar3;
    int *in_stack_00000000;
    ushort uStack_2c;
    ushort uStack_2a;
    int16_t iStack_28;
    int32_t iStack_24;
    ushort uStack_20;
    ushort uStack_1e;
    ushort uStack_1c;
    int32_t iStack_18;
    int iStack_14;
    
    piVar1 = *0xc043d5ec;
    uStack_2a = 0;
    iStack_28 = arg2 + 1;
    iStack_14 = **0xc043d5ec;
    uStack_1c = arg4;
    iVar2 = *in_stack_00000000;
    *arg1 = ~(~(arg2 - 1U) & 0x5f);
    uStack_2c = 0x28;
    uStack_20 = 0x28;
    uStack_1e = 1;
    iStack_24 = arg1;
    iStack_18 = arg3;
    uVar3 = sym.i2c_transfer(*(iVar2 + 0x18),&uStack_2c,2);
    if (uVar3 != 2) {
        sym.msleep(0x14,uVar3 >> 0x20);
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return 0;
}

// ----- END sitronix_ts_i2c_aread -----

// ----- BEGIN sitronix_ts_i2c_dwrite (t) [.kernel] file=0xc043d5f0 runtime=0xc043d5f0 -----

int32_t sym.sitronix_ts_i2c_dwrite(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int *piVar1;
    ulong uVar2;
    ushort uStack_20;
    ushort uStack_1e;
    ushort uStack_1c;
    int32_t iStack_18;
    int iStack_14;
    
    piVar1 = *0xc043d668;
    iStack_14 = **0xc043d668;
    uStack_20 = *(*arg3 + 2);
    uStack_1c = arg2;
    uStack_1e = 0;
    iStack_18 = arg1;
    uVar2 = sym.i2c_transfer(*(*arg3 + 0x18),&uStack_20,1);
    if (uVar2 != 1) {
        sym.msleep(0x14,uVar2 >> 0x20);
        arg2 = -5;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg2;
}

// ----- END sitronix_ts_i2c_dwrite -----

// ----- BEGIN sitronix_ts_i2c_dread (t) [.kernel] file=0xc043d66c runtime=0xc043d66c -----

int32_t sym.sitronix_ts_i2c_dread(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int *piVar1;
    ulong uVar2;
    ushort uStack_20;
    ushort uStack_1e;
    ushort uStack_1c;
    int32_t iStack_18;
    int iStack_14;
    
    piVar1 = *0xc043d6e0;
    iStack_14 = **0xc043d6e0;
    uStack_20 = *(*arg3 + 2);
    uStack_1c = arg2;
    uStack_1e = 1;
    iStack_18 = arg1;
    uVar2 = sym.i2c_transfer(*(*arg3 + 0x18),&uStack_20,1);
    if (uVar2 != 1) {
        sym.msleep(0x14,uVar2 >> 0x20);
        arg2 = -5;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg2;
}

// ----- END sitronix_ts_i2c_dread -----

// ----- BEGIN sitronix_ts_i2c_read (t) [.kernel] file=0xc043d6e4 runtime=0xc043d6e4 -----

int32_t sym.sitronix_ts_i2c_read(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    int *piVar1;
    int iVar2;
    ulong uVar3;
    ushort uStack_30;
    ushort uStack_2e;
    ushort uStack_2c;
    uchar *puStack_28;
    ushort uStack_24;
    ushort uStack_22;
    ushort uStack_20;
    int32_t iStack_1c;
    uchar uStack_16;
    uchar uStack_15;
    int iStack_14;
    
    piVar1 = *0xc043d784;
    iVar2 = *arg4;
    puStack_28 = &uStack_16;
    iStack_14 = **0xc043d784;
    uStack_30 = *(iVar2 + 2);
    uStack_2e = 0;
    uStack_2c = 2;
    uStack_24 = *(iVar2 + 2);
    uStack_15 = arg1;
    uStack_16 = arg1 >> 8;
    uStack_20 = arg3;
    uStack_22 = 1;
    iStack_1c = arg2;
    uVar3 = sym.i2c_transfer(*(iVar2 + 0x18),&uStack_30,2);
    if (uVar3 != 2) {
        sym.msleep(0x14,uVar3 >> 0x20);
        arg3 = -5;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg3;
}

// ----- END sitronix_ts_i2c_read -----

// ----- BEGIN sitronix_ts_i2c_exit (T) [.kernel] file=0xc043d788 runtime=0xc043d788 -----

void sym.sitronix_ts_i2c_exit(void)

{
    int *piVar1;
    char *pcVar2;
    int32_t arg1;
    uint32_t uVar3;
    int iVar4;
    uint32_t *puVar5;
    code *pcVar6;
    uint32_t *arg1_00;
    uint32_t *puVar7;
    uint *puVar8;
    
    iVar4 = *0xc043d790;
    sym.i2c_for_each_dev(*0xc043d790,*0xc044fa28);
    pcVar2 = *0xc03aa244;
    piVar1 = *0xc0119460;
    uVar3 = iVar4 + 0x20;
    if ((uVar3 == 0) || (*(iVar4 + 0x68) == 0)) {
        iVar4 = **0xc0119460;
        sym.printk(*0xc0119464,0xc1,9);
        sym.__warn(pcVar2,0xc1);
        if (iVar4 != *piVar1) {
    //WARNING: Subroutine does not return
            sym.__stack_chk_fail();
        }
        return;
    }
    sym.driver_remove_groups(uVar3);
    if (*(iVar4 + 0x24) == 0) {
        return;
    }
    if (*(iVar4 + 0x30) == '\0') {
        sym.driver_remove_file(uVar3);
        sym.driver_remove_file(uVar3);
    }
    sym.driver_remove_groups(uVar3);
    sym.driver_remove_file(uVar3);
    sym.klist_remove(*(iVar4 + 0x68) + 0x5c);
    sym.driver_detach(uVar3);
    sym.module_remove_driver(uVar3);
    sym.kobject_put(*(iVar4 + 0x68));
    arg1 = *0xc064e6c8;
    pcVar2 = *0xc064e6c4;
    if (*(iVar4 + 0x24) != 0) {
        arg1_00 = *(*(iVar4 + 0x24) + 0x50) + 0x10;
        while( true ) {
            if (arg1_00 == NULL) {
                return;
            }
            if ((arg1_00[8] & 1) == 0) {
                sym.warn_slowpath_fmt(arg1,0x2ef,9,pcVar2);
            }
            iVar4 = sym.refcount_dec_and_test_checked(arg1_00 + 7);
            if (iVar4 == 0) break;
            puVar7 = arg1_00[3];
            puVar8 = arg1_00[5];
            uVar3 = *arg1_00;
            if ((arg1_00[8] & 0xc) == 4) {
                sym.kobject_uevent(arg1_00,1);
            }
            puVar5 = arg1_00[8] & 2;
            if ((arg1_00[8] & 2) != 0) {
                sym.__kobject_del(arg1_00);
                puVar5 = puVar7;
            }
            if ((puVar8 != NULL) && (pcVar6 = *puVar8, pcVar6 != NULL)) {
                (*pcVar6)(arg1_00);
            }
            arg1_00 = puVar5;
            if (uVar3 != 0) {
                sym.kfree_const(uVar3);
            }
        }
        return;
    }
    return;
}

// ----- END sitronix_ts_i2c_exit -----

// ----- BEGIN sitronix_ts_i2c_probe (t) [.kernel] file=0xc043d794 runtime=0xc043d794 -----

uint sym.sitronix_ts_i2c_probe(int32_t arg1)

{
    int32_t *piVar1;
    uint32_t uVar2;
    int32_t iVar3;
    int iVar4;
    uint uVar5;
    int iVar6;
    
    uVar2 = (**(*(*(arg1 + 0x18) + 8) + 0x10))();
    iVar4 = *0xc043d848;
    if ((uVar2 & 1) != 0) {
        iVar6 = *(arg1 + 0x21c);
        if (iVar6 != 0) {
            iVar3 = sym.of_get_named_gpio_flags(iVar6,*0xc043d84c,0,*0xc043d848 + 0x358);
            *(iVar4 + 0x354) = iVar3;
            if (-1 < iVar3) {
                sym.gpio_request(iVar3,*0xc043d850);
            }
            iVar3 = sym.of_get_named_gpio_flags(iVar6,*0xc043d858,0,*0xc043d854);
            *(iVar4 + 0x35c) = iVar3;
            if (-1 < iVar3) {
                sym.gpio_request(iVar3,*0xc043d85c);
            }
        }
        piVar1 = *0xc043d864;
        iVar6 = *0xc043d860;
        *(iVar4 + 0x118) = *0xc043d860;
        *piVar1 = arg1;
        *(iVar4 + 0x100) = arg1 + 0x20;
        iVar4 = sym.platform_device_register(iVar6 + -0x2a8);
        uVar5 = 0;
        if (iVar4 != 0) {
            uVar5 = 0xffffffed;
        }
        return uVar5;
    }
    return 0xfffffffb;
}

// ----- END sitronix_ts_i2c_probe -----

// ----- BEGIN sitronix_ts_i2c_write (t) [.kernel] file=0xc043d868 runtime=0xc043d868 -----

int32_t sym.sitronix_ts_i2c_write(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    int *piVar1;
    uchar *arg1_00;
    int iVar2;
    ulong uVar3;
    uint32_t uStack_30;
    uint32_t uStack_2c;
    uchar *puStack_28;
    int iStack_24;
    
    piVar1 = *0xc043d92c;
    iVar2 = *arg4;
    iStack_24 = **0xc043d92c;
    puStack_28 = NULL;
    uStack_2c = arg3 + 2U & 0xffff;
    uStack_30 = *(iVar2 + 2);
    arg1_00 = sym.__kmalloc(arg3 + 2U,0xdc0);
    if (arg1_00 == NULL) {
        arg3 = -0xc;
    }
    else {
        *arg1_00 = arg1 >> 8;
        arg1_00[1] = arg1;
        puStack_28 = arg1_00;
        sym.memcpy(arg1_00 + 2,arg2,arg3);
        uVar3 = sym.i2c_transfer(*(iVar2 + 0x18),&uStack_30,1);
        if (uVar3 != 1) {
            arg3 = -5;
            sym.msleep(8,uVar3 >> 0x20);
        }
        sym.kfree(arg1_00);
    }
    if (iStack_24 == *piVar1) {
        return arg3;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_i2c_write -----

// ----- BEGIN sitronix_ts_reg_read (t) [.kernel] file=0xc043d930 runtime=0xc043d930 -----

void sym.sitronix_ts_reg_read(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    //WARNING: Could not recover jumptable at 0xc043d958. Too many branches
    //WARNING: Treating indirect jump as call
    (**(*(arg1 + 0x10) + 0x18))(arg2,arg3,arg4,*(*(arg1 + 0x10) + 0x14));
    return;
}

// ----- END sitronix_ts_reg_read -----

// ----- BEGIN sitronix_ts_reg_write (t) [.kernel] file=0xc043d95c runtime=0xc043d95c -----

void sym.sitronix_ts_reg_write(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    //WARNING: Could not recover jumptable at 0xc043d984. Too many branches
    //WARNING: Treating indirect jump as call
    (**(*(arg1 + 0x10) + 0x1c))(arg2,arg3,arg4,*(*(arg1 + 0x10) + 0x14));
    return;
}

// ----- END sitronix_ts_reg_write -----

// ----- BEGIN sitronix_ts_addrmode_write (t) [.kernel] file=0xc043d988 runtime=0xc043d988 -----

void sym.sitronix_ts_addrmode_write(int32_t arg1,int32_t arg2,int32_t arg3)

{
    //WARNING: Could not recover jumptable at 0xc043d9ac. Too many branches
    //WARNING: Treating indirect jump as call
    (**(*(arg1 + 0x10) + 0x2c))(arg2,arg3,*(*(arg1 + 0x10) + 0x14));
    return;
}

// ----- END sitronix_ts_addrmode_write -----

// ----- BEGIN sitronix_ts_get_device_status (T) [.kernel] file=0xc043d9c4 runtime=0xc043d9c4 -----

uint32_t sym.sitronix_ts_get_device_status(int32_t arg1)

{
    int *piVar1;
    uint32_t uVar2;
    uint32_t in_r1;
    uint32_t auStack_14 [2];
    int iStack_c;
    
    piVar1 = *0xc043da0c;
    iStack_c = **0xc043da0c;
    auStack_14[0] = in_r1;
    uVar2 = sym.sitronix_ts_reg_read(arg1,1,auStack_14,8);
    if (-1 < uVar2) {
        uVar2 = auStack_14[0] & 0xf;
    }
    if (iStack_c == *piVar1) {
        return uVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_get_device_status -----

// ----- BEGIN sitronix_ts_get_fw_revision (T) [.kernel] file=0xc043da10 runtime=0xc043da10 -----

int sym.sitronix_ts_get_fw_revision(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    int32_t iStack_18;
    int iStack_14;
    
    piVar1 = *0xc043da84;
    iStack_14 = **0xc043da84;
    iStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0,&iStack_18,1);
    if (-1 < iVar2) {
        *(arg1 + 0x15) = iStack_18;
        iVar2 = sym.sitronix_ts_reg_read(arg1,0xc,&iStack_18,4);
        if (-1 < iVar2) {
            iVar2 = 0;
            *(arg1 + 0x16) = iStack_18;
        }
    }
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_get_fw_revision -----

// ----- BEGIN sitronix_ts_get_max_touches (T) [.kernel] file=0xc043da88 runtime=0xc043da88 -----

int sym.sitronix_ts_get_max_touches(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043dad8;
    iStack_14 = **0xc043dad8;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,9,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        iVar2 = 0;
        *(arg1 + 0x1e) = uStack_18._3_1_;
    }
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_get_max_touches -----

// ----- BEGIN sitronix_ts_get_chip_id (T) [.kernel] file=0xc043dadc runtime=0xc043dadc -----

int sym.sitronix_ts_get_chip_id(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043db2c;
    iStack_14 = **0xc043db2c;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0xf4,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        iVar2 = 0;
        *(arg1 + 0x14) = uStack_18._3_1_;
    }
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_get_chip_id -----

// ----- BEGIN sitronix_ts_get_resolution (T) [.kernel] file=0xc043db30 runtime=0xc043db30 -----

int sym.sitronix_ts_get_resolution(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043dbac;
    iStack_14 = **0xc043dbac;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,5,&uStack_18,4);
    if (-1 < iVar2) {
        iVar2 = 0;
        *(arg1 + 0x20) = uStack_18._1_1_ | (uStack_18 & 0x3f) << 8;
        *(arg1 + 0x22) = uStack_18._3_1_ | (uStack_18._2_1_ & 0x3f) << 8;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar2;
}

// ----- END sitronix_ts_get_resolution -----

// ----- BEGIN sitronix_ts_get_customer_info (T) [.kernel] file=0xc043dbb0 runtime=0xc043dbb0 -----

int sym.sitronix_ts_get_customer_info(int32_t arg1)

{
    int *piVar1;
    uchar uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043dc54;
    iStack_14 = **0xc043dc54;
    uStack_18 = arg1;
    iVar4 = sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_18,1);
    if (-1 < iVar4) {
        uVar2 = uStack_18;
        uStack_18 = uStack_18 & 0xfffffffc | 1;
        sym.sitronix_ts_reg_write(arg1,0xf1,&uStack_18,1);
        sym.sitronix_ts_reg_read(arg1,0xc,&uStack_18,4);
        uVar3 = uStack_18;
        uStack_18 = CONCAT31(uStack_18._1_3_,uVar2);
        *(arg1 + 0x1a) = uVar3;
        sym.sitronix_ts_reg_write(arg1,0xf1,&uStack_18,1);
        iVar4 = 0;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar4;
}

// ----- END sitronix_ts_get_customer_info -----

// ----- BEGIN sitronix_ts_get_misc_info (T) [.kernel] file=0xc043dc58 runtime=0xc043dc58 -----

int sym.sitronix_ts_get_misc_info(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043dcd0;
    *(arg1 + 400) = 0;
    *(arg1 + 0x8a) = 0;
    iStack_14 = *piVar1;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0xf0,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        iVar2 = 0;
        *(arg1 + 0x8a) = 0;
        *(arg1 + 0x28) = uStack_18._3_1_;
        *(arg1 + 400) = uStack_18._3_1_ >> 7;
        *(arg1 + 0x193) = uStack_18._3_1_ >> 7;
        *(arg1 + 0x8f) = (uStack_18._3_1_ << 0x1b) >> 0x1f;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar2;
}

// ----- END sitronix_ts_get_misc_info -----

// ----- BEGIN sitronix_ts_set_smart_wake_up (T) [.kernel] file=0xc043dcd4 runtime=0xc043dcd4 -----

int sym.sitronix_ts_set_smart_wake_up(int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    uint8_t uVar3;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043dd6c;
    iStack_14 = **0xc043dd6c;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        if (arg2 == 0) {
            uVar3 = uStack_18 >> 0x18 & 0x7f;
        }
        else {
            uVar3 = ~(~(((uStack_18 >> 0x18) << 0x19) >> 0x18) >> 1);
        }
        uStack_18 = CONCAT13(uVar3,uStack_18);
        iVar2 = sym.sitronix_ts_reg_write(arg1,0xf1,&uStack_18 + 3,1);
        if (-1 < iVar2) {
            sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_18 + 3,1);
            iVar2 = 0;
        }
    }
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_set_smart_wake_up -----

// ----- BEGIN sitronix_ts_get_swu_keycode (T) [.kernel] file=0xc043dd70 runtime=0xc043dd70 -----

int sym.sitronix_ts_get_swu_keycode(int32_t arg1)

{
    uint32_t uVar1;
    int iVar2;
    
    uVar1 = arg1 - 99U & 0xff;
    if (uVar1 < 0x66) {
        iVar2 = *(*0xc043dd8c + uVar1);
    }
    else {
        iVar2 = 0;
    }
    return iVar2;
}

// ----- END sitronix_ts_get_swu_keycode -----

// ----- BEGIN sitronix_ts_powerdown (T) [.kernel] file=0xc043dd90 runtime=0xc043dd90 -----

uint32_t sym.sitronix_ts_powerdown(int32_t arg1,int32_t arg2)

{
    int *piVar1;
    uint32_t uVar2;
    uint8_t uVar3;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043de08;
    iStack_14 = **0xc043de08;
    uStack_18 = arg1;
    uVar2 = sym.sitronix_ts_reg_read(arg1,2,&uStack_18 + 3,1);
    if (-1 < uVar2) {
        if (arg2 == 0) {
            uVar3 = uStack_18._3_1_ & 0xfd;
        }
        else {
            uVar3 = uStack_18._3_1_ | 2;
        }
        uStack_18 = CONCAT13(uVar3,uStack_18);
        uVar2 = sym.sitronix_ts_reg_write(arg1,2,&uStack_18 + 3,1);
        uVar2 = uVar2 & uVar2 >> 0x1f;
    }
    if (iStack_14 == *piVar1) {
        return uVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_powerdown -----

// ----- BEGIN sitronix_ts_proximity_enable (T) [.kernel] file=0xc043de0c runtime=0xc043de0c -----

int sym.sitronix_ts_proximity_enable(int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    uint8_t uVar3;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc043de94;
    iStack_14 = **0xc043de94;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,2,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        if (arg2 == 0) {
            uVar3 = uStack_18._3_1_ & 0xdf;
        }
        else {
            uVar3 = uStack_18._3_1_ | 0x20;
        }
        uStack_18 = CONCAT13(uVar3,uStack_18);
        iVar2 = sym.sitronix_ts_reg_write(arg1,2,&uStack_18 + 3,1);
        if (-1 < iVar2) {
            iVar2 = 0;
            *(**0xc043de98 + 0x8b) = arg2;
        }
    }
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_proximity_enable -----

// ----- BEGIN sitronix_ts_get_swu_gesture (T) [.kernel] file=0xc043dee8 runtime=0xc043dee8 -----

int sym.sitronix_ts_get_swu_gesture(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uchar auStack_16 [2];
    int iStack_14;
    
    piVar1 = *0xc043df94;
    iStack_14 = **0xc043df94;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0x10,arg1 + 0x1c6U,*(arg1 + 0x2a) * 7 + 5);
    if (-1 < iVar2) {
        if (*(arg1 + 0x8f) != '\0') {
            sym.STChecksumCalculation(auStack_16,arg1 + 0x1c6U,4);
            if (*(arg1 + 0x2a) != 0) {
                sym.STChecksumCalculation(auStack_16,arg1 + 0x1ca,*(arg1 + 0x2a) * 7);
            }
        }
        iVar2 = 0;
        *(arg1 + 0x88) = *(arg1 + 0x1c8);
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar2;
}

// ----- END sitronix_ts_get_swu_gesture -----

// ----- BEGIN sitronix_ts_get_xy_chs (T) [.kernel] file=0xc043ea38 runtime=0xc043ea38 -----

uint sym.sitronix_ts_get_xy_chs(int32_t arg1)

{
    int *piVar1;
    uchar auStack_26 [2];
    uchar uStack_24;
    uchar uStack_23;
    uchar uStack_22;
    uint8_t uStack_21;
    uchar uStack_19;
    int iStack_14;
    
    piVar1 = *0xc043eaac;
    iStack_14 = **0xc043eaac;
    sym.TDU_FWInfoRead(2,auStack_26,0x12);
    *(arg1 + 0x24) = uStack_24;
    *(arg1 + 0x25) = uStack_23;
    *(arg1 + 0x26) = uStack_22;
    *(arg1 + 0x27) = (uStack_21 << 0x19) >> 0x1c;
    *(arg1 + 0x2a) = uStack_19;
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return 0;
}

// ----- END sitronix_ts_get_xy_chs -----

// ----- BEGIN sitronix_ts_get_device_info (T) [.kernel] file=0xc043eab0 runtime=0xc043eab0 -----

int sym.sitronix_ts_get_device_info(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_18;
    int iStack_14;
    
    iVar2 = sym.sitronix_ts_get_fw_revision(arg1);
    if (iVar2 != 0) {
        return iVar2;
    }
    iVar2 = sym.sitronix_ts_get_customer_info(arg1);
    if (iVar2 != 0) {
        return iVar2;
    }
    iVar2 = sym.sitronix_ts_get_resolution(arg1);
    if (iVar2 != 0) {
        return iVar2;
    }
    iVar2 = sym.sitronix_ts_get_max_touches(arg1);
    if (iVar2 != 0) {
        return iVar2;
    }
    iVar2 = sym.sitronix_ts_get_chip_id(arg1);
    if (iVar2 != 0) {
        return iVar2;
    }
    iVar2 = sym.sitronix_ts_get_xy_chs(arg1);
    piVar1 = *0xc043dcd0;
    if (iVar2 != 0) {
        return iVar2;
    }
    *(arg1 + 400) = 0;
    *(arg1 + 0x8a) = 0;
    iStack_14 = *piVar1;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0xf0,&uStack_18 + 3,1);
    if (-1 < iVar2) {
        iVar2 = 0;
        *(arg1 + 0x8a) = 0;
        *(arg1 + 0x28) = uStack_18._3_1_;
        *(arg1 + 400) = uStack_18._3_1_ >> 7;
        *(arg1 + 0x193) = uStack_18._3_1_ >> 7;
        *(arg1 + 0x8f) = (uStack_18._3_1_ << 0x1b) >> 0x1f;
    }
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar2;
}

// ----- END sitronix_ts_get_device_info -----

// ----- BEGIN sitronix_mode_switch_value (T) [.kernel] file=0xc043ec20 runtime=0xc043ec20 -----

int sym.sitronix_mode_switch_value(int32_t arg1,int32_t arg2,int32_t arg3)

{
    uchar uVar1;
    int *piVar2;
    int iVar3;
    uint8_t uVar4;
    ulong uVar5;
    uint uStack_20;
    int iStack_1c;
    int32_t iStack_18;
    
    piVar2 = *0xc043ecf4;
    iStack_1c = **0xc043ecf4;
    uStack_20 = arg1;
    iStack_18 = arg3;
    if (arg1 < 9) {
        uVar1 = arg2;
        if (arg1 == 1) {
            iVar3 = **0xc043ecf8;
            *(iVar3 + 400) = uVar1;
            *(iVar3 + 0x193) = uVar1;
        }
        else {
            if (arg2 == 0) {
                uVar4 = 0;
            }
            else {
                uVar4 = 0x80;
            }
            uStack_20._3_1_ = arg1 >> 0x18;
            uStack_20._0_3_ = CONCAT12(uVar4 | arg3,arg1);
            uVar5 = sym.TDU_FWControlWrite(arg1,&uStack_20 + 2,1);
            iVar3 = uVar5;
            if (iVar3 < 0) goto code_r0xc043ec3c;
            sym.msleep(10,uVar5 >> 0x20);
            iVar3 = sym.TDU_FWControlRead(arg1,&uStack_20 + 3,1);
            if (iVar3 < 0) goto code_r0xc043ec3c;
            if (uStack_20._3_1_ != uStack_20._2_1_) goto code_r0xc043ec38;
            iVar3 = **0xc043ecf8;
            *(iVar3 + arg1 + 0x192) = uVar1;
            *(iVar3 + arg1 + 0x1a6) = arg3;
        }
        iVar3 = 0;
    }
    else {
code_r0xc043ec38:
        iVar3 = -0x16;
    }
code_r0xc043ec3c:
    if (iStack_1c == *piVar2) {
        return iVar3;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_mode_switch_value -----

// ----- BEGIN sitronix_mode_switch (T) [.kernel] file=0xc043ecfc runtime=0xc043ecfc -----

int sym.sitronix_mode_switch(int32_t param_1,int param_2)

{
    uchar uVar1;
    int *piVar2;
    int iVar3;
    uchar uVar4;
    ulong uVar5;
    uint uStack_20;
    int iStack_1c;
    uint uStack_18;
    
    piVar2 = *0xc043ecf4;
    uStack_18 = 0;
    iStack_1c = **0xc043ecf4;
    uStack_20 = param_1;
    if (param_1 < 9) {
        uVar1 = param_2;
        if (param_1 == 1) {
            iVar3 = **0xc043ecf8;
            *(iVar3 + 400) = uVar1;
            *(iVar3 + 0x193) = uVar1;
        }
        else {
            if (param_2 == 0) {
                uVar4 = 0;
            }
            else {
                uVar4 = 0x80;
            }
            uStack_20._3_1_ = param_1 >> 0x18;
            uStack_20._0_3_ = CONCAT12(uVar4,param_1);
            uVar5 = sym.TDU_FWControlWrite(param_1,&uStack_20 + 2,1);
            iVar3 = uVar5;
            if (iVar3 < 0) goto code_r0xc043ec3c;
            sym.msleep(10,uVar5 >> 0x20);
            iVar3 = sym.TDU_FWControlRead(param_1,&uStack_20 + 3,1);
            if (iVar3 < 0) goto code_r0xc043ec3c;
            if (uStack_20._3_1_ != uStack_20._2_1_) goto code_r0xc043ec38;
            iVar3 = **0xc043ecf8;
            *(iVar3 + param_1 + 0x192) = uVar1;
            *(iVar3 + param_1 + 0x1a6) = 0;
        }
        iVar3 = 0;
    }
    else {
code_r0xc043ec38:
        iVar3 = -0x16;
    }
code_r0xc043ec3c:
    if (iStack_1c == *piVar2) {
        return iVar3;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_mode_switch -----

// ----- BEGIN sitronix_mode_backup (T) [.kernel] file=0xc043ed04 runtime=0xc043ed04 -----

void sym.sitronix_mode_backup(uint param_1)

{
    int *piVar1;
    int *piVar2;
    int iVar3;
    int arg1;
    uint uStack_18;
    int iStack_14;
    
    piVar2 = *0xc043ed78;
    piVar1 = *0xc043ed74;
    arg1 = 2;
    iStack_14 = **0xc043ed74;
    uStack_18 = param_1;
    do {
        sym.TDU_FWControlRead(arg1,&uStack_18 + 3,1);
        iVar3 = *piVar2 + arg1;
        arg1 = arg1 + 1;
        *(iVar3 + 0x192) = uStack_18._3_1_ >> 7;
        *(iVar3 + 0x1a6) = uStack_18._3_1_ & 0x7f;
    } while (arg1 != 8);
    if (iStack_14 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_mode_backup -----

// ----- BEGIN sitronix_swk_config_backup (T) [.kernel] file=0xc043ed7c runtime=0xc043ed7c -----

void sym.sitronix_swk_config_backup(void)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    
    piVar1 = *0xc043edd8;
    if (**0xc043edd8 != 0) {
        iVar2 = sym.TDU_Cmdio_ReadSWKConfig(0,**0xc043edd8 + 0x1ba,4);
        iVar3 = *piVar1;
        if (iVar2 < 0) {
            *(iVar3 + 0x1be) = 1;
            *(iVar3 + 0x1bf) = 0x8f;
            *(iVar3 + 0x1c0) = 0xff;
            *(iVar3 + 0x1c1) = 0xf;
        }
        else {
            *(iVar3 + 0x1be) = *(iVar3 + 0x1ba);
        }
        return;
    }
    return;
}

// ----- END sitronix_swk_config_backup -----

// ----- BEGIN sitronix_swk_config_restore (T) [.kernel] file=0xc043eddc runtime=0xc043eddc -----

//WARNING: Removing unreachable block (ram,0xc043e860)

uint sym.sitronix_swk_config_restore(uint param_1)

{
    int *piVar1;
    int32_t arg1;
    int iVar2;
    uint uVar3;
    uint noname_0;
    ushort uStack_3e;
    uchar uStack_3c;
    uint8_t auStack_3b [31];
    int iStack_1c;
    
    piVar1 = *0xc043e900;
    iVar2 = **0xc043ee00;
    if (iVar2 == 0) {
        return param_1;
    }
    iStack_1c = **0xc043e900;
    sym.memset(&uStack_3c,0,0x20);
    uVar3 = 4;
    auStack_3b[0] = 6;
    uStack_3c = 7;
    auStack_3b[1] = 0;
    sym.memcpy(auStack_3b + 2,iVar2 + 0x1ba,4);
    uStack_3e = 0;
    sym.STChecksumCalculation(&uStack_3e,&uStack_3c,7);
    auStack_3b[auStack_3b[0]] = uStack_3e;
    iVar2 = sym.TDU_WriteIOCommand(&uStack_3c);
    if (((iVar2 == 0) || (iVar2 = sym.TDU_SetH2DReady(), iVar2 == 0)) ||
       (iVar2 = sym.TDU_GetH2DReady(noname_0,arg1), iVar2 == 0)) {
        uVar3 = 0;
    }
    if (iStack_1c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return uVar3;
}

// ----- END sitronix_swk_config_restore -----

// ----- BEGIN sitronix_get_ic_position (T) [.kernel] file=0xc043ee04 runtime=0xc043ee04 -----

uint sym.sitronix_get_ic_position(int32_t arg1)

{
    int *piVar1;
    int32_t *piVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    uint uVar6;
    int iVar7;
    uint uStack_36;
    uint uStack_32;
    ushort uStack_2e;
    int iStack_2c;
    
    piVar2 = *0xc043f0a0;
    piVar1 = *0xc043f09c;
    iStack_2c = **0xc043f09c;
    uStack_2e = 0;
    uStack_36 = 0x23715300;
    uStack_32 = 0x3ca5;
    sym.sitronix_ts_addrmode_write(**0xc043f0a0,&uStack_36,5);
    uStack_36._0_2_ = CONCAT11(0x53,uStack_36);
    uStack_36 = CONCAT13(0x23,CONCAT12(0x71,uStack_36));
    uStack_32 = CONCAT22(uStack_32._2_2_,0x5514);
    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,5);
    uStack_36._0_2_ = CONCAT11(3,uStack_36);
    uStack_36._0_3_ = CONCAT12(6,uStack_36);
    uStack_36 = CONCAT13(0xfc,uStack_36);
    uStack_32._0_2_ = 0x9d5a;
    uStack_32._2_2_ = 0xbd;
    uStack_2e = 0;
    iVar5 = sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,9);
    if (-1 < iVar5) {
        uStack_36._0_2_ = CONCAT11(3,uStack_36);
        uStack_36._0_3_ = CONCAT12(6,uStack_36);
        uStack_36 = CONCAT13(0xfe,uStack_36);
        uStack_32._0_2_ = 0xa500;
        iVar5 = sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,5);
        if (-1 < iVar5) {
            uStack_36._0_2_ = CONCAT11(3,uStack_36);
            uStack_36._0_3_ = CONCAT12(6,uStack_36);
            uStack_36 = CONCAT13(0xfc,uStack_36);
            uStack_32._0_2_ = 0x9e5a;
            uStack_32._2_2_ = 0x6c;
            iVar5 = sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,7);
            piVar4 = *0xc043f0a8;
            piVar3 = *0xc043f0a4;
            if (-1 < iVar5) {
                *(**0xc043f0a4 + 1) = 0x83;
                *(*piVar3 + 2) = 7;
                *(*piVar3 + 3) = 4;
                iVar7 = (**(*(*piVar2 + 0x10) + 0x30))(*piVar3,3,*piVar4,6,*(*(*piVar2 + 0x10) + 0x14));
                if (iVar7 < 0) {
                    iVar5 = -1;
                }
                uStack_36._0_2_ = CONCAT11(3,uStack_36);
                uStack_36._0_3_ = CONCAT12(6,uStack_36);
                uStack_36 = CONCAT13(0xfe,uStack_36);
                uStack_32._0_2_ = 0xa500;
                sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,5);
                if (iVar5 != -1) {
                    uStack_36._0_2_ = CONCAT11(0x53,uStack_36);
                    *arg1 = *(*piVar4 + iVar7 + 4);
                    uStack_36._0_3_ = CONCAT12(0x71,uStack_36);
                    uStack_36 = CONCAT13(0x23,uStack_36);
                    uStack_32._0_2_ = 0x4c41;
                    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,5);
                    uStack_36._0_2_ = CONCAT11(0x53,uStack_36);
                    uStack_36._0_3_ = CONCAT12(0x71,uStack_36);
                    uStack_36 = CONCAT13(0x23,uStack_36);
                    uStack_32._0_2_ = 0xc35a;
                    uVar6 = sym.sitronix_ts_addrmode_write(*piVar2,&uStack_36,5);
                    goto code_r0xc043eef4;
                }
            }
        }
    }
    uVar6 = 0xffffffff;
code_r0xc043eef4:
    if (iStack_2c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return uVar6;
}

// ----- END sitronix_get_ic_position -----

// ----- BEGIN sitronix_get_chip_id (T) [.kernel] file=0xc043f0ac runtime=0xc043f0ac -----

uint32_t sym.sitronix_get_chip_id(void)

{
    int *piVar1;
    int32_t *piVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    uint32_t uVar6;
    uint uStack_2c;
    uint uStack_28;
    int iStack_24;
    
    piVar2 = *0xc043f1e0;
    piVar1 = *0xc043f1dc;
    iStack_24 = **0xc043f1dc;
    uStack_28 = 0x3ca5;
    uStack_2c = 0x23715300;
    sym.sitronix_ts_addrmode_write(**0xc043f1e0,&uStack_2c,5);
    uStack_28._0_2_ = 0x5514;
    uStack_2c._0_2_ = CONCAT11(0x53,uStack_2c);
    uStack_2c._0_3_ = CONCAT12(0x71,uStack_2c);
    uStack_2c = CONCAT13(0x23,uStack_2c);
    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_2c,5);
    uStack_28 = CONCAT22(uStack_28._2_2_,0x5555);
    uStack_2c._0_2_ = CONCAT11(0x53,uStack_2c);
    uStack_2c._0_3_ = CONCAT12(0x71,uStack_2c);
    uStack_2c = CONCAT13(0x23,uStack_2c);
    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_2c,5);
    piVar3 = *0xc043f1e4;
    *(**0xc043f1e4 + 1) = 0x81;
    *(*piVar3 + 2) = 1;
    *(*piVar3 + 3) = 0x1e;
    piVar4 = *0xc043f1e8;
    iVar5 = (**(*(*piVar2 + 0x10) + 0x28))(*piVar3,3,**0xc043f1e8,3,*(*(*piVar2 + 0x10) + 0x14));
    if (-1 < iVar5) {
        uVar6 = *piVar4 + iVar5;
    }
    else {
        uVar6 = 0xffffffff;
    }
    if (-1 < iVar5) {
        uVar6 = *(uVar6 + 1);
    }
    if (iStack_24 == *piVar1) {
        return uVar6;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_get_chip_id -----

// ----- BEGIN sitronix_get_ic_sfrver (T) [.kernel] file=0xc043f1ec runtime=0xc043f1ec -----

uint32_t sym.sitronix_get_ic_sfrver(void)

{
    int *piVar1;
    int32_t *piVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    uint32_t uVar6;
    uint uStack_2c;
    uint uStack_28;
    int iStack_24;
    
    piVar2 = *0xc043f320;
    piVar1 = *0xc043f31c;
    iStack_24 = **0xc043f31c;
    uStack_28 = 0x3ca5;
    uStack_2c = 0x23715300;
    sym.sitronix_ts_addrmode_write(**0xc043f320,&uStack_2c,5);
    uStack_28._0_2_ = 0x5514;
    uStack_2c._0_2_ = CONCAT11(0x53,uStack_2c);
    uStack_2c._0_3_ = CONCAT12(0x71,uStack_2c);
    uStack_2c = CONCAT13(0x23,uStack_2c);
    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_2c,5);
    uStack_28 = CONCAT22(uStack_28._2_2_,0x5555);
    uStack_2c._0_2_ = CONCAT11(0x53,uStack_2c);
    uStack_2c._0_3_ = CONCAT12(0x71,uStack_2c);
    uStack_2c = CONCAT13(0x23,uStack_2c);
    sym.sitronix_ts_addrmode_write(*piVar2,&uStack_2c,5);
    piVar3 = *0xc043f324;
    *(**0xc043f324 + 1) = 0x81;
    *(*piVar3 + 2) = 1;
    *(*piVar3 + 3) = 0xc2;
    piVar4 = *0xc043f328;
    iVar5 = (**(*(*piVar2 + 0x10) + 0x28))(*piVar3,3,**0xc043f328,3,*(*(*piVar2 + 0x10) + 0x14));
    if (-1 < iVar5) {
        uVar6 = *piVar4 + iVar5;
    }
    else {
        uVar6 = 0xffffffff;
    }
    if (-1 < iVar5) {
        uVar6 = *(uVar6 + 1);
    }
    if (iStack_24 == *piVar1) {
        return uVar6;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_get_ic_sfrver -----

// ----- BEGIN sitronix_write_driver_cmd (T) [.kernel] file=0xc043f32c runtime=0xc043f32c -----

uint sym.sitronix_write_driver_cmd(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int32_t *piVar1;
    size_t arg1_00;
    int32_t iVar2;
    int iVar3;
    uint32_t uVar4;
    uint uVar5;
    
    if (0x7a < arg3) {
        return 0xffffffff;
    }
    arg1_00 = sym.kmem_cache_alloc(*(*0xc043f518 + 0x1c),0xdc0);
    piVar1 = *0xc043f51c;
    if (arg1_00 == 0) {
        return 0xfffffff4;
    }
    *(arg1_00 + 4) = 0xa5;
    *(arg1_00 + 1) = 0x53;
    *(arg1_00 + 5) = 0x3c;
    *(arg1_00 + 2) = 0x71;
    *(arg1_00 + 3) = 0x23;
    sym.sitronix_ts_addrmode_write(*piVar1,arg1_00,5);
    *(arg1_00 + 4) = 0x14;
    *(arg1_00 + 1) = 0x53;
    *(arg1_00 + 5) = 0x55;
    *(arg1_00 + 2) = 0x71;
    *(arg1_00 + 3) = 0x23;
    sym.sitronix_ts_addrmode_write(*piVar1,arg1_00,5);
    *(arg1_00 + 1) = 3;
    iVar2 = *piVar1;
    *(arg1_00 + 2) = 6;
    *(arg1_00 + 3) = 0xfc;
    *(arg1_00 + 4) = 0x5a;
    *(arg1_00 + 5) = 0x9d;
    iVar3 = sym.sitronix_ts_addrmode_write(iVar2,arg1_00,5);
    if (-1 < iVar3) {
        uVar4 = arg3 & 1;
        if (arg3 < 0) {
            uVar4 = -uVar4;
        }
        *(arg1_00 + 4) = arg1;
        if (uVar4 == 1) {
            arg3 = arg3 + 1;
        }
        *(arg1_00 + 1) = 3;
        *(arg1_00 + 2) = 6;
        *(arg1_00 + 5) = 0;
        *(arg1_00 + 3) = 0xfe;
        sym.memcpy(arg1_00 + 6,arg2,arg3);
        iVar3 = sym.sitronix_ts_addrmode_write(*piVar1,arg1_00,arg3 + 5U & 0xffff);
        if (-1 < iVar3) {
            *(arg1_00 + 4) = 0;
            *(arg1_00 + 5) = 0xa5;
            iVar2 = *piVar1;
            *(arg1_00 + 1) = 3;
            *(arg1_00 + 2) = 6;
            *(arg1_00 + 3) = 0xfe;
            sym.sitronix_ts_addrmode_write(iVar2,arg1_00,5);
            *(arg1_00 + 4) = 0x41;
            iVar2 = *piVar1;
            *(arg1_00 + 5) = 0x4c;
            *(arg1_00 + 1) = 0x53;
            *(arg1_00 + 2) = 0x71;
            *(arg1_00 + 3) = 0x23;
            sym.sitronix_ts_addrmode_write(iVar2,arg1_00,5);
            iVar2 = *piVar1;
            *(arg1_00 + 4) = 0x5a;
            *(arg1_00 + 1) = 0x53;
            *(arg1_00 + 2) = 0x71;
            *(arg1_00 + 3) = 0x23;
            *(arg1_00 + 5) = 0xc3;
            uVar5 = sym.sitronix_ts_addrmode_write(iVar2,arg1_00,5);
            goto code_r0xc043f410;
        }
    }
    uVar5 = 0xffffffff;
code_r0xc043f410:
    sym.kfree(arg1_00);
    return uVar5;
}

// ----- END sitronix_write_driver_cmd -----

// ----- BEGIN sitronix_ts_proximity_control_sensing (T) [.kernel] file=0xc043f520 runtime=0xc043f520 -----

uint sym.sitronix_ts_proximity_control_sensing(int32_t arg1,int32_t arg2)

{
    uint *arg3;
    int *piVar1;
    int32_t arg1_00;
    uint *puVar2;
    uint *arg2_00;
    uint uStack_14;
    uint uStack_10;
    int iStack_c;
    
    piVar1 = *0xc043f57c;
    if (arg2 != 0) {
        puVar2 = &uStack_14;
        arg1_00 = 0x11;
    }
    else {
        arg1_00 = 0x10;
        puVar2 = NULL;
    }
    iStack_c = **0xc043f57c;
    uStack_14 = 0;
    uStack_10 = 0;
    arg2_00 = puVar2;
    arg3 = NULL;
    if (arg2 == 0) {
        arg2_00 = &uStack_14;
        arg3 = puVar2;
    }
    sym.sitronix_write_driver_cmd(arg1_00,arg2_00,arg3);
    if (iStack_c == *piVar1) {
        return 0;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_proximity_control_sensing -----

// ----- BEGIN sitronix_read_driver_cmd (T) [.kernel] file=0xc043f580 runtime=0xc043f580 -----

uint sym.sitronix_read_driver_cmd(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int32_t *piVar1;
    int *piVar2;
    uint uVar3;
    int iVar4;
    uchar uStack_4c;
    uchar uStack_4b;
    uchar uStack_4a;
    uchar uStack_49;
    uchar uStack_48;
    uchar uStack_47;
    uchar uStack_46;
    uchar uStack_45;
    uchar uStack_44;
    uchar uStack_43;
    int iStack_2c;
    
    iStack_2c = **0xc043f848;
    sym.memset(&uStack_4c,0,0x20);
    piVar1 = *0xc043f84c;
    if (arg3 < 0x1b) {
        uStack_4b = 0x53;
        uStack_49 = 0x23;
        uStack_4a = 0x71;
        uStack_48 = 0xa5;
        uStack_47 = 0x3c;
        sym.sitronix_ts_addrmode_write(**0xc043f84c,&uStack_4c,5);
        uStack_4b = 0x53;
        uStack_49 = 0x23;
        uStack_4a = 0x71;
        uStack_48 = 0x14;
        uStack_47 = 0x55;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
        uStack_49 = 0xfc;
        uStack_4b = 3;
        uStack_4a = 6;
        uStack_47 = 0x9d;
        uStack_48 = 0x5a;
        uStack_46 = 0xbd;
        uStack_45 = 0;
        uStack_44 = 0;
        uStack_43 = 0;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,9);
        uStack_49 = 0xfe;
        uStack_4b = 3;
        uStack_4a = 6;
        uStack_48 = 0;
        uStack_47 = 0xa5;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
        uStack_49 = 0xfc;
        uStack_46 = arg1;
        uStack_4b = 3;
        uStack_47 = 0x9e;
        uStack_4a = 6;
        uStack_48 = 0x5a;
        uStack_45 = 0;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,7);
        piVar2 = *0xc043f850;
        uStack_4b = 0x83;
        uStack_4a = 7;
        uStack_49 = 0;
        iVar4 = (**(*(*piVar1 + 0x10) + 0x30))(&uStack_4c,3,**0xc043f850,arg3 & 0xffff,*(*(*piVar1 + 0x10) + 0x14));
        sym.memcpy(arg2,*piVar2 + iVar4,arg3);
        uStack_49 = 0xfe;
        uStack_4b = 3;
        uStack_4a = 6;
        uStack_48 = 0;
        uStack_47 = 0xa5;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
        uStack_49 = 0xfc;
        uStack_4b = 3;
        uStack_4a = 6;
        uStack_47 = 0x9d;
        uStack_48 = 0x5a;
        uStack_46 = 0xbd;
        uStack_45 = 0;
        uStack_44 = 3;
        uStack_43 = 0;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,9);
        uStack_49 = 0xfe;
        uStack_4b = 3;
        uStack_4a = 6;
        uStack_48 = 0;
        uStack_47 = 0xa5;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
        uStack_4b = 0x53;
        uStack_49 = 0x23;
        uStack_4a = 0x71;
        uStack_48 = 0x41;
        uStack_47 = 0x4c;
        sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
        uStack_4b = 0x53;
        uStack_49 = 0x23;
        uStack_48 = 0x5a;
        uStack_4a = 0x71;
        uStack_47 = 0xc3;
        uVar3 = sym.sitronix_ts_addrmode_write(*piVar1,&uStack_4c,5);
    }
    else {
        uVar3 = 0xffffffff;
    }
    if (iStack_2c == **0xc043f848) {
        return uVar3;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_read_driver_cmd -----

// ----- BEGIN sitronix_swite_driver_deep_standby (T) [.kernel] file=0xc043f854 runtime=0xc043f854 -----

void sym.sitronix_swite_driver_deep_standby(void)

{
    int32_t *piVar1;
    int32_t arg2;
    int32_t arg2_00;
    int32_t arg2_01;
    int32_t arg2_02;
    uchar uStack_3c;
    uchar uStack_3b;
    uchar uStack_3a;
    uchar uStack_39;
    uchar uStack_38;
    uchar uStack_37;
    uchar uStack_36;
    uchar uStack_35;
    uchar uStack_34;
    uchar uStack_33;
    uchar uStack_32;
    uchar uStack_31;
    int iStack_2c;
    
    piVar1 = *0xc043fb68;
    iStack_2c = **0xc043fb64;
    sym.memset(&uStack_3c,0,0x10);
    uStack_3b = 0x53;
    uStack_3a = 0x71;
    uStack_39 = 0x23;
    uStack_37 = 0x3c;
    uStack_38 = 0xa5;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    uStack_3b = 0x53;
    uStack_3a = 0x71;
    uStack_39 = 0x23;
    uStack_38 = 0x14;
    uStack_37 = 0x55;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    uStack_32 = 0xa2;
    uStack_39 = 0xfc;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_37 = 0x9d;
    uStack_38 = 0x5a;
    uStack_36 = 0x60;
    uStack_35 = 0;
    uStack_34 = 0x71;
    uStack_33 = 0x23;
    uStack_31 = 0;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,0xb);
    uStack_39 = 0xfe;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_38 = 0;
    uStack_37 = 0xa5;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    sym.msleep(1,arg2);
    uStack_39 = 0xfc;
    uStack_37 = 0x9d;
    uStack_32 = 0xa3;
    uStack_3b = 3;
    uStack_36 = 0x60;
    uStack_3a = 6;
    uStack_38 = 0x5a;
    uStack_35 = 0;
    uStack_34 = 0x71;
    uStack_33 = 0x23;
    uStack_31 = 0;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,8);
    uStack_39 = 0xfe;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_38 = 0;
    uStack_37 = 0xa5;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    sym.msleep(1,arg2_00);
    uStack_39 = 0xfc;
    uStack_37 = 0x9d;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_36 = 0x60;
    uStack_38 = 0x5a;
    uStack_32 = 0xa4;
    uStack_35 = 0;
    uStack_34 = 0x71;
    uStack_33 = 0x23;
    uStack_31 = 0;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,8);
    uStack_39 = 0xfe;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_38 = 0;
    uStack_37 = 0xa5;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    sym.msleep(1,arg2_01);
    uStack_39 = 0xfc;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_37 = 0x9d;
    uStack_38 = 0x5a;
    uStack_36 = 0x4f;
    uStack_35 = 0;
    uStack_34 = 1;
    uStack_33 = 0;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,9);
    uStack_39 = 0xfe;
    uStack_3b = 3;
    uStack_3a = 6;
    uStack_38 = 0;
    uStack_37 = 0xa5;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    sym.msleep(1,arg2_02);
    uStack_3b = 0x53;
    uStack_3a = 0x71;
    uStack_39 = 0x23;
    uStack_38 = 0x41;
    uStack_37 = 0x4c;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    uStack_3b = 0x53;
    uStack_3a = 0x71;
    uStack_39 = 0x23;
    uStack_37 = 0xc3;
    uStack_38 = 0x5a;
    sym.sitronix_ts_addrmode_write(*piVar1,&uStack_3c,5);
    if (iStack_2c != **0xc043fb64) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_swite_driver_deep_standby -----

// ----- BEGIN sitronix_ts_read_raw_aa (T) [.kernel] file=0xc043fb6c runtime=0xc043fb6c -----

int sym.sitronix_ts_read_raw_aa(int32_t arg1,int32_t arg2)

{
    uint8_t uVar1;
    uint8_t uVar2;
    uint8_t uVar3;
    uint8_t uVar4;
    int *piVar5;
    int *piVar6;
    char *arg1_00;
    char *pcVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    ulong uVar11;
    
    arg1_00 = sym.kmem_cache_alloc(*(*0xc043fce8 + 0x1c),0xdc0);
    piVar5 = *0xc043fcec;
    if (arg1_00 == NULL) {
        return -0xc;
    }
    iVar9 = 0;
    iVar8 = (*(**0xc043fcec + 0x24) + *(**0xc043fcec + 0x27)) * 2;
    do {
        if (iVar9 == iVar8) {
code_r0xc043fbe4:
            piVar6 = *0xc043fcec;
            iVar8 = 0;
            iVar9 = 0;
            uVar1 = *(*piVar5 + 0x24);
            goto code_r0xc043fc00;
        }
        uVar11 = sym.sitronix_ts_reg_read(arg1,0x140,arg1_00,0x50);
        iVar10 = uVar11;
        if (iVar10 < 0) goto code_r0xc043fc14;
        if (*arg1_00 == '\x10') goto code_r0xc043fbe4;
        iVar9 = iVar9 + 1;
        sym.msleep(1,uVar11 >> 0x20);
    } while (iVar9 <= iVar8);
    iVar10 = -1;
    goto code_r0xc043fc14;
    while( true ) {
        iVar9 = iVar9 + 1;
        sym.msleep(1,uVar11 >> 0x20);
        if (uVar1 << 1 < iVar9) break;
code_r0xc043fc00:
        if (*(*piVar6 + 0x24) <= iVar8) {
            iVar10 = 0;
            goto code_r0xc043fc14;
        }
        uVar11 = sym.sitronix_ts_reg_read(arg1,0x140,arg1_00,0x50);
        iVar10 = uVar11;
        if (iVar10 < 0) goto code_r0xc043fc14;
        if (*arg1_00 == '\x13') {
            uVar2 = arg1_00[1];
            uVar3 = arg1_00[2];
            uVar4 = arg1_00[3];
            pcVar7 = arg1_00 + 4;
            for (iVar10 = 0; iVar10 < (uVar2 - 3) / 2; iVar10 = iVar10 + 1) {
                *(arg2 + (*(*piVar6 + 0x25) * uVar3 + iVar10 + uVar4) * 4) = CONCAT11(*pcVar7,pcVar7[1]);
                pcVar7 = pcVar7 + 2;
            }
            iVar8 = iVar8 + 1;
            goto code_r0xc043fc00;
        }
    }
    iVar10 = -2;
code_r0xc043fc14:
    sym.kfree(arg1_00);
    return iVar10;
}

// ----- END sitronix_ts_read_raw_aa -----

// ----- BEGIN sitronix_ts_enable_raw (T) [.kernel] file=0xc043fcf0 runtime=0xc043fcf0 -----

int * sym.sitronix_ts_enable_raw(int32_t arg1,int32_t arg2)

{
    uint32_t arg1_00;
    int *piVar1;
    int32_t *piVar2;
    void *s;
    int *s_00;
    uint uVar3;
    int32_t arg2_00;
    int32_t arg2_01;
    int *piVar4;
    int iVar5;
    int iVar6;
    int *piVar7;
    int iVar8;
    uint8_t uStack_2e;
    uint8_t uStack_2d;
    int iStack_2c;
    
    piVar2 = *0xc043ff64;
    piVar1 = *0xc043ff60;
    iStack_2c = **0xc043ff60;
    if (**0xc043ff64 == arg2) {
        piVar7 = NULL;
        goto code_r0xc043fdac;
    }
    if (2 < arg2) {
        piVar7 = 0xffffffea;
        goto code_r0xc043fdac;
    }
    if (arg2 == 0) {
        iVar5 = 6;
        sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_2e,1);
        uStack_2e = uStack_2e & 0xa3 | 4;
        do {
            sym.sitronix_ts_reg_write(arg1,0xf1,&uStack_2e,1);
            sym.msleep(10,arg2_00);
            piVar7 = sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_2d,1);
            if (uStack_2d == uStack_2e) {
                if (piVar2[1] != 0) {
                    sym.kfree(piVar2[1]);
                    piVar2[1] = 0;
                }
                *piVar2 = 0;
                goto code_r0xc043fdac;
            }
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    else {
        if (**0xc043ff64 - 1U < 2) {
            s_00 = NULL;
            piVar7 = s_00;
            goto code_r0xc043fef8;
        }
        iVar5 = 6;
        sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_2e,1);
        uStack_2e = uStack_2e & 0xa3 | 0x58;
        do {
            sym.sitronix_ts_reg_write(arg1,0xf1,&uStack_2e,1);
            sym.msleep(10,arg2_01);
            sym.sitronix_ts_reg_read(arg1,0xf1,&uStack_2d,1);
            if (uStack_2d == uStack_2e) {
                iVar5 = 5;
                iVar8 = *(arg1 + 0x24) * *(arg1 + 0x25);
                arg1_00 = iVar8 * 4;
                s = sym.__kmalloc(arg1_00,0xcc0);
                piVar2[1] = s;
                sym.memset(s,0,arg1_00);
                s_00 = sym.__kmalloc(arg1_00,0xcc0);
                goto code_r0xc043feac;
            }
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    piVar7 = 0xfffffffb;
    goto code_r0xc043fdac;
    while( true ) {
        for (; s_00 + iVar8 != piVar4; piVar4 = piVar4 + 1) {
            *(piVar4 + (piVar2[1] - s_00)) = *(piVar4 + (piVar2[1] - s_00)) + *piVar4;
        }
        iVar5 = iVar5 + -1;
        iVar6 = 0;
        if (iVar5 == 0) break;
code_r0xc043feac:
        sym.memset(s_00,0,arg1_00);
        piVar7 = sym.sitronix_ts_read_raw_aa(arg1,s_00);
        piVar4 = s_00;
        if (piVar7 < 0) goto code_r0xc043fefc;
    }
    for (; iVar6 != iVar8; iVar6 = iVar6 + 1) {
        iVar5 = piVar2[1];
        uVar3 = sym.__aeabi_idiv(*(iVar5 + iVar6 * 4),0x5);
        *(iVar5 + iVar6 * 4) = uVar3;
    }
code_r0xc043fef8:
    *piVar2 = arg2;
code_r0xc043fefc:
    if (s_00 != NULL) {
        sym.kfree(s_00);
    }
code_r0xc043fdac:
    if (iStack_2c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return piVar7;
}

// ----- END sitronix_ts_enable_raw -----

// ----- BEGIN sitronix_ts_get_rawdata (T) [.kernel] file=0xc043ff68 runtime=0xc043ff68 -----

int sym.sitronix_ts_get_rawdata(int32_t arg1,int32_t arg2)

{
    uint8_t uVar1;
    uint8_t uVar2;
    int *piVar3;
    int iVar4;
    int *piVar5;
    
    piVar3 = *0xc043ffe4;
    if (**0xc043ffe4 == 0) {
        return -0x47;
    }
    iVar4 = sym.sitronix_ts_read_raw_aa(arg1,arg2);
    if (iVar4 < 0) {
        return iVar4;
    }
    if (*piVar3 == 2) {
        uVar1 = *(arg1 + 0x25);
        uVar2 = *(arg1 + 0x24);
        for (piVar5 = arg2; piVar5 != arg2 + uVar2 * uVar1 * 4; piVar5 = piVar5 + 1) {
            *piVar5 = *(piVar5 + (piVar3[1] - arg2)) - *piVar5;
        }
    }
    return *piVar3;
}

// ----- END sitronix_ts_get_rawdata -----

// ----- BEGIN sitronix_ts_set_rawdata_area (T) [.kernel] file=0xc043ffe8 runtime=0xc043ffe8 -----

uint sym.sitronix_ts_set_rawdata_area(uint noname_0,int32_t arg1,int32_t arg2,int32_t arg3)

{
    int *piVar1;
    int iVar2;
    uint uVar3;
    int iVar4;
    int32_t arg2_00;
    int32_t arg1_00;
    int32_t arg1_01;
    ulong uVar5;
    ushort uStack_36;
    uchar uStack_34;
    uint8_t auStack_33 [6];
    uchar uStack_2d;
    int iStack_14;
    
    piVar1 = *0xc0440168;
    uStack_2d = arg3;
    auStack_33[3] = arg2;
    iStack_14 = **0xc0440168;
    auStack_33[2] = arg1;
    uStack_34 = 6;
    auStack_33[0] = 10;
    auStack_33[1] = 0;
    uStack_36 = 0;
    sym.STChecksumCalculation(&uStack_36,&uStack_34,0xb);
    auStack_33[auStack_33[0]] = uStack_36;
    iVar2 = sym.TDU_WriteIOCommand(&uStack_34);
    if (iVar2 != 0) {
        uVar5 = sym.TDU_SetH2DReady();
        arg2_00 = uVar5 >> 0x20;
        if (uVar5 != 0) {
            iVar2 = 5;
            do {
                uVar3 = sym.msleep(0x14,arg2_00);
                uVar5 = sym.TDU_GetH2DReady(uVar3,arg1_00);
                arg2_00 = uVar5 >> 0x20;
                if (uVar5 != 0) {
                    sym.memset(&uStack_34,0,0x20);
                    uStack_34 = 6;
                    auStack_33[0] = 2;
                    auStack_33[1] = 0x80;
                    uStack_36 = 0;
                    sym.STChecksumCalculation(&uStack_36,&uStack_34,3);
                    auStack_33[auStack_33[0]] = uStack_36;
                    iVar4 = sym.TDU_WriteIOCommand(&uStack_34);
                    if (iVar4 != 0) {
                        uVar5 = sym.TDU_SetH2DReady();
                        goto joined_r0xc0440128;
                    }
                    break;
                }
                iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
        }
    }
code_r0xc0440080:
    uVar3 = 0xfffffffb;
code_r0xc0440084:
    if (iStack_14 == *piVar1) {
        return uVar3;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
joined_r0xc0440128:
    if (uVar5 == 0) goto code_r0xc0440080;
    uVar3 = sym.msleep(0x14,uVar5 >> 0x20);
    uVar5 = sym.TDU_GetH2DReady(uVar3,arg1_01);
    if (uVar5 != 0) {
        uVar3 = 0;
        goto code_r0xc0440084;
    }
    iVar2 = iVar2 + -1;
    uVar5 = CONCAT44(uVar5 >> 0x20,iVar2);
    goto joined_r0xc0440128;
}

// ----- END sitronix_ts_set_rawdata_area -----

// ----- BEGIN sitronix_ts_exdiff_enable (T) [.kernel] file=0xc044016c runtime=0xc044016c -----

int sym.sitronix_ts_exdiff_enable(int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    uint8_t uVar3;
    uint uStack_18;
    int iStack_14;
    
    piVar1 = *0xc0440278;
    iStack_14 = **0xc0440278;
    uStack_18 = arg1;
    iVar2 = sym.sitronix_ts_reg_read(arg1,0x130,&uStack_18,1);
    if (-1 < iVar2) {
        if (arg2 == 0) {
            uVar3 = uStack_18 & 0xfe;
        }
        else {
            uVar3 = uStack_18 | 1;
        }
        uStack_18 = CONCAT31(uStack_18._1_3_,uVar3);
        iVar2 = sym.sitronix_ts_reg_write(arg1,0x130,&uStack_18,1);
        if ((-1 < iVar2) && (iVar2 = sym.sitronix_ts_reg_read(arg1,0x130,&uStack_18,4), -1 < iVar2)) {
            if (arg2 == 0) {
                if ((uStack_18 & 1) != 0) {
                    iVar2 = 0;
                    goto code_r0xc0440228;
                }
                *(arg1 + 0x2e0) = 0;
                *(arg1 + 0x2e1) = 0;
                *(arg1 + 0x2e4) = 0;
            }
            else {
                if (((uStack_18 & 1) == 0) || (uStack_18._1_1_ == '\0')) {
                    iVar2 = -0x16;
                    *(arg1 + 0x2e0) = 0;
                    *(arg1 + 0x2e1) = 0;
                    *(arg1 + 0x2e4) = 0;
                    goto code_r0xc0440228;
                }
                *(arg1 + 0x2e0) = 1;
                *(arg1 + 0x2e1) = uStack_18._1_1_;
                *(arg1 + 0x2e4) = CONCAT11(uStack_18._2_1_,uStack_18._3_1_);
            }
            iVar2 = 0;
        }
    }
code_r0xc0440228:
    if (iStack_14 == *piVar1) {
        return iVar2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_exdiff_enable -----

// ----- BEGIN sitronix_mode_restore (T) [.kernel] file=0xc044027c runtime=0xc044027c -----

void sym.sitronix_mode_restore(uint param_1,uint param_2,uint param_3)

{
    int *piVar1;
    int *piVar2;
    uint8_t uVar3;
    int iVar4;
    int iVar5;
    uint uStack_20;
    int iStack_1c;
    uint uStack_18;
    
    piVar2 = *0xc0440334;
    piVar1 = *0xc0440330;
    iVar5 = 2;
    iStack_1c = **0xc0440330;
    uStack_20 = param_1;
    uStack_18 = param_3;
    do {
        iVar4 = *piVar2 + iVar5;
        if (*(iVar4 + 0x192) == '\0') {
            uVar3 = 0;
        }
        else {
            uVar3 = 0x80;
        }
        uStack_20._0_3_ = CONCAT12(uVar3 | *(iVar4 + 0x1a6),uStack_20);
        sym.TDU_FWControlRead(iVar5,&uStack_20 + 3,1);
        if (uStack_20._3_1_ != uStack_20._2_1_) {
            sym.TDU_FWControlWrite(iVar5,&uStack_20 + 2,1);
        }
        iVar5 = iVar5 + 1;
    } while (iVar5 != 8);
    iVar5 = *piVar2;
    if (*(iVar5 + 0x2e0) != '\0') {
        sym.sitronix_ts_exdiff_enable(iVar5,1);
    }
    if (iStack_1c == *piVar1) {
        return;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_mode_restore -----

// ----- BEGIN sitronix_ts_get_exdiff (T) [.kernel] file=0xc0440338 runtime=0xc0440338 -----

int sym.sitronix_ts_get_exdiff(int32_t arg1,int32_t arg2)

{
    uchar *puVar1;
    uchar *puVar2;
    int *piVar3;
    uint uVar4;
    uint uVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    uint uStack_28;
    int iStack_24;
    
    piVar3 = *0xc04403f8;
    iStack_24 = **0xc04403f8;
    uStack_28 = arg1 & 0xffff;
    iVar6 = sym.sitronix_ts_reg_read(arg1,*(arg1 + 0x2e4),arg2,0x65);
    if (-1 < iVar6) {
        sym.STChecksumCalculation(&uStack_28 + 2,arg2,100);
        uVar5 = *0xc0440400;
        uVar4 = *0xc04403fc;
        if (*(arg2 + 100) == uStack_28._2_1_) {
            iVar7 = arg2 + 0x62;
            do {
                iVar8 = arg2 + 0xe;
                do {
                    puVar1 = arg2 + 2;
                    puVar2 = arg2 + 3;
                    arg2 = arg2 + 2;
                    sym.printk(uVar4,CONCAT11(*puVar1,*puVar2));
                } while (iVar8 != arg2);
                sym.printk(uVar5);
            } while (arg2 != iVar7);
        }
        else {
            iVar6 = -5;
        }
    }
    if (iStack_24 == *piVar3) {
        return iVar6;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_get_exdiff -----

// ----- BEGIN sitronix_ts_mt_reset_process (T) [.kernel] file=0xc0440638 runtime=0xc0440638 -----

void sym.sitronix_ts_mt_reset_process(void)

{
    int32_t *piVar1;
    int *piVar2;
    int *piVar3;
    uint32_t *puVar4;
    int iVar5;
    uint32_t *arg1;
    uint32_t *arg1_00;
    uint32_t arg1_01;
    int iVar6;
    int32_t arg2;
    int iVar7;
    uint32_t *puVar8;
    uint32_t uVar9;
    int32_t arg2_00;
    bool bVar10;
    uint auStack_40 [3];
    uint uStack_34;
    uint *puStack_30;
    int iStack_2c;
    
    piVar1 = *0xc04406b4;
    sym.sitronix_ts_reset_device(**0xc04406b4);
    if (*(*piVar1 + 0x6c) != '\0') {
        sym.mutex_lock(*piVar1 + 0x70);
        sym.sitronix_ts_set_smart_wake_up(*piVar1,*(*piVar1 + 400) != '\0');
        sym.msleep(0x14,arg2);
        sym.sitronix_ts_powerdown(*piVar1,1);
        sym.mutex_unlock(*piVar1 + 0x70);
    }
    sym.mutex_lock(*piVar1 + 0x70);
    sym.sitronix_mode_restore();
    iVar5 = *piVar1;
    arg1 = iVar5 + 0x70;
    iVar7 = *((&stack0xfffffff0 & 0xffffe000) + 0xc);
    DataMemoryBarrier(0xb);
    iVar6 = sym.atomic_cmpxchg_relaxed(arg1);
    piVar2 = *0xc0661c2c;
    if (iVar7 == iVar6) {
        return;
    }
    iStack_2c = **0xc0661c2c;
    uStack_34 = 1;
    arg1_00 = arg1;
    puVar4 = *arg1;
    puStack_30 = &uStack_34;
    do {
        puVar8 = puVar4;
        piVar3 = *0xc0661c30;
        if (**0xc0661c30 == 0) {
            if (*((auStack_40 & 0xffffe000) + 0xc) != (puVar8 & 0xfffffff8)) {
                arg1_00 = sym.debug_locks_off(arg1_00);
                if ((arg1_00 != NULL) && (**0xc0661c34 == 0)) {
                    auStack_40[0] = *0xc0661c38;
                    arg1_00 = sym.warn_slowpath_fmt(*0xc0661c3c,0x4df,9,*0xc0661c40);
                }
                if (*piVar3 != 0) goto code_r0xc0661aa0;
            }
            if ((((puVar8 & 4) != 0) && (iVar6 = sym.debug_locks_off(arg1_00), iVar6 != 0)) && (**0xc0661c34 == 0)) {
                auStack_40[0] = *0xc0661c44;
                sym.warn_slowpath_fmt(*0xc0661c3c,0x4e0,9,*0xc0661c40);
            }
        }
code_r0xc0661aa0:
        if ((puVar8 & 2) != 0) goto code_r0xc0661acc;
        DataMemoryBarrier(0xb);
        arg1_00 = sym.atomic_cmpxchg_relaxed(arg1);
        puVar4 = arg1_00;
    } while (puVar8 != arg1_00);
    if ((puVar8 & 1) != 0) {
code_r0xc0661acc:
        sym._raw_spin_lock(iVar5 + 0x74);
        arg1_01 = sym.debug_mutex_unlock(arg1);
        if (iVar5 + 0x7c != *(iVar5 + 0x7c)) {
            arg2_00 = *(*(iVar5 + 0x7c) + 8);
            sym.debug_mutex_wake_waiter(arg1,*(iVar5 + 0x7c));
            arg1_01 = sym.wake_q_add(&uStack_34,arg2_00);
        }
        if ((puVar8 & 2) != 0) {
            uVar9 = *arg1;
            do {
                if (*piVar3 == 0) {
                    if (*((auStack_40 & 0xffffe000) + 0xc) != (uVar9 & 0xfffffff8)) {
                        arg1_01 = sym.debug_locks_off(arg1_01);
                        if ((arg1_01 != 0) && (**0xc0661c34 == 0)) {
                            auStack_40[0] = *0xc0661c38;
                            arg1_01 = sym.warn_slowpath_fmt(*0xc0661c3c,0xea,9,*0xc0661c40);
                        }
                        if (*piVar3 != 0) goto code_r0xc0661bf4;
                    }
                    if ((((uVar9 & 4) != 0) && (iVar6 = sym.debug_locks_off(arg1_01), iVar6 != 0)) &&
                       (**0xc0661c34 == 0)) {
                        auStack_40[0] = *0xc0661c44;
                        sym.warn_slowpath_fmt(*0xc0661c3c,0xeb,9,*0xc0661c40);
                    }
                }
code_r0xc0661bf4:
                DataMemoryBarrier(0xb);
                arg1_01 = sym.atomic_cmpxchg_relaxed(arg1);
                bVar10 = uVar9 != arg1_01;
                uVar9 = arg1_01;
            } while (bVar10);
        }
        sym._raw_spin_unlock(iVar5 + 0x74);
        sym.wake_up_q(&uStack_34);
    }
    if (iStack_2c != *piVar2) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_ts_mt_reset_process -----

// ----- BEGIN sitronix_ts_monitor_thread_v3 (T) [.kernel] file=0xc04406b8 runtime=0xc04406b8 -----

uint sym.sitronix_ts_monitor_thread_v3(uint noname_0,int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int iVar4;
    int32_t extraout_r1;
    int32_t extraout_r1_00;
    int32_t extraout_r1_01;
    int32_t iVar5;
    int32_t extraout_r1_02;
    int32_t extraout_r1_03;
    int iVar6;
    int32_t arg1_00;
    ulong uVar7;
    int32_t arg_0h;
    
    piVar3 = *0xc0440894;
    piVar2 = *0xc0440890;
    piVar1 = *0xc044088c;
    arg1_00 = 2000;
    iVar6 = **0xc044088c;
    arg_0h = 0;
    sym.msleep(*(**0xc0440890 + 0x100),arg1);
    while (uVar7 = sym.kthread_should_stop(), iVar5 = uVar7 >> 0x20, uVar7 == 0) {
        iVar4 = *piVar2;
        if (*(iVar4 + 0xfc) == '\0') {
            if ((*(iVar4 + 0xfd) == '\0') && (*(iVar4 + 0x90) == 0)) {
                if (*piVar3 == 0) {
                    sym.mutex_lock(iVar4 + 0x70);
                    iVar4 = (**(*(*piVar2 + 0x10) + 0x18))(0,&stack0xffffffd0,0xc,*(*(*piVar2 + 0x10) + 0x14));
                    sym.mutex_unlock(*piVar2 + 0x70);
                    iVar5 = extraout_r1_00;
                    if ((iVar4 < 0) || ((arg_0h >> 8 & 0xf) == 6)) {
                        iVar4 = piVar3[3];
                        piVar3[3] = iVar4 + 1;
                        if (1 < iVar4 + 1) {
                            sym.sitronix_ts_mt_reset_process();
                            arg1_00 = 2000;
                            piVar3[3] = 0;
                            piVar3[2] = 0;
                            iVar5 = extraout_r1_03;
                        }
                    }
                    else {
                        if ((piVar3[1] == '\0') && (*(piVar3 + 5) == '\0')) {
                            sym.mutex_lock(*piVar2 + 0x70);
                            iVar4 = sym.sitroinx_ts_check_display_off(arg_0h);
                            piVar3[2] = piVar3[2] + 1;
                            if (iVar4 == 1) {
                                arg1_00 = 2000;
                            }
                            else {
                                arg1_00 = 500;
                            }
                            sym.mutex_unlock(*piVar2 + 0x70);
                            iVar5 = extraout_r1_01;
                        }
                        else {
                            arg1_00 = 2000;
                            piVar3[2] = 0;
                        }
                        *(piVar3 + 1) = 0;
                        *(piVar3 + 5) = 0;
                        if (2 < piVar3[2]) {
                            piVar3[2] = 0;
                            sym.sitronix_ts_mt_reset_process();
                            piVar3[2] = 0;
                            arg1_00 = 2000;
                            iVar5 = extraout_r1_02;
                        }
                        piVar3[3] = 0;
                    }
                }
                else {
                    *piVar3 = 0;
                }
            }
        }
        else {
            sym.sitronix_ts_mt_reset_process();
            *(*piVar2 + 0xfc) = 0;
            iVar5 = extraout_r1;
        }
        sym.msleep(arg1_00,iVar5);
    }
    if (iVar6 == *piVar1) {
        return 0;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_ts_monitor_thread_v3 -----

// ----- BEGIN sitronix_mt_pause_one (T) [.kernel] file=0xc0440898 runtime=0xc0440898 -----

void sym.sitronix_mt_pause_one(uint noname_0,uint noname_1,int32_t arg1)

{
    if (*(**0xc04408b8 + 0xfe) != '\0') {
        **0xc04408bc = 1;
    }
    return;
}

// ----- END sitronix_mt_pause_one -----

// ----- BEGIN sitronix_mt_pause (T) [.kernel] file=0xc04408c0 runtime=0xc04408c0 -----

void sym.sitronix_mt_pause(void)

{
    *(**0xc04408d4 + 0x90) = 1;
    return;
}

// ----- END sitronix_mt_pause -----

// ----- BEGIN sitronix_mt_restore (T) [.kernel] file=0xc04408d8 runtime=0xc04408d8 -----

void sym.sitronix_mt_restore(void)

{
    *(**0xc04408ec + 0x90) = 0;
    return;
}

// ----- END sitronix_mt_restore -----

// ----- BEGIN sitronix_mt_suspend (T) [.kernel] file=0xc04408f0 runtime=0xc04408f0 -----

void sym.sitronix_mt_suspend(void)

{
    *(**0xc0440904 + 0xfd) = 1;
    return;
}

// ----- END sitronix_mt_suspend -----

// ----- BEGIN sitronix_mt_resume (T) [.kernel] file=0xc0440908 runtime=0xc0440908 -----

void sym.sitronix_mt_resume(int32_t arg1)

{
    int32_t in_r2;
    uint in_s0;
    uint in_s1;
    
    sym.sitronix_mt_pause_one(in_s0,in_s1,in_r2);
    *(**0xc0440924 + 0xfd) = 0;
    return;
}

// ----- END sitronix_mt_resume -----

// ----- BEGIN sitronix_mt_stop (T) [.kernel] file=0xc0440928 runtime=0xc0440928 -----

void sym.sitronix_mt_stop(void)

{
    int *piVar1;
    int iVar2;
    
    piVar1 = *0xc0440968;
    iVar2 = **0xc0440968;
    if (iVar2 == 0) {
        return;
    }
    if (*(iVar2 + 0xfe) == '\0') {
        return;
    }
    if (*(iVar2 + 0x104) == 0) {
        return;
    }
    sym.kthread_stop(*(iVar2 + 0x104));
    *(*piVar1 + 0x104) = 0;
    return;
}

// ----- END sitronix_mt_stop -----

// ----- BEGIN sitronix_mt_start (T) [.kernel] file=0xc044096c runtime=0xc044096c -----

uint32_t sym.sitronix_mt_start(int32_t arg1)

{
    int *piVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int32_t in_r2;
    int iVar4;
    int arg2;
    uint in_s0;
    uint in_s1;
    
    piVar1 = *0xc04409f4;
    if (**0xc04409f4 == 0) {
        return arg1;
    }
    if (*(**0xc04409f4 + 0xfe) != '\0') {
        uVar2 = sym.sitronix_mt_pause_one(in_s0,in_s1,in_r2);
        iVar4 = *0xc04409f8;
        arg2 = *piVar1;
        *(*0xc04409f8 + 8) = 0;
        *(iVar4 + 0xc) = 0;
        *(arg2 + 0x100) = uVar2;
        if (*(arg2 + 0x104) == 0) {
            uVar3 = sym.kthread_create_on_node(*(arg2 + 0x108),arg2,-1,*0xc04409fc);
            uVar2 = uVar3;
            if (uVar3 < 0xfffff001) {
                uVar2 = sym.wake_up_process();
            }
            *(arg2 + 0x104) = uVar3;
        }
        iVar4 = *piVar1;
        if (0xfffff000 < *(iVar4 + 0x104)) {
            *(iVar4 + 0x104) = 0;
        }
        return uVar2;
    }
    return arg1;
}

// ----- END sitronix_mt_start -----

// ----- BEGIN sitronix_stproximity_show (t) [.kernel] file=0xc0440adc runtime=0xc0440adc -----

void sym.sitronix_stproximity_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_4;
    
    piVar1 = *0xc065b558;
    uStack_4 = *0xc0440b10;
    if (*(**0xc0440b08 + 0x8b) == '\0') {
        uStack_4 = *0xc0440b0c;
    }
    iVar2 = **0xc065b558;
    sym.vsnprintf(arg1,200,*0xc0440b14,&uStack_4);
    if (iVar2 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_stproximity_show -----

// ----- BEGIN sitronix_stmodeswitch_show (t) [.kernel] file=0xc0440b18 runtime=0xc0440b18 -----

int sym.sitronix_stmodeswitch_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int iVar1;
    int ...;
    int iVar2;
    
    iVar2 = 0;
    ... = 1;
    do {
        if (... == 7) {
            iVar1 = sym.snprintf(arg1 + iVar2,100,*0xc0440bc8,7);
        }
        else {
            iVar1 = sym.snprintf(arg1 + iVar2,100,*0xc0440bcc,...);
        }
        ... = ... + 1;
        iVar2 = iVar2 + iVar1;
    } while (... != 8);
    return iVar2;
}

// ----- END sitronix_stmodeswitch_show -----

// ----- BEGIN sitronix_stselftest_show (t) [.kernel] file=0xc0440bd0 runtime=0xc0440bd0 -----

void sym.sitronix_stselftest_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_4;
    
    piVar1 = *0xc065b558;
    uStack_4 = *(**0xc0440bec + 0x2ac);
    iVar2 = **0xc065b558;
    sym.vsnprintf(arg1,200,*0xc0440bf0,&uStack_4);
    if (iVar2 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_stselftest_show -----

// ----- BEGIN sitronix_stupgrade_show (t) [.kernel] file=0xc0440bf4 runtime=0xc0440bf4 -----

void sym.sitronix_stupgrade_show(uint noname_0,uint noname_1,int32_t arg1)

{
    uint ...;
    code *UNRECOVERED_JUMPTABLE;
    
    ... = *0xc0440c38;
    if (*(**0xc0440c34 + 0x94) < 0) {
        ... = *0xc0440c3c;
    }
    sym.snprintf(arg1,1000,*0xc0440c40,...);
    //WARNING: Could not recover jumptable at 0xc0440c30. Too many branches
    //WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
}

// ----- END sitronix_stupgrade_show -----

// ----- BEGIN sitronix_stmt_show (t) [.kernel] file=0xc0440c44 runtime=0xc0440c44 -----

void sym.sitronix_stmt_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int iVar2;
    uint uStack_4;
    
    piVar1 = *0xc065b558;
    uStack_4 = *0xc0440c78;
    if (*(**0xc0440c70 + 0x90) == '\0') {
        uStack_4 = *0xc0440c74;
    }
    iVar2 = **0xc065b558;
    sym.vsnprintf(arg1,200,*0xc0440c7c,&uStack_4);
    if (iVar2 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return;
}

// ----- END sitronix_stmt_show -----

// ----- BEGIN sitronix_strequestfw_show (t) [.kernel] file=0xc0440c80 runtime=0xc0440c80 -----

uint sym.sitronix_strequestfw_show(uint noname_0,uint noname_1,int32_t arg1)

{
    sym.strcpy(arg1,*0xc0440c98);
    return 0x1a;
}

// ----- END sitronix_strequestfw_show -----

// ----- BEGIN sitronix_stmodeswitch_store (t) [.kernel] file=0xc0440c9c runtime=0xc0440c9c -----

int32_t sym.sitronix_stmodeswitch_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2)

{
    char cVar1;
    int *piVar2;
    int *piVar3;
    int in_r1;
    int32_t arg3;
    int32_t arg2_00;
    uint noname_1_00;
    int iStack_24;
    uint uStack_20;
    int iStack_1c;
    
    piVar2 = *0xc0440d9c;
    arg3 = 0;
    iStack_1c = **0xc0440d9c;
    uStack_20 = arg1 & 0xff;
    iStack_24 = in_r1;
    sym.strlcpy(&uStack_20 + 1,arg1,3);
    sym._kstrtoul(&uStack_20 + 1,noname_1_00,&iStack_24);
    piVar3 = *0xc0440da0;
    cVar1 = *(arg1 + 3);
    if (iStack_24 != 7) {
        sym.mutex_lock(**0xc0440da0 + 0x70);
        sym.sitronix_mode_switch(iStack_24,cVar1 != '0');
        goto code_r0xc0440d44;
    }
    if (cVar1 == '0') {
code_r0xc0440d24:
        arg2_00 = 1;
    }
    else {
        if (cVar1 == '1') {
            arg3 = 1;
            goto code_r0xc0440d24;
        }
        if (cVar1 == '2') {
            arg3 = 2;
            goto code_r0xc0440d24;
        }
        if (cVar1 == '3') {
            arg3 = 3;
            goto code_r0xc0440d24;
        }
        arg2_00 = 0;
    }
    sym.mutex_lock(**0xc0440da0 + 0x70);
    sym.sitronix_mode_switch_value(7,arg2_00,arg3);
code_r0xc0440d44:
    sym.mutex_unlock(*piVar3 + 0x70);
    if (iStack_1c == *piVar2) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_stmodeswitch_store -----

// ----- BEGIN sitronix_stswu_show (t) [.kernel] file=0xc0440da4 runtime=0xc0440da4 -----

uint sym.sitronix_stswu_show(uint noname_0,uint noname_1,int32_t arg1)

{
    sym.sitronix_ts_report_swu(*(**0xc0440dd4 + 8),0xb0);
    sym.strcpy(arg1,*0xc0440dd8);
    return 6;
}

// ----- END sitronix_stswu_show -----

// ----- BEGIN sitronix_stselftest_store (t) [.kernel] file=0xc0440ddc runtime=0xc0440ddc -----

int32_t sym.sitronix_stselftest_store(int32_t arg1)

{
    int32_t *piVar1;
    int iVar2;
    uint uVar3;
    
    piVar1 = *0xc0440e40;
    sym.sitronix_ts_irq_enable(**0xc0440e40,0);
    iVar2 = *piVar1;
    *(iVar2 + 0x91) = 1;
    sym.mutex_lock(iVar2 + 0x70);
    iVar2 = *piVar1;
    uVar3 = sym.st_self_test();
    *(iVar2 + 0x2ac) = uVar3;
    sym.mutex_unlock(*piVar1 + 0x70);
    sym.sitronix_ts_mt_reset_process();
    iVar2 = *piVar1;
    *(iVar2 + 0x91) = 0;
    sym.sitronix_ts_irq_enable(iVar2,1);
    return arg1;
}

// ----- END sitronix_stselftest_store -----

// ----- BEGIN sitronix_stupgrade_store (t) [.kernel] file=0xc0440e44 runtime=0xc0440e44 -----

int sym.sitronix_stupgrade_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2)

{
    uint32_t *puVar1;
    uint32_t uVar2;
    uint uVar3;
    int iVar4;
    uint32_t uVar5;
    bool bVar6;
    
    puVar1 = *0xc0440ea4;
    uVar5 = *arg1;
    bVar6 = uVar5 == 0x31;
    if (bVar6) {
        uVar5 = **0xc0440ea4;
        arg1 = 1;
    }
    uVar2 = **0xc0440ea4;
    if (bVar6) {
        *(uVar5 + 0x2de) = arg1;
    }
    sym.mutex_lock(uVar2 + 0x70);
    uVar5 = *puVar1;
    uVar3 = sym.sitronix_do_upgrade();
    *(uVar5 + 0x94) = uVar3;
    sym.mutex_unlock(*puVar1 + 0x70);
    iVar4 = *(*puVar1 + 0x94);
    *(*puVar1 + 0x2de) = 0;
    if (-1 < iVar4) {
        iVar4 = arg2;
    }
    return iVar4;
}

// ----- END sitronix_stupgrade_store -----

// ----- BEGIN sitronix_stmt_store (t) [.kernel] file=0xc0440eb8 runtime=0xc0440eb8 -----

int32_t sym.sitronix_stmt_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2)

{
    if (*arg1 == '1') {
        sym.sitronix_mt_restore();
    }
    if (*arg1 == '0') {
        sym.sitronix_mt_pause();
    }
    return arg2;
}

// ----- END sitronix_stmt_store -----

// ----- BEGIN sitronix_icinfo_show (t) [.kernel] file=0xc0440efc runtime=0xc0440efc -----

void sym.sitronix_icinfo_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    
    piVar1 = *0xc0440fc4;
    sym.mutex_lock(**0xc0440fc4 + 0x70);
    sym.sitronix_ts_get_device_info(*piVar1);
    sym.mutex_unlock(*piVar1 + 0x70);
    sym.snprintf(arg1,1000,*0xc0440fc8,*(*piVar1 + 0x14));
    return;
}

// ----- END sitronix_icinfo_show -----

// ----- BEGIN sitronix_create_proc (T) [.kernel] file=0xc044156c runtime=0xc044156c -----

uint sym.sitronix_create_proc(uint param_1)

{
    int32_t *piVar1;
    int32_t iVar2;
    int iVar3;
    int32_t *piVar4;
    uint uVar5;
    int32_t *piVar6;
    
    uVar5 = 0;
    iVar2 = sym.proc_mkdir(param_1,0);
    piVar1 = *0xc04415e0;
    piVar4 = *0xc04415dc;
    piVar6 = *0xc04415dc + 0xe6;
    **0xc04415e0 = iVar2;
    while (piVar4 != piVar6) {
        iVar3 = sym.proc_create(*piVar4,0x1b6,*piVar1,piVar4[2]);
        piVar4[1] = iVar3;
        if (iVar3 == 0) {
            *(piVar4 + 3) = 0;
            uVar5 = 0xffffffed;
            piVar4 = piVar4 + 10;
        }
        else {
            *(piVar4 + 3) = 1;
            piVar4 = piVar4 + 10;
        }
    }
    return uVar5;
}

// ----- END sitronix_create_proc -----

// ----- BEGIN sitronix_remove_proc (T) [.kernel] file=0xc04415e4 runtime=0xc04415e4 -----

void sym.sitronix_remove_proc(void)

{
    int *piVar1;
    int32_t *piVar2;
    char *pcVar3;
    int32_t iVar4;
    int iVar5;
    int32_t arg3;
    int iVar6;
    int32_t iStack_24;
    char *pcStack_20;
    int iStack_1c;
    
    piVar2 = *0xc0441640;
    iVar5 = *0xc044163c;
    iVar6 = 0;
    do {
        if (*(iVar5 + iVar6 + 4) != 0) {
            sym.remove_proc_entry(*(iVar6 + iVar5),*piVar2);
        }
        pcVar3 = *0xc0441644;
        piVar1 = *0xc0229bc0;
        iVar6 = iVar6 + 0x28;
    } while (iVar6 != 0x398);
    if (**0xc0441640 == 0) {
        return;
    }
    iStack_24 = 0;
    pcStack_20 = *0xc0441644;
    iStack_1c = **0xc0229bc0;
    sym._raw_write_lock(*0xc0229bc4);
    iVar5 = sym.__xlate_proc_name(pcVar3,&iStack_24,&pcStack_20);
    pcVar3 = pcStack_20;
    if (iVar5 == 0) {
        arg3 = sym.strlen(pcStack_20);
        iVar4 = iStack_24;
        iVar5 = sym.pde_subdir_find(iStack_24,pcVar3,arg3);
        if (iVar5 != 0) {
            sym.rb_erase(iVar5 + 0x58,iVar4 + 0x54);
        }
        sym._raw_write_unlock(*0xc0229bc4);
        if (iVar5 == 0) {
            sym.warn_slowpath_fmt(*0xc0229bcc,0x2a1,9,*0xc0229bc8);
        }
        else {
            sym.proc_entry_rundown(iVar5);
            if ((*(iVar5 + 0x68) & 0xf000) == 0x4000) {
                *(iStack_24 + 0x38) = *(iStack_24 + 0x38) + -1;
            }
            *(iVar5 + 0x38) = 0;
            iVar6 = sym.pde_subdir_first(iVar5);
            if (iVar6 != 0) {
                sym.pde_subdir_first(iVar5);
                sym.warn_slowpath_fmt(*0xc0229bcc,0x2ac,9,*0xc0229bd4);
            }
            sym.pde_put(iVar5);
        }
    }
    else {
        sym._raw_write_unlock(*0xc0229bc4);
    }
    if (iStack_1c == *piVar1) {
        return;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_remove_proc -----

// ----- BEGIN sitronix_proc_strawdata_show (t) [.kernel] file=0xc044165c runtime=0xc044165c -----

int sym.sitronix_proc_strawdata_show(int32_t arg1)

{
    int *piVar1;
    size_t arg1_00;
    int iVar2;
    int iVar3;
    
    piVar1 = *0xc0441744;
    arg1_00 = sym.__kmalloc(*(**0xc0441744 + 0x24) * *(**0xc0441744 + 0x25) * 4,0xcc0);
    sym.mutex_lock(*piVar1 + 0x70);
    iVar2 = sym.sitronix_ts_get_rawdata(*piVar1,arg1_00);
    sym.mutex_unlock(*piVar1 + 0x70);
    if (-1 < iVar2) {
        sym.seq_printf(arg1);
        for (iVar3 = 0; iVar2 = 0, iVar3 < *(*piVar1 + 0x25); iVar3 = iVar3 + 1) {
            for (; iVar2 < *(*piVar1 + 0x24); iVar2 = iVar2 + 1) {
                sym.seq_printf(arg1);
            }
            sym.seq_printf(arg1);
        }
    }
    if (arg1_00 != 0) {
        sym.kfree(arg1_00);
    }
    return iVar2;
}

// ----- END sitronix_proc_strawdata_show -----

// ----- BEGIN sitronix_proc_strawdata_test_read (t) [.kernel] file=0xc0441758 runtime=0xc0441758 -----

uint32_t sym.sitronix_proc_strawdata_test_read(void)

{
    int *piVar1;
    size_t arg1;
    uint32_t uVar2;
    
    piVar1 = *0xc04417c4;
    arg1 = sym.__kmalloc(*(**0xc04417c4 + 0x24) * *(**0xc04417c4 + 0x25) * 4,0xcc0);
    sym.mutex_lock(*piVar1 + 0x70);
    uVar2 = sym.sitronix_ts_get_rawdata(*piVar1,arg1);
    sym.mutex_unlock(*piVar1 + 0x70);
    if (arg1 != 0) {
        sym.kfree(arg1);
    }
    return uVar2 & uVar2 >> 0x1f;
}

// ----- END sitronix_proc_strawdata_test_read -----

// ----- BEGIN sitronix_stcmdio_show.part.3 (t) [.kernel] file=0xc04417c8 runtime=0xc04417c8 -----

int sym.sitronix_stcmdio_show.part.3(int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    char *format;
    int *piVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    
    sym.strcpy(arg1,*0xc0441864);
    piVar3 = *0xc065b558;
    format = *0xc0441870;
    piVar2 = *0xc044186c;
    piVar1 = *0xc0441868;
    if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
        iVar5 = 6;
        for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
            iVar4 = sym.snprintf(arg1 + iVar5,10,format,*(*piVar2 + uVar6));
            iVar5 = iVar5 + iVar4;
        }
        sym.strcpy(arg1 + iVar5,*0xc0441874);
        return iVar5 + 1;
    }
    iVar4 = **0xc065b558;
    iVar5 = sym.vsnprintf(arg1,200,*0xc0441878,&stack0xfffffffc);
    if (iVar4 != *piVar3) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar5;
}

// ----- END sitronix_stcmdio_show.part.3 -----

// ----- BEGIN sitronix_stdrivercmd_show.part.1 (t) [.kernel] file=0xc04417c8 runtime=0xc04417c8 -----

int sym.sitronix_stcmdio_show.part.3(int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    char *format;
    int *piVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    
    sym.strcpy(arg1,*0xc0441864);
    piVar3 = *0xc065b558;
    format = *0xc0441870;
    piVar2 = *0xc044186c;
    piVar1 = *0xc0441868;
    if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
        iVar5 = 6;
        for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
            iVar4 = sym.snprintf(arg1 + iVar5,10,format,*(*piVar2 + uVar6));
            iVar5 = iVar5 + iVar4;
        }
        sym.strcpy(arg1 + iVar5,*0xc0441874);
        return iVar5 + 1;
    }
    iVar4 = **0xc065b558;
    iVar5 = sym.vsnprintf(arg1,200,*0xc0441878,&stack0xfffffffc);
    if (iVar4 != *piVar3) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar5;
}

// ----- END sitronix_stdrivercmd_show.part.1 -----

// ----- BEGIN sitronix_stfwinfo_show.part.2 (t) [.kernel] file=0xc04417c8 runtime=0xc04417c8 -----

int sym.sitronix_stcmdio_show.part.3(int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    char *format;
    int *piVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    
    sym.strcpy(arg1,*0xc0441864);
    piVar3 = *0xc065b558;
    format = *0xc0441870;
    piVar2 = *0xc044186c;
    piVar1 = *0xc0441868;
    if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
        iVar5 = 6;
        for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
            iVar4 = sym.snprintf(arg1 + iVar5,10,format,*(*piVar2 + uVar6));
            iVar5 = iVar5 + iVar4;
        }
        sym.strcpy(arg1 + iVar5,*0xc0441874);
        return iVar5 + 1;
    }
    iVar4 = **0xc065b558;
    iVar5 = sym.vsnprintf(arg1,200,*0xc0441878,&stack0xfffffffc);
    if (iVar4 != *piVar3) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar5;
}

// ----- END sitronix_stfwinfo_show.part.2 -----

// ----- BEGIN sitronix_stfwinfo_show (t) [.kernel] file=0xc044187c runtime=0xc044187c -----

int sym.sitronix_stfwinfo_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    size_t size;
    char *pcVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    code *UNRECOVERED_JUMPTABLE;
    
    iVar4 = **0xc04418e8;
    if (*(iVar4 + 0x10c) == 0) {
        size = 100;
        pcVar3 = *0xc04418ec;
    }
    else {
        if (*(iVar4 + 0x174) == 0) {
            sym.snprintf(arg1,200,*0xc04418f0,*(iVar4 + 0x18c));
    //WARNING: Could not recover jumptable at 0xc04418d8. Too many branches
    //WARNING: Treating indirect jump as call
            iVar4 = (*UNRECOVERED_JUMPTABLE)();
            return iVar4;
        }
        sym.strcpy(arg1,*0xc0441864);
        pcVar3 = *0xc0441870;
        piVar2 = *0xc044186c;
        piVar1 = *0xc0441868;
        if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
            iVar4 = 6;
            for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
                iVar5 = sym.snprintf(arg1 + iVar4,10,pcVar3,*(*piVar2 + uVar6));
                iVar4 = iVar4 + iVar5;
            }
            sym.strcpy(arg1 + iVar4,*0xc0441874);
            return iVar4 + 1;
        }
        size = 200;
        pcVar3 = *0xc0441878;
    }
    piVar1 = *0xc065b558;
    iVar5 = **0xc065b558;
    iVar4 = sym.vsnprintf(arg1,size,pcVar3,&stack0xfffffffc);
    if (iVar5 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar4;
}

// ----- END sitronix_stfwinfo_show -----

// ----- BEGIN sitronix_stdrivercmd_show (t) [.kernel] file=0xc04418f4 runtime=0xc04418f4 -----

int sym.sitronix_stdrivercmd_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    size_t size;
    int iVar3;
    char *pcVar4;
    int iVar5;
    uint32_t uVar6;
    code *UNRECOVERED_JUMPTABLE;
    
    iVar3 = **0xc0441964;
    if (*(iVar3 + 0x10c) == 0) {
        size = 100;
        pcVar4 = *0xc0441968;
    }
    else {
        if (*(iVar3 + 0x174) == 0) {
            sym.snprintf(arg1,200,*0xc044196c,*(iVar3 + 0x178));
    //WARNING: Could not recover jumptable at 0xc0441954. Too many branches
    //WARNING: Treating indirect jump as call
            iVar3 = (*UNRECOVERED_JUMPTABLE)();
            return iVar3;
        }
        sym.strcpy(arg1,*0xc0441864);
        pcVar4 = *0xc0441870;
        piVar2 = *0xc044186c;
        piVar1 = *0xc0441868;
        if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
            iVar3 = 6;
            for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
                iVar5 = sym.snprintf(arg1 + iVar3,10,pcVar4,*(*piVar2 + uVar6));
                iVar3 = iVar3 + iVar5;
            }
            sym.strcpy(arg1 + iVar3,*0xc0441874);
            return iVar3 + 1;
        }
        size = 200;
        pcVar4 = *0xc0441878;
    }
    piVar1 = *0xc065b558;
    iVar5 = **0xc065b558;
    iVar3 = sym.vsnprintf(arg1,size,pcVar4,&stack0xfffffffc);
    if (iVar5 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar3;
}

// ----- END sitronix_stdrivercmd_show -----

// ----- BEGIN sitronix_stcmdio_show (t) [.kernel] file=0xc0441970 runtime=0xc0441970 -----

int sym.sitronix_stcmdio_show(uint noname_0,uint noname_1,int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    size_t size;
    char *pcVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    code *UNRECOVERED_JUMPTABLE;
    
    iVar4 = **0xc04419e8;
    if (*(iVar4 + 0x10c) == 0) {
        size = 100;
        pcVar3 = *0xc04419ec;
    }
    else {
        if (*(iVar4 + 0x174) == 0) {
            sym.snprintf(arg1,200,*0xc04419f0,*(iVar4 + 0x18c));
    //WARNING: Could not recover jumptable at 0xc04419d8. Too many branches
    //WARNING: Treating indirect jump as call
            iVar4 = (*UNRECOVERED_JUMPTABLE)();
            return iVar4;
        }
        sym.strcpy(arg1,*0xc0441864);
        pcVar3 = *0xc0441870;
        piVar2 = *0xc044186c;
        piVar1 = *0xc0441868;
        if (*(**0xc0441868 + 0x188) * 3 + 6U < 0x1000) {
            iVar4 = 6;
            for (uVar6 = 0; uVar6 < *(*piVar1 + 0x188); uVar6 = uVar6 + 1) {
                iVar5 = sym.snprintf(arg1 + iVar4,10,pcVar3,*(*piVar2 + uVar6));
                iVar4 = iVar4 + iVar5;
            }
            sym.strcpy(arg1 + iVar4,*0xc0441874);
            return iVar4 + 1;
        }
        size = 200;
        pcVar3 = *0xc0441878;
    }
    piVar1 = *0xc065b558;
    iVar5 = **0xc065b558;
    iVar4 = sym.vsnprintf(arg1,size,pcVar3,&stack0xfffffffc);
    if (iVar5 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar4;
}

// ----- END sitronix_stcmdio_show -----

// ----- BEGIN sitronix_stproximity_store (t) [.kernel] file=0xc04419f4 runtime=0xc04419f4 -----

int32_t sym.sitronix_stproximity_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int arg1_00;
    
    piVar1 = *0xc0441a90;
    if (*(**0xc0441a90 + 0x8a) != '\0') {
        sym.mutex_lock(**0xc0441a90 + 0x70);
        if (*arg1 == '1') {
            sym.sitronix_ts_proximity_enable(*piVar1,1);
        }
        if (*arg1 == '0') {
            sym.sitronix_ts_proximity_enable(*piVar1,0);
        }
        if (((*arg1 == '2') && (arg1_00 = *piVar1, *(arg1_00 + 0x8b) != '\0')) && (*(arg1_00 + 0x6c) != '\0')) {
            sym.sitronix_ts_proximity_control_sensing(arg1_00,1);
        }
        sym.mutex_unlock(*piVar1 + 0x70);
    }
    return arg2;
}

// ----- END sitronix_stproximity_store -----

// ----- BEGIN sitronix_stcmdio_store (t) [.kernel] file=0xc0442180 runtime=0xc0442180 -----

int sym.sitronix_stcmdio_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2,int32_t arg_0h)

{
    int *piVar1;
    int *piVar2;
    int *piVar3;
    uint32_t uVar4;
    int iVar5;
    char *src;
    int iVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int iVar10;
    int iStack_4c;
    int iStack_48;
    char acStack_36 [10];
    int iStack_2c;
    
    piVar2 = *0xc044258c;
    piVar1 = *0xc0442588;
    uVar8 = 0;
    iStack_2c = **0xc0442588;
    uVar9 = 0;
    uVar7 = 0;
    iVar5 = 0;
    iStack_48 = 0;
    iStack_4c = 0;
    *(**0xc044258c + 0x10c) = 0;
    iVar6 = 0;
    for (iVar10 = 0; iVar10 != arg2; iVar10 = iVar10 + 1) {
        if (*(arg1 + iVar10) == ' ') {
            acStack_36[0] = '\0';
            acStack_36[1] = '\0';
            acStack_36[2] = '\0';
            acStack_36[3] = '\0';
            acStack_36[4] = '\0';
            acStack_36[5] = '\0';
            acStack_36[6] = '\0';
            acStack_36[7] = '\0';
            acStack_36[8] = '\0';
            acStack_36[9] = '\0';
            sym.strlcpy(acStack_36,arg1 + iVar5,(iVar10 - iVar5) + 1);
            if (iVar6 == 0) {
                uVar7 = sym.strlen(acStack_36);
                uVar7 = sym.st_formatinput.constprop.9(acStack_36,uVar7);
                if (1 < uVar7) {
                    iVar5 = **0xc044258c;
                    src = *0xc044259c;
                    goto code_r0xc0442348;
                }
                iVar6 = 1;
            }
            else if (iVar6 == 1) {
                uVar9 = sym.strlen(acStack_36);
                uVar9 = sym.st_formatinput.constprop.9(acStack_36,uVar9);
                if (6 < uVar9) {
                    iVar5 = **0xc044258c;
                    src = *0xc04425a0;
                    goto code_r0xc0442348;
                }
                iVar6 = 2;
            }
            else if (iVar6 == 2) {
                uVar4 = sym.strlen(acStack_36);
                iStack_4c = sym.st_formatinput.constprop.9(acStack_36,uVar4);
                if (iStack_4c < 0) {
                    iVar5 = **0xc044258c;
                    src = *0xc04425a4;
                    goto code_r0xc0442348;
                }
                iVar6 = 3;
            }
            else if (iVar6 == 3) {
                uVar4 = sym.strlen(acStack_36);
                iStack_48 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
                if (iStack_48 < 0) {
                    iVar5 = **0xc044258c;
                    src = *0xc04425a8;
                    goto code_r0xc0442348;
                }
                iVar6 = 4;
            }
            else {
                uVar4 = sym.strlen(acStack_36);
                iVar5 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
                if (iVar5 < 0) {
                    iVar5 = **0xc044258c;
                    src = *0xc04425ac;
                    goto code_r0xc0442348;
                }
                iVar6 = iVar6 + 1;
                *(**0xc0442590 + uVar8) = iVar5;
                uVar8 = uVar8 + 1;
            }
            iVar5 = iVar10 + 1;
        }
    }
    acStack_36[0] = '\0';
    acStack_36[1] = '\0';
    acStack_36[2] = '\0';
    acStack_36[3] = '\0';
    acStack_36[4] = '\0';
    acStack_36[5] = '\0';
    acStack_36[6] = '\0';
    acStack_36[7] = '\0';
    acStack_36[8] = '\0';
    acStack_36[9] = '\0';
    sym.strlcpy(acStack_36,arg1 + iVar5,iVar10 - iVar5);
    piVar3 = *0xc044258c;
    uVar4 = sym.strlen(acStack_36);
    iVar5 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
    if (-1 < iVar5) {
        *(**0xc0442590 + uVar8) = iVar5;
        uVar8 = uVar8 + 1;
    }
    if (uVar7 == 1) {
        uVar8 = (**0xc0442590)[1] + ***0xc0442590 * 0x100;
    }
    else if (uVar9 - 3 < 2) {
        uVar4 = uVar8 & 1;
        if (uVar8 < 0) {
            uVar4 = -uVar4;
        }
        if (uVar4 == 1) {
            iVar5 = *piVar3;
            src = *0xc04425b0;
code_r0xc0442348:
            iVar10 = -5;
            sym.strlcpy(iVar5 + 0x110,src,100);
            goto code_r0xc0442354;
        }
    }
    iVar5 = *piVar2;
    *(iVar5 + 0x178) = iStack_48 + iStack_4c * 0x100;
    *(iVar5 + 0x174) = uVar7;
    *(iVar5 + 0x188) = uVar8;
    *(iVar5 + 0x18c) = uVar9;
    sym.mutex_lock(iVar5 + 0x70);
    if ((uVar7 & 1 & uVar9 == 6) == 0) {
        uVar8 = (uVar7 ^ 1) & 1;
        if ((uVar9 == 6 & uVar8) == 0) {
            if ((uVar7 & 1 & uVar9 != 6) == 0) {
                iVar5 = 0;
                if ((uVar8 & uVar9 != 6) != 0) {
                    iVar5 = *piVar2;
                    iVar5 = sym.TDU_CmdioWrite(*(iVar5 + 0x18c),*(iVar5 + 0x178),**0xc0442590,*(iVar5 + 0x188));
                }
            }
            else {
                iVar5 = *piVar2;
                iVar5 = sym.TDU_CmdioRead(*(iVar5 + 0x18c),*(iVar5 + 0x178),**0xc0442594,*(iVar5 + 0x188));
            }
        }
        else {
            iVar5 = *piVar2;
            iVar5 = (**(*(iVar5 + 0x10) + 0x1c))
                              (*(iVar5 + 0x178),**0xc0442590,*(iVar5 + 0x188) & 0xffff,*(*(iVar5 + 0x10) + 0x14));
        }
    }
    else {
        iVar5 = *piVar2;
        iVar5 = sym.sitronix_ts_reg_read_1(iVar5,*(iVar5 + 0x178),**0xc0442594,*(iVar5 + 0x188));
    }
    sym.mutex_unlock(*piVar3 + 0x70);
    if (iVar5 < 0) {
        sym.strlcpy(*piVar3 + 0x110,*0xc0442598,100);
        iVar10 = iVar5;
    }
    else {
        *(*piVar3 + 0x10c) = 1;
    }
code_r0xc0442354:
    if (iStack_2c == *piVar1) {
        return iVar10;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_stcmdio_store -----

// ----- BEGIN sitronix_stfwinfo_store (t) [.kernel] file=0xc04425b4 runtime=0xc04425b4 -----

int sym.sitronix_stfwinfo_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2,int32_t arg_0h)

{
    int *piVar1;
    int *piVar2;
    uint32_t uVar3;
    int iVar4;
    char *src;
    int *extraout_r3;
    int *piVar5;
    int iVar6;
    int iVar7;
    uint32_t uVar8;
    int iVar9;
    uint uStack_44;
    char acStack_36 [10];
    int iStack_2c;
    
    piVar5 = *0xc04427e8;
    piVar2 = *0xc04427e4;
    piVar1 = *0xc04427e0;
    iVar6 = 0;
    uVar8 = 0;
    iStack_2c = **0xc04427e0;
    iVar9 = 0;
    iVar7 = 0;
    iVar4 = 0;
    uStack_44 = 0;
    *(**0xc04427e4 + 0x10c) = 0;
    do {
        if (iVar7 == arg2) {
            acStack_36[0] = '\0';
            acStack_36[1] = '\0';
            acStack_36[2] = '\0';
            acStack_36[3] = '\0';
            acStack_36[4] = '\0';
            acStack_36[5] = '\0';
            acStack_36[6] = '\0';
            acStack_36[7] = '\0';
            acStack_36[8] = '\0';
            acStack_36[9] = '\0';
            sym.strlcpy(acStack_36,arg1 + iVar4,iVar7 - iVar4);
            uVar3 = sym.strlen(acStack_36);
            iVar4 = sym.st_formatinput.constprop.9(acStack_36,uVar3);
            piVar5 = extraout_r3;
            if (-1 < iVar4) {
                piVar5 = **0xc04427e8;
                *(piVar5 + iVar6) = iVar4;
                iVar6 = iVar6 + 1;
            }
            iVar4 = *piVar2;
            if (uVar8 == 1) {
                piVar5 = *0xc04427e8;
            }
            if (uVar8 == 1) {
                iVar6 = (*piVar5)[1] + **piVar5 * 0x100;
            }
            *(iVar4 + 0x174) = uVar8;
            *(iVar4 + 0x188) = iVar6;
            *(iVar4 + 0x18c) = uStack_44;
            sym.mutex_lock(iVar4 + 0x70);
            iVar4 = sym.TDU_FWInfoRead(*(*piVar2 + 0x18c),**0xc04427ec,*(*piVar2 + 0x188));
            sym.mutex_unlock(*piVar2 + 0x70);
            if (iVar4 < 0) {
                sym.strlcpy(*piVar2 + 0x110,*0xc04427f0,100);
                iVar7 = iVar4;
            }
            else {
                *(*piVar2 + 0x10c) = 1;
            }
code_r0xc044273c:
            if (iStack_2c != *piVar1) {
    //WARNING: Subroutine does not return
                sym.__stack_chk_fail();
            }
            return iVar7;
        }
        if (*(arg1 + iVar7) == ' ') {
            acStack_36[0] = '\0';
            acStack_36[1] = '\0';
            acStack_36[2] = '\0';
            acStack_36[3] = '\0';
            acStack_36[4] = '\0';
            acStack_36[5] = '\0';
            acStack_36[6] = '\0';
            acStack_36[7] = '\0';
            acStack_36[8] = '\0';
            acStack_36[9] = '\0';
            sym.strlcpy(acStack_36,arg1 + iVar4,(iVar7 - iVar4) + 1);
            if (iVar9 == 0) {
                uVar8 = sym.strlen(acStack_36);
                uVar8 = sym.st_formatinput.constprop.9(acStack_36,uVar8);
                if (1 < uVar8) {
                    iVar4 = *piVar2;
                    src = *0xc04427f4;
code_r0xc0442730:
                    iVar7 = -5;
                    sym.strlcpy(iVar4 + 0x110,src,100);
                    goto code_r0xc044273c;
                }
                iVar9 = 1;
            }
            else if (iVar9 == 1) {
                uVar3 = sym.strlen(acStack_36);
                iVar9 = 2;
                uStack_44 = sym.st_formatinput.constprop.9(acStack_36,uVar3);
            }
            else {
                uVar3 = sym.strlen(acStack_36);
                iVar4 = sym.st_formatinput.constprop.9(acStack_36,uVar3);
                if (iVar4 < 0) {
                    iVar4 = *piVar2;
                    src = *0xc04427f8;
                    goto code_r0xc0442730;
                }
                iVar9 = iVar9 + 1;
                *(*piVar5 + iVar6) = iVar4;
                iVar6 = iVar6 + 1;
            }
            iVar4 = iVar7 + 1;
        }
        iVar7 = iVar7 + 1;
    } while( true );
}

// ----- END sitronix_stfwinfo_store -----

// ----- BEGIN sitronix_stdrivercmd_store (t) [.kernel] file=0xc04427fc runtime=0xc04427fc -----

int sym.sitronix_stdrivercmd_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2,int32_t arg_0h)

{
    int *piVar1;
    int *piVar2;
    int32_t *piVar3;
    uint32_t uVar4;
    int iVar5;
    char *src;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    int iVar9;
    int iStack_44;
    char acStack_36 [10];
    int iStack_2c;
    
    piVar3 = *0xc0442a8c;
    piVar2 = *0xc0442a88;
    piVar1 = *0xc0442a84;
    uVar6 = 0;
    uVar8 = 0;
    iStack_2c = **0xc0442a84;
    iVar9 = 0;
    iVar5 = 0;
    iStack_44 = 0;
    *(**0xc0442a88 + 0x10c) = 0;
    for (iVar7 = 0; iVar7 != arg2; iVar7 = iVar7 + 1) {
        if (*(arg1 + iVar7) == ' ') {
            acStack_36[0] = '\0';
            acStack_36[1] = '\0';
            acStack_36[2] = '\0';
            acStack_36[3] = '\0';
            acStack_36[4] = '\0';
            acStack_36[5] = '\0';
            acStack_36[6] = '\0';
            acStack_36[7] = '\0';
            acStack_36[8] = '\0';
            acStack_36[9] = '\0';
            sym.strlcpy(acStack_36,arg1 + iVar5,(iVar7 - iVar5) + 1);
            if (iVar9 == 0) {
                uVar8 = sym.strlen(acStack_36);
                uVar8 = sym.st_formatinput.constprop.9(acStack_36,uVar8);
                if (1 < uVar8) {
                    iVar5 = *piVar2;
                    src = *0xc0442a98;
                    goto code_r0xc0442980;
                }
                iVar9 = 1;
            }
            else if (iVar9 == 1) {
                uVar4 = sym.strlen(acStack_36);
                iStack_44 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
                if (iStack_44 < 0) {
                    iVar5 = *piVar2;
                    src = *0xc0442a9c;
                    goto code_r0xc0442980;
                }
                iVar9 = 2;
            }
            else {
                uVar4 = sym.strlen(acStack_36);
                iVar5 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
                if (iVar5 < 0) {
                    iVar5 = *piVar2;
                    src = *0xc0442aa0;
                    goto code_r0xc0442980;
                }
                iVar9 = iVar9 + 1;
                *(*piVar3 + uVar6) = iVar5;
                uVar6 = uVar6 + 1;
            }
            iVar5 = iVar7 + 1;
        }
    }
    acStack_36[0] = '\0';
    acStack_36[1] = '\0';
    acStack_36[2] = '\0';
    acStack_36[3] = '\0';
    acStack_36[4] = '\0';
    acStack_36[5] = '\0';
    acStack_36[6] = '\0';
    acStack_36[7] = '\0';
    acStack_36[8] = '\0';
    acStack_36[9] = '\0';
    sym.strlcpy(acStack_36,arg1 + iVar5,iVar7 - iVar5);
    uVar4 = sym.strlen(acStack_36);
    iVar5 = sym.st_formatinput.constprop.9(acStack_36,uVar4);
    if (-1 < iVar5) {
        *(**0xc0442a8c + uVar6) = iVar5;
        uVar6 = uVar6 + 1;
    }
    if (uVar8 == 1) {
        uVar6 = ***0xc0442a8c;
    }
    else {
        uVar4 = uVar6 & 1;
        if (uVar6 < 0) {
            uVar4 = -uVar4;
        }
        if (uVar4 == 1) {
            iVar5 = *piVar2;
            src = *0xc0442aa4;
code_r0xc0442980:
            iVar7 = -5;
            sym.strlcpy(iVar5 + 0x110,src,100);
            goto code_r0xc044298c;
        }
    }
    iVar5 = *piVar2;
    *(iVar5 + 0x178) = iStack_44;
    *(iVar5 + 0x174) = uVar8;
    *(iVar5 + 0x188) = uVar6;
    sym.mutex_lock(iVar5 + 0x70);
    iVar5 = *piVar2;
    if (uVar8 == 1) {
        iVar5 = sym.sitronix_read_driver_cmd(*(iVar5 + 0x178),**0xc0442a90,*(iVar5 + 0x188));
    }
    else {
        iVar5 = sym.sitronix_write_driver_cmd(*(iVar5 + 0x178),**0xc0442a8c,*(iVar5 + 0x188));
    }
    sym.mutex_unlock(*piVar2 + 0x70);
    if (iVar5 < 0) {
        sym.strlcpy(*piVar2 + 0x110,*0xc0442a94,100);
        iVar7 = iVar5;
    }
    else {
        *(*piVar2 + 0x10c) = 1;
    }
code_r0xc044298c:
    if (iStack_2c == *piVar1) {
        return iVar7;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_stdrivercmd_store -----

// ----- BEGIN sitronix_copystring_without_line (T) [.kernel] file=0xc04431d0 runtime=0xc04431d0 -----

uint sym.sitronix_copystring_without_line(int32_t arg1,int32_t arg2)

{
    size_t n;
    
    n = sym.strlen(arg1);
    sym.strlcpy(arg2,arg1,n);
    if (*(arg1 + (n - 1)) == '\n') {
        *(arg2 + (n - 1)) = 0;
    }
    return 0;
}

// ----- END sitronix_copystring_without_line -----

// ----- BEGIN sitronix_strequestfw_store (t) [.kernel] file=0xc0443210 runtime=0xc0443210 -----

int32_t sym.sitronix_strequestfw_store(uint noname_0,uint noname_1,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int *piVar2;
    uint32_t uVar3;
    size_t arg1_00;
    int iVar4;
    uint32_t *puStack_38;
    int iStack_34;
    uchar auStack_30 [4];
    uchar auStack_2c [4];
    uint32_t uStack_28;
    uchar auStack_20 [4];
    int iStack_1c;
    
    piVar1 = *0xc04433a0;
    iStack_1c = **0xc04433a0;
    puStack_38 = NULL;
    uVar3 = sym.strlen(arg1);
    if (200 < uVar3) {
        iVar4 = -0x16;
        goto code_r0xc0443354;
    }
    arg1_00 = sym.kmem_cache_alloc(*(*0xc04433a4 + 0x20),0xdc0);
    if (arg1_00 == 0) {
        iVar4 = -0xc;
        goto code_r0xc0443354;
    }
    sym.sitronix_copystring_without_line(arg1,arg1_00);
    piVar2 = *0xc04433a8;
    iVar4 = sym.request_firmware(&puStack_38,arg1_00,*(**0xc04433a8 + 4) + 0x10);
    if (iVar4 == 0) {
        if ((*puStack_38 < 0x1001) ||
           (iVar4 = sym.st_check_fw(puStack_38[1],&iStack_34,auStack_30,auStack_2c), iVar4 != 0)) {
            iVar4 = sym.st_check_cfg(puStack_38[1],auStack_20);
            if (iVar4 == 0) {
                uStack_28 = 0x10000;
                uVar3 = puStack_38[1];
                goto code_r0xc044332c;
            }
        }
        else {
            sym.st_set_dump(puStack_38[1] + iStack_34,iStack_34);
            iVar4 = 0;
            if ((uStack_28 < *puStack_38) &&
               (iVar4 = sym.st_check_cfg(puStack_38[1] + uStack_28,auStack_20), iVar4 == 0)) {
                uVar3 = puStack_38[1] + uStack_28;
code_r0xc044332c:
                sym.st_set_dump(uVar3,uStack_28);
            }
        }
        *(*piVar2 + 0x2df) = 1;
        sym.release_firmware(puStack_38);
        if (iVar4 == 0) {
            iVar4 = arg2;
        }
    }
    else {
        iVar4 = -2;
    }
    sym.kfree(arg1_00);
code_r0xc0443354:
    if (iStack_1c == *piVar1) {
        return iVar4;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_strequestfw_store -----

// ----- BEGIN sitronix_copycmd_without_line (T) [.kernel] file=0xc04433ac runtime=0xc04433ac -----

int sym.sitronix_copycmd_without_line(int32_t arg1,int32_t arg2,int32_t arg3)

{
    int32_t arg1_00;
    int arg3_00;
    
    arg1_00 = *0xc0443418;
    if (arg1 == 0) {
        return 0;
    }
    arg3_00 = arg3 + -1;
    if (arg3_00 < 0) {
        if (**0xc0443414 == '\0') {
            **0xc0443414 = '\x01';
            sym.warn_slowpath_fmt(arg1_00,0x96,9,NULL);
        }
    }
    else {
        arg3_00 = sym._copy_from_user_44(arg2,arg1,arg3_00);
    }
    if (arg3_00 < 0) {
        arg3_00 = -5;
    }
    return arg3_00;
}

// ----- END sitronix_copycmd_without_line -----

// ----- BEGIN sitronix_proc_stexdiff_write (T) [.kernel] file=0xc0443830 runtime=0xc0443830 -----

int32_t sym.sitronix_proc_stexdiff_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int *piVar2;
    int iVar3;
    int iVar4;
    int32_t arg2_00;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc04438f0;
    iStack_1c = **0xc04438f0;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar3 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar4 = *0xc04438f4;
    if (iVar3 < 1) {
        iVar3 = sym.strcmp(acStack_26,*(*0xc04438f4 + 0x308));
        if (iVar3 == 0) {
            arg2_00 = 1;
        }
        else {
            iVar4 = sym.strcmp(acStack_26,*(iVar4 + 0x30c));
            arg2_00 = 0;
            if (iVar4 != 0) goto code_r0xc04438e0;
        }
        piVar2 = *0xc04438f8;
        sym.mutex_lock(**0xc04438f8 + 0x70);
        sym.sitronix_ts_exdiff_enable(*piVar2,arg2_00);
        sym.mutex_unlock(*piVar2 + 0x70);
    }
    else {
code_r0xc04438e0:
        arg2 = -0x16;
    }
    if (iStack_1c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg2;
}

// ----- END sitronix_proc_stexdiff_write -----

// ----- BEGIN sitronix_proc_stswktapmode_write (T) [.kernel] file=0xc04438fc runtime=0xc04438fc -----

int32_t sym.sitronix_proc_stswktapmode_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int *piVar2;
    int iVar3;
    int iVar4;
    uint8_t uVar5;
    char acStack_1e [10];
    int iStack_14;
    
    piVar1 = *0xc04439d4;
    iStack_14 = **0xc04439d4;
    acStack_1e[0] = '\0';
    acStack_1e[1] = '\0';
    acStack_1e[2] = '\0';
    acStack_1e[3] = '\0';
    acStack_1e[4] = '\0';
    acStack_1e[5] = '\0';
    acStack_1e[6] = '\0';
    acStack_1e[7] = '\0';
    acStack_1e[8] = '\0';
    acStack_1e[9] = '\0';
    iVar3 = sym.sitronix_copycmd_without_line(arg1,acStack_1e,arg2);
    iVar4 = *0xc04439d8;
    if (iVar3 < 1) {
        iVar3 = sym.strcmp(acStack_1e,*(*0xc04439d8 + 0x338));
        if (iVar3 == 0) {
            iVar4 = 1;
        }
        else {
            iVar4 = sym.strcmp(acStack_1e,*(iVar4 + 0x33c));
            if (iVar4 != 0) goto code_r0xc0443964;
            iVar4 = 2;
        }
        piVar2 = *0xc04439dc;
        iVar3 = **0xc04439dc;
        if (iVar3 != 0) {
            uVar5 = *(iVar3 + 0x1ba) & 0xfc;
            if (iVar4 == 2) {
                uVar5 = uVar5 | 2;
            }
            else {
                uVar5 = uVar5 | 1;
            }
            *(iVar3 + 0x1ba) = uVar5;
            sym.mutex_lock(iVar3 + 0x70);
            sym.sitronix_swk_config_restore();
            sym.mutex_unlock(*piVar2 + 0x70);
        }
    }
    else {
code_r0xc0443964:
        arg2 = -0x16;
    }
    if (iStack_14 == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_stswktapmode_write -----

// ----- BEGIN sitronix_proc_stswkselect_write (T) [.kernel] file=0xc04439e0 runtime=0xc04439e0 -----

int32_t sym.sitronix_proc_stswkselect_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int *piVar2;
    char cVar3;
    int iVar4;
    char acStack_1e [10];
    int iStack_14;
    
    piVar1 = *0xc0443b00;
    iStack_14 = **0xc0443b00;
    acStack_1e[0] = '\0';
    acStack_1e[1] = '\0';
    acStack_1e[2] = '\0';
    acStack_1e[3] = '\0';
    acStack_1e[4] = '\0';
    acStack_1e[5] = '\0';
    acStack_1e[6] = '\0';
    acStack_1e[7] = '\0';
    acStack_1e[8] = '\0';
    acStack_1e[9] = '\0';
    iVar4 = sym.sitronix_copycmd_without_line(arg1,acStack_1e,arg2);
    if (0 < iVar4) {
code_r0xc0443a6c:
        arg2 = -0x16;
        goto code_r0xc0443ad8;
    }
    iVar4 = sym.strcmp(acStack_1e,*0xc0443b04);
    cVar3 = '\0';
    if (iVar4 != 0) {
        iVar4 = sym.strcmp(acStack_1e,*0xc0443b08);
        if (iVar4 == 0) {
            cVar3 = '\x01';
        }
        else {
            iVar4 = sym.strcmp(acStack_1e,*0xc0443b0c);
            if (iVar4 == 0) {
                cVar3 = '\x02';
            }
            else {
                iVar4 = sym.strcmp(acStack_1e,*0xc0443b10);
                if (iVar4 != 0) goto code_r0xc0443a6c;
                cVar3 = '\x03';
            }
        }
    }
    piVar2 = *0xc0443b14;
    iVar4 = **0xc0443b14;
    if (iVar4 == 0) goto code_r0xc0443ad8;
    *(iVar4 + 0x1ba) = 0;
    if (cVar3 == '\x02') {
code_r0xc0443abc:
        *(iVar4 + 0x1ba) = cVar3;
    }
    else if (cVar3 == '\x03') {
        *(iVar4 + 0x1bb) = 0xf;
    }
    else {
        if (cVar3 == '\x01') goto code_r0xc0443abc;
        *(iVar4 + 0x1ba) = *(iVar4 + 0x1be);
    }
    sym.mutex_lock(iVar4 + 0x70);
    sym.sitronix_swk_config_restore();
    sym.mutex_unlock(*piVar2 + 0x70);
code_r0xc0443ad8:
    if (iStack_14 == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_stswkselect_write -----

// ----- BEGIN sitronix_proc_swu_write (t) [.kernel] file=0xc0443b18 runtime=0xc0443b18 -----

int32_t sym.sitronix_proc_swu_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0443be8;
    iStack_1c = **0xc0443be8;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0443bec;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0443bec + 0x10));
        piVar5 = *0xc0443bf0;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc0443bf0 + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x14));
            piVar5 = *0xc0443bf0;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443b98;
            }
            sym.mutex_lock(**0xc0443bf0 + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(1,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443b98:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_swu_write -----

// ----- BEGIN sitronix_proc_glove_write (t) [.kernel] file=0xc0443bf4 runtime=0xc0443bf4 -----

int32_t sym.sitronix_proc_glove_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0443cc4;
    iStack_1c = **0xc0443cc4;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0443cc8;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0443cc8 + 0x38));
        piVar5 = *0xc0443ccc;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc0443ccc + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x3c));
            piVar5 = *0xc0443ccc;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443c74;
            }
            sym.mutex_lock(**0xc0443ccc + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(2,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443c74:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_glove_write -----

// ----- BEGIN sitronix_proc_charge_write (t) [.kernel] file=0xc0443cd0 runtime=0xc0443cd0 -----

int32_t sym.sitronix_proc_charge_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0443da0;
    iStack_1c = **0xc0443da0;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0443da4;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0443da4 + 0x60));
        piVar5 = *0xc0443da8;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc0443da8 + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 100));
            piVar5 = *0xc0443da8;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443d50;
            }
            sym.mutex_lock(**0xc0443da8 + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(3,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443d50:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_charge_write -----

// ----- BEGIN sitronix_proc_jittersuppress_write (t) [.kernel] file=0xc0443dac runtime=0xc0443dac -----

int32_t sym.sitronix_proc_jittersuppress_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0443e7c;
    iStack_1c = **0xc0443e7c;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0443e80;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0443e80 + 0x88));
        piVar5 = *0xc0443e84;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc0443e84 + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x8c));
            piVar5 = *0xc0443e84;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443e2c;
            }
            sym.mutex_lock(**0xc0443e84 + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(4,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443e2c:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_jittersuppress_write -----

// ----- BEGIN sitronix_proc_palm_write (t) [.kernel] file=0xc0443e88 runtime=0xc0443e88 -----

int32_t sym.sitronix_proc_palm_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0443f58;
    iStack_1c = **0xc0443f58;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0443f5c;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0443f5c + 0xb0));
        piVar5 = *0xc0443f60;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc0443f60 + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0xb4));
            piVar5 = *0xc0443f60;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443f08;
            }
            sym.mutex_lock(**0xc0443f60 + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(5,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443f08:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_palm_write -----

// ----- BEGIN sitronix_proc_headphone_write (t) [.kernel] file=0xc0443f64 runtime=0xc0443f64 -----

int32_t sym.sitronix_proc_headphone_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    uint uVar4;
    int *piVar5;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc0444034;
    iStack_1c = **0xc0444034;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc0444038;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc0444038 + 0xd8));
        piVar5 = *0xc044403c;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc044403c + 0x70);
            uVar4 = 1;
        }
        else {
            iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0xdc));
            piVar5 = *0xc044403c;
            if (iVar3 != 0) {
                arg2 = -5;
                goto code_r0xc0443fe4;
            }
            sym.mutex_lock(**0xc044403c + 0x70);
            uVar4 = 0;
        }
        sym.sitronix_mode_switch(6,uVar4);
        sym.mutex_unlock(*piVar5 + 0x70);
    }
    else {
        arg2 = -0x16;
    }
code_r0xc0443fe4:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_headphone_write -----

// ----- BEGIN sitronix_proc_grip_write (t) [.kernel] file=0xc0444040 runtime=0xc0444040 -----

int32_t sym.sitronix_proc_grip_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    int32_t arg2_00;
    uint32_t arg3;
    int *piVar4;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc04441d0;
    iStack_1c = **0xc04441d0;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc04441d4;
    if (0 < iVar2) {
        arg2 = -0x16;
        goto code_r0xc04440c4;
    }
    iVar2 = sym.strcmp(acStack_26,*(*0xc04441d4 + 0x108));
    piVar4 = *0xc04441d8;
    if (iVar2 == 0) {
        sym.mutex_lock(**0xc04441d8 + 0x70);
        arg3 = 0;
code_r0xc04440ac:
        arg2_00 = 1;
    }
    else {
        iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x10c));
        piVar4 = *0xc04441d8;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04441d8 + 0x70);
            arg3 = 1;
            goto code_r0xc04440ac;
        }
        iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x110));
        piVar4 = *0xc04441d8;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04441d8 + 0x70);
            arg3 = 2;
            goto code_r0xc04440ac;
        }
        iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x114));
        piVar4 = *0xc04441d8;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04441d8 + 0x70);
            arg3 = 3;
            goto code_r0xc04440ac;
        }
        iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x100));
        piVar4 = *0xc04441d8;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04441d8 + 0x70);
            arg3 = *(*piVar4 + 0x1ad);
            goto code_r0xc04440ac;
        }
        iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x104));
        piVar4 = *0xc04441d8;
        if (iVar3 != 0) {
            arg2 = -5;
            goto code_r0xc04440c4;
        }
        sym.mutex_lock(**0xc04441d8 + 0x70);
        arg3 = *(*piVar4 + 0x1ad);
        arg2_00 = 0;
    }
    sym.sitronix_mode_switch_value(7,arg2_00,arg3);
    sym.mutex_unlock(*piVar4 + 0x70);
code_r0xc04440c4:
    if (iStack_1c == *piVar1) {
        return arg2;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_proc_grip_write -----

// ----- BEGIN sitronix_proc_strawdata_test_write (t) [.kernel] file=0xc04441dc runtime=0xc04441dc -----

int32_t sym.sitronix_proc_strawdata_test_write(uint noname_0,int32_t arg1,int32_t arg2)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    int32_t arg2_00;
    int *piVar4;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc04442ec;
    iStack_1c = **0xc04442ec;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(arg1,acStack_26,arg2);
    iVar3 = *0xc04442f0;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc04442f0 + 0x2e4));
        piVar4 = *0xc04442f4;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04442f4 + 0x70);
            sym.sitronix_ts_enable_raw(*piVar4,0);
            sym.sitronix_mt_restore();
        }
        else {
            iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x2e8));
            piVar4 = *0xc04442f4;
            if (iVar2 == 0) {
                sym.mutex_lock(**0xc04442f4 + 0x70);
                sym.sitronix_mt_pause();
                arg2_00 = 1;
            }
            else {
                iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x2ec));
                piVar4 = *0xc04442f4;
                if (iVar3 != 0) goto code_r0xc04442dc;
                sym.mutex_lock(**0xc04442f4 + 0x70);
                sym.sitronix_mt_pause();
                arg2_00 = 2;
            }
            sym.sitronix_ts_enable_raw(*piVar4,arg2_00);
        }
        sym.mutex_unlock(*piVar4 + 0x70);
    }
    else {
code_r0xc04442dc:
        arg2 = -0x16;
    }
    if (iStack_1c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return arg2;
}

// ----- END sitronix_proc_strawdata_test_write -----

// ----- BEGIN sitronix_proc_strawdata_write (t) [.kernel] file=0xc04442f8 runtime=0xc04442f8 -----

int32_t sym.sitronix_proc_strawdata_write(uint param_1,int32_t param_2,int32_t param_3)

{
    int *piVar1;
    int iVar2;
    int iVar3;
    int32_t arg2;
    int *piVar4;
    char acStack_26 [10];
    int iStack_1c;
    
    piVar1 = *0xc04442ec;
    iStack_1c = **0xc04442ec;
    acStack_26[0] = '\0';
    acStack_26[1] = '\0';
    acStack_26[2] = '\0';
    acStack_26[3] = '\0';
    acStack_26[4] = '\0';
    acStack_26[5] = '\0';
    acStack_26[6] = '\0';
    acStack_26[7] = '\0';
    acStack_26[8] = '\0';
    acStack_26[9] = '\0';
    iVar2 = sym.sitronix_copycmd_without_line(param_2,acStack_26,param_3);
    iVar3 = *0xc04442f0;
    if (iVar2 < 1) {
        iVar2 = sym.strcmp(acStack_26,*(*0xc04442f0 + 0x2e4));
        piVar4 = *0xc04442f4;
        if (iVar2 == 0) {
            sym.mutex_lock(**0xc04442f4 + 0x70);
            sym.sitronix_ts_enable_raw(*piVar4,0);
            sym.sitronix_mt_restore();
        }
        else {
            iVar2 = sym.strcmp(acStack_26,*(iVar3 + 0x2e8));
            piVar4 = *0xc04442f4;
            if (iVar2 == 0) {
                sym.mutex_lock(**0xc04442f4 + 0x70);
                sym.sitronix_mt_pause();
                arg2 = 1;
            }
            else {
                iVar3 = sym.strcmp(acStack_26,*(iVar3 + 0x2ec));
                piVar4 = *0xc04442f4;
                if (iVar3 != 0) goto code_r0xc04442dc;
                sym.mutex_lock(**0xc04442f4 + 0x70);
                sym.sitronix_mt_pause();
                arg2 = 2;
            }
            sym.sitronix_ts_enable_raw(*piVar4,arg2);
        }
        sym.mutex_unlock(*piVar4 + 0x70);
    }
    else {
code_r0xc04442dc:
        param_3 = -0x16;
    }
    if (iStack_1c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return param_3;
}

// ----- END sitronix_proc_strawdata_write -----

// ----- BEGIN sitronix_create_sysfs (T) [.kernel] file=0xc0444350 runtime=0xc0444350 -----

int sym.sitronix_create_sysfs(int32_t arg1)

{
    int32_t arg1_00;
    uint uVar1;
    int iVar2;
    uint noname_0;
    
    uVar1 = sym.kobject_create_and_add(*0xc0444390,0);
    arg1_00 = *0xc0444394;
    *(arg1 + 0x2c) = uVar1;
    iVar2 = sym.sysfs_create_group(noname_0,arg1_00);
    if (iVar2 != 0) {
        sym.kobject_put(*(arg1 + 0x2c));
        *(arg1 + 0x2c) = 0;
    }
    return iVar2;
}

// ----- END sitronix_create_sysfs -----

// ----- BEGIN sitronix_remove_sysfs (T) [.kernel] file=0xc0444398 runtime=0xc0444398 -----

void sym.sitronix_remove_sysfs(int32_t arg1)

{
    char *arg4;
    int32_t arg1_00;
    int iVar1;
    uint32_t *puVar2;
    code *pcVar3;
    uint32_t *arg1_01;
    uint32_t *puVar4;
    uint32_t arg1_02;
    uint *puVar5;
    
    if (*(arg1 + 0x2c) == 0) {
        return;
    }
    sym.sysfs_remove_group(*(arg1 + 0x2c),*0xc04443c4);
    arg1_00 = *0xc064e6c8;
    arg4 = *0xc064e6c4;
    arg1_01 = *(arg1 + 0x2c);
    while( true ) {
        if (arg1_01 == NULL) {
            return;
        }
        if ((arg1_01[8] & 1) == 0) {
            sym.warn_slowpath_fmt(arg1_00,0x2ef,9,arg4);
        }
        iVar1 = sym.refcount_dec_and_test_checked(arg1_01 + 7);
        if (iVar1 == 0) break;
        puVar4 = arg1_01[3];
        puVar5 = arg1_01[5];
        arg1_02 = *arg1_01;
        if ((arg1_01[8] & 0xc) == 4) {
            sym.kobject_uevent(arg1_01,1);
        }
        puVar2 = arg1_01[8] & 2;
        if ((arg1_01[8] & 2) != 0) {
            sym.__kobject_del(arg1_01);
            puVar2 = puVar4;
        }
        if ((puVar5 != NULL) && (pcVar3 = *puVar5, pcVar3 != NULL)) {
            (*pcVar3)(arg1_01);
        }
        arg1_01 = puVar2;
        if (arg1_02 != 0) {
            sym.kfree_const(arg1_02);
        }
    }
    return;
}

// ----- END sitronix_remove_sysfs -----

// ----- BEGIN sitronix_create_st_dev (T) [.kernel] file=0xc0444ab4 runtime=0xc0444ab4 -----

uint32_t sym.sitronix_create_st_dev(int32_t arg1)

{
    int *piVar1;
    int iVar2;
    int32_t arg2;
    int32_t arg2_00;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uStack_28;
    int iStack_24;
    
    arg2 = *0xc0444bfc;
    iVar2 = *0xc0444bf8;
    piVar1 = *0xc0444bf4;
    iStack_24 = **0xc0444bf4;
    uStack_28 = *(*0xc0444bf8 + 4) << 0x14;
    uVar3 = sym.alloc_chrdev_region(&uStack_28,0,1,*0xc0444bfc);
    arg2_00 = *0xc0444c00;
    if (-1 < uVar3) {
        *(iVar2 + 4) = uStack_28 >> 0x14;
        sym.cdev_init(iVar2 + 8,arg2_00);
        *(iVar2 + 0x54) = arg2_00;
        *(iVar2 + 0x50) = 0;
        uVar3 = sym.cdev_add(iVar2 + 8,uStack_28,1);
        uVar4 = uVar3;
        if (uVar3 == 0) {
            uVar4 = sym.__class_create(0,arg2,iVar2 + 0x68);
            *(iVar2 + 0x68) = uVar4;
            if (uVar4 < 0xfffff001) {
                uVar4 = sym.device_create(uVar4,0,*(iVar2 + 4) << 0x14,0);
                if (uVar4 < 0xfffff001) {
                    sym.__init_waitqueue_head(arg1 + 0x29c);
                    *(arg1 + 0x2a8) = 0;
                    goto code_r0xc0444bd4;
                }
                uVar4 = 0xffffffed;
                sym.class_destroy(*(iVar2 + 0x68));
            }
            else {
                sym.__unregister_chrdev(*(iVar2 + 4),0,0x100);
            }
            sym.cdev_del(*0xc0444c04);
        }
        sym.unregister_chrdev_region(uStack_28,1);
        *(iVar2 + 0x68) = 0;
        uVar3 = uVar4;
    }
code_r0xc0444bd4:
    if (iStack_24 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return uVar3;
}

// ----- END sitronix_create_st_dev -----

// ----- BEGIN sitronix_remove_st_dev (T) [.kernel] file=0xc0444c0c runtime=0xc0444c0c -----

void sym.sitronix_remove_st_dev(void)

{
    int iVar1;
    size_t arg1;
    uint32_t arg2;
    uint32_t uVar2;
    uint32_t uVar3;
    
    iVar1 = *0xc0444c50;
    if (*(*0xc0444c50 + 0x68) == 0) {
        return;
    }
    arg2 = *(*0xc0444c50 + 4) * 0x100000;
    sym.device_destroy(*(*0xc0444c50 + 0x68),arg2);
    sym.class_destroy(*(iVar1 + 0x68));
    sym.cdev_del(iVar1 + 8);
    uVar3 = arg2 + 1;
    while (arg2 < uVar3) {
        uVar2 = ((arg2 >> 0x14) + 1) * 0x100000;
        if (uVar3 < uVar2) {
            uVar2 = uVar3;
        }
        arg1 = sym.__unregister_chrdev_region(arg2 >> 0x14,arg2 & 0xfffff,uVar2 - arg2);
        sym.kfree(arg1);
        arg2 = uVar2;
    }
    return;
}

// ----- END sitronix_remove_st_dev -----

// ----- BEGIN sitronix_copy_to_user (T) [.kernel] file=0xc0444c54 runtime=0xc0444c54 -----

int sym.sitronix_copy_to_user(int32_t arg1,int32_t arg2,int32_t arg3)

{
    uint *puVar1;
    int32_t arg1_00;
    int arg2_00;
    int iVar2;
    uint noname_1;
    
    puVar1 = *0xc0444ce0;
    ***0xc0444ce0 = 0;
    arg2_00 = sym.snprintf(*puVar1,0x1008,*0xc0444ce4,arg1);
    arg1_00 = *0xc0444cec;
    if (arg2_00 < 0) {
        iVar2 = arg2_00;
        if (**0xc0444ce8 == '\0') {
            **0xc0444ce8 = '\x01';
            sym.warn_slowpath_fmt(arg1_00,0x96,9,NULL);
        }
    }
    else {
        iVar2 = sym._copy_to_user_45(arg3,noname_1,arg2_00);
    }
    if (iVar2 < 0) {
        arg2_00 = 0;
    }
    return arg2_00;
}

// ----- END sitronix_copy_to_user -----

// ----- BEGIN sitronix_proc_swu_read (t) [.kernel] file=0xc0444cf0 runtime=0xc0444cf0 -----

uint sym.sitronix_proc_swu_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444d24,*(**0xc0444d20 + 0x193),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_swu_read -----

// ----- BEGIN sitronix_proc_glove_read (t) [.kernel] file=0xc0444d28 runtime=0xc0444d28 -----

uint sym.sitronix_proc_glove_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444d5c,*(**0xc0444d58 + 0x194),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_glove_read -----

// ----- BEGIN sitronix_proc_charge_read (t) [.kernel] file=0xc0444d60 runtime=0xc0444d60 -----

uint sym.sitronix_proc_charge_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444d94,*(**0xc0444d90 + 0x195),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_charge_read -----

// ----- BEGIN sitronix_proc_jittersuppress_read (t) [.kernel] file=0xc0444d98 runtime=0xc0444d98 -----

uint sym.sitronix_proc_jittersuppress_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444dcc,*(**0xc0444dc8 + 0x196),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_jittersuppress_read -----

// ----- BEGIN sitronix_proc_palm_read (t) [.kernel] file=0xc0444dd0 runtime=0xc0444dd0 -----

uint sym.sitronix_proc_palm_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444e04,*(**0xc0444e00 + 0x197),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_palm_read -----

// ----- BEGIN sitronix_proc_headphone_read (t) [.kernel] file=0xc0444e08 runtime=0xc0444e08 -----

uint sym.sitronix_proc_headphone_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444e3c,*(**0xc0444e38 + 0x198),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_headphone_read -----

// ----- BEGIN sitronix_proc_grip_read (t) [.kernel] file=0xc0444e40 runtime=0xc0444e40 -----

uint sym.sitronix_proc_grip_read(uint noname_0,int32_t arg1,uint noname_2,int32_t arg2)

{
    uint uVar1;
    
    uVar1 = sym.sitronix_copy_to_user(*0xc0444e74,*(**0xc0444e70 + 0x199),arg1);
    *arg2 = uVar1;
    *(arg2 + 4) = 0;
    return 0;
}

// ----- END sitronix_proc_grip_read -----

// ----- BEGIN sitronix_do_upgrade_flash_icp_all (T) [.kernel] file=0xc0445bf4 runtime=0xc0445bf4 -----

//WARNING: Type propagation algorithm not settling

int sym.sitronix_do_upgrade_flash_icp_all(void)

{
    int *piVar1;
    int32_t *piVar2;
    int32_t arg1;
    int32_t iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    uint16_t uStack_3e;
    int32_t iStack_3c;
    uint32_t uStack_38;
    uint32_t uStack_34;
    uint32_t uStack_30;
    uint32_t auStack_2c [4];
    
    arg1 = *0xc0445eac;
    piVar2 = *0xc0445ea8;
    piVar1 = *0xc0445ea4;
    iStack_3c = 0;
    auStack_2c[2] = **0xc0445ea4;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    auStack_2c[1] = 0;
    auStack_2c[0] = 0;
    *(**0xc0445ea8 + 0x91) = 1;
    iVar4 = sym.st_check_fw(arg1,&iStack_3c,&uStack_30,auStack_2c + 1);
    if (((iVar4 < 0) || (0x13000 < uStack_38)) || (iVar4 = sym.st_check_cfg(arg1 + uStack_38,auStack_2c), iVar4 < 0))
    {
        iVar4 = -5;
        goto code_r0xc0445c68;
    }
    sym.st_irq_off();
    if (*(*piVar2 + 0x2de) == '\0') {
        uStack_34 = *(arg1 + uStack_38 + 0xf) + *(arg1 + uStack_38 + 0xe) * 0x100;
        if (uStack_38 + uStack_34 < 0x13001) {
            uStack_34 = *(arg1 + uStack_38 + uStack_34);
            if (uStack_34 <= *(*piVar2 + 0x15)) {
                iVar4 = 0;
                uStack_30 = 0;
                auStack_2c[0] = 0;
                goto code_r0xc0445c68;
            }
            goto code_r0xc0445d44;
        }
    }
    else {
code_r0xc0445d44:
        iVar5 = sym.st_icp_flash_wakeup(&uStack_3e);
        if ((iVar5 != 0) && (iVar5 = sym.st_icp_flash_read(*0xc0445eb0,0,uStack_30), -1 < iVar5)) {
            iVar5 = sym.st_compare_array(*0xc0445eb0,*0xc0445eac,uStack_30);
            if (iVar5 == 0) {
                uStack_30 = 0;
            }
            sym.st_icp_flash_read(*0xc0445eb0,uStack_38,auStack_2c[0]);
            iVar5 = sym.st_compare_array(*0xc0445eb0,arg1 + uStack_38,auStack_2c[0]);
            if (iVar5 == 0) {
                auStack_2c[0] = 0;
            }
            iVar5 = sym.st_icp_flash_wakeup(&uStack_3e);
            if ((iVar5 != 0) && (iVar5 = sym.st_icp_flash_lock(0), iVar3 = *0xc0445eb0, iVar5 != 0)) {
                if (auStack_2c[0] != 0) {
                    iVar5 = 4;
                    do {
                        sym.st_icp_flash_write(arg1 + uStack_38,uStack_38,auStack_2c[0],uStack_3e);
                        sym.st_icp_flash_read(iVar3,uStack_38,auStack_2c[0]);
                        iVar6 = sym.st_compare_array(iVar3,arg1 + uStack_38,auStack_2c[0]);
                        if (iVar6 == 0) break;
                        iVar5 = iVar5 + -1;
                    } while (iVar5 != 0);
                }
                iVar3 = *0xc0445eb0;
                if (uStack_30 != 0) {
                    iVar5 = 4;
                    do {
                        sym.st_icp_flash_write(arg1 + iStack_3c,iStack_3c,uStack_30,uStack_3e);
                        sym.st_icp_flash_read(iVar3,0,uStack_30);
                        iVar6 = sym.st_compare_array(iVar3,arg1 + iStack_3c,uStack_30);
                        if (iVar6 == 0) break;
                        iVar5 = iVar5 + -1;
                    } while (iVar5 != 0);
                }
                sym.st_icp_flash_lock(1);
                goto code_r0xc0445c68;
            }
        }
    }
    iVar4 = -1;
code_r0xc0445c68:
    sym.sitronix_ts_reset_device(*piVar2);
    sym.st_irq_on();
    iVar5 = *piVar2;
    *(iVar5 + 0x91) = 0;
    if ((-1 < iVar4) && ((auStack_2c[0] != 0 || (uStack_30 != 0)))) {
        sym.sitronix_ts_get_device_info(iVar5);
        iVar4 = 1;
    }
    if (auStack_2c[2] != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return iVar4;
}

// ----- END sitronix_do_upgrade_flash_icp_all -----

// ----- BEGIN sitronix_spi_pram_rw (T) [.kernel] file=0xc0445eb4 runtime=0xc0445eb4 -----

int sym.sitronix_spi_pram_rw(int32_t arg1,int32_t arg2,int32_t arg3,int32_t arg4)

{
    int *piVar1;
    int32_t *piVar2;
    int *piVar3;
    int iVar4;
    int iVar5;
    size_t in_stack_00000000;
    
    piVar3 = *0xc0446098;
    piVar2 = *0xc0446094;
    piVar1 = *0xc0446090;
    iVar5 = 0;
    while( true ) {
        if (in_stack_00000000 < 1) {
            return 0;
        }
        iVar4 = iVar5 + arg2;
        *(*piVar1 + 1) = iVar4 >> 0x10;
        *(*piVar1 + 2) = iVar4 >> 8;
        *(*piVar1 + 3) = iVar4;
        if (in_stack_00000000 < 0x101) break;
        if (arg1 == 0) {
            iVar4 = *piVar1;
            sym.memcpy(iVar4 + 4,arg3 + iVar5,0x100);
            iVar4 = sym.sitronix_ts_addrmode_write_2(*piVar2,iVar4,0x103);
            if (iVar4 < 0) {
                return iVar4;
            }
        }
        else {
            *(*piVar1 + 1) = ~(~((*(*piVar1 + 1) << 0x19) >> 0x18) >> 1);
            iVar4 = *piVar1;
            sym.memset(iVar4 + 4,0,0x101);
            iVar4 = (**(*(*piVar2 + 0x10) + 0x28))(iVar4,3,*piVar3,0x101,*(*(*piVar2 + 0x10) + 0x14));
            if (iVar4 < 0) {
                return iVar4;
            }
            sym.memcpy(arg4 + iVar5,*piVar3 + iVar4 + 1,0x100);
        }
        iVar5 = iVar5 + 0x100;
        in_stack_00000000 = in_stack_00000000 - 0x100;
    }
    if (arg1 == 0) {
        iVar4 = *piVar1;
        sym.memcpy(iVar4 + 4,arg3 + iVar5,in_stack_00000000);
        iVar5 = sym.sitronix_ts_addrmode_write_2(*piVar2,iVar4,in_stack_00000000 + 3 & 0xffff);
        if (-1 < iVar5) {
            return 0;
        }
        return iVar5;
    }
    *(*piVar1 + 1) = ~(~((*(*piVar1 + 1) << 0x19) >> 0x18) >> 1);
    iVar4 = *piVar1;
    sym.memset(iVar4 + 4,0,in_stack_00000000 + 1);
    iVar4 = (**(*(*piVar2 + 0x10) + 0x28))
                      (iVar4,3,*piVar3,in_stack_00000000 + 1 & 0xffff,*(*(*piVar2 + 0x10) + 0x14));
    if (-1 < iVar4) {
        sym.memcpy(arg4 + iVar5,*piVar3 + iVar4 + 1,in_stack_00000000);
        return 0;
    }
    return iVar4;
}

// ----- END sitronix_spi_pram_rw -----

// ----- BEGIN sitronix_spi_hdl_fw (T) [.kernel] file=0xc044609c runtime=0xc044609c -----

//WARNING: Type propagation algorithm not settling

uint sym.sitronix_spi_hdl_fw(int32_t arg1)

{
    int *piVar1;
    int *piVar2;
    int iVar3;
    uint uVar4;
    int iVar5;
    char *src;
    int iStack_58;
    uint uStack_50;
    int iStack_4c;
    int32_t iStack_48;
    uint uStack_44;
    int aiStack_40 [2];
    uchar auStack_36 [4];
    uchar uStack_32;
    uchar uStack_31;
    uchar uStack_30;
    uchar uStack_2f;
    uchar uStack_2e;
    uchar uStack_2d;
    int iStack_2c;
    
    piVar1 = *0xc0446488;
    uStack_50 = 0;
    iStack_4c = 0;
    iStack_2c = **0xc0446488;
    iStack_48 = 0;
    uStack_44 = 0;
    aiStack_40[0] = 0;
    aiStack_40[1] = 0;
    iVar3 = sym.st_check_fw(arg1,&uStack_50,&uStack_44,aiStack_40 + 1);
    if (iVar3 < 0) {
        iVar3 = **0xc044648c;
        src = *0xc0446490;
    }
    else {
        iVar3 = sym.st_check_cfg(arg1 + iStack_4c,aiStack_40);
        piVar2 = *0xc044648c;
        if (-1 < iVar3) {
            iStack_58 = 4;
code_r0xc0446140:
            do {
                do {
                    do {
                        do {
                            do {
                                do {
                                    do {
                                        do {
                                            do {
                                                do {
                                                    iStack_58 = iStack_58 + -1;
                                                    if (iStack_58 == 0) goto code_r0xc0446114;
                                                    sym.sitronix_ts_reset_device(*piVar2);
                                                    uStack_31 = 0x53;
                                                    uStack_30 = 0x71;
                                                    uStack_2f = 0x23;
                                                    uStack_2e = 0xa5;
                                                    uStack_2d = 0x3c;
                                                    iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                                                } while (iVar3 < 0);
                                                uStack_31 = 0x53;
                                                uStack_30 = 0x71;
                                                uStack_2f = 0x23;
                                                uStack_2e = 5;
                                                uStack_2d = 0x55;
                                                iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                                            } while (iVar3 < 0);
                                            uStack_31 = 0x53;
                                            uStack_30 = 0x71;
                                            uStack_2f = 0x23;
                                            uStack_2e = 0x55;
                                            uStack_2d = 0x55;
                                            iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                                        } while (iVar3 < 0);
                                        uStack_2e = 0x14;
                                        uStack_31 = 0x53;
                                        uStack_30 = 0x71;
                                        uStack_2f = 0x23;
                                        uStack_2d = 0x55;
                                        iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                                    } while (iVar3 < 0);
                                    uStack_31 = 0;
                                    uStack_2f = 0;
                                    uStack_30 = 0xf3;
                                    uStack_2e = 0x5a;
                                    uStack_2d = 0xa5;
                                    iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                                } while (iVar3 < 0);
                                uStack_31 = 0;
                                uStack_30 = 0xf3;
                                uStack_2f = 2;
                                uStack_2e = 0;
                                uStack_2d = 1;
                                iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                            } while (iVar3 < 0);
                            uStack_31 = 0;
                            uStack_30 = 0xf3;
                            uStack_2f = 2;
                            uStack_2e = 0;
                            uStack_2d = 0;
                            iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                        } while (iVar3 < 0);
                        uStack_31 = 0;
                        uStack_30 = 0xf3;
                        uStack_2f = 2;
                        uStack_2e = 0;
                        uStack_2d = 1;
                        iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
                    } while (((iVar3 < 0) || (iVar3 = sym.sitronix_spi_pram_rw(0,0x7f0000,arg1,0), iVar3 < 0)) ||
                            (((iVar3 = *0xc0446494, *(*piVar2 + 0x14) != -0x7d || (0x46 < *(*piVar2 + 0x29))) &&
                             ((*(arg1 + 0x84) == '\0' &&
                              (iVar5 = sym.sitronix_spi_pram_rw(0,0x400000,arg1 + 0x10000,0), iVar3 = *0xc0446494,
                              iVar5 < 0))))));
                    do {
                        sym.sitronix_spi_pram_rw(1,iVar3,0,auStack_36);
                        iVar5 = sym.st_compare_array(arg1 + iVar3 + -0x7f0000,auStack_36,4);
                        if (iVar5 < 0) goto code_r0xc0446140;
                        iVar3 = iVar3 + 0x1000;
                    } while (iVar3 != *0xc0446498);
                    sym.sitronix_spi_pram_rw(0,iStack_48,arg1 + iStack_4c,0);
                    sym.sitronix_spi_pram_rw(1,iStack_48 + aiStack_40[0] + -4,0,auStack_36);
                    iVar3 = sym.st_compare_array(arg1 + iStack_4c + aiStack_40[0] + -4,auStack_36,4);
                } while (iVar3 < 0);
                uStack_31 = 0;
                uStack_30 = 0xf3;
                uStack_2e = 0;
                uStack_2f = 2;
                uStack_2d = 3;
                iVar3 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_32,5);
            } while (iVar3 < 0);
            uVar4 = 0;
            goto code_r0xc0446424;
        }
        iVar3 = **0xc044648c;
        src = *0xc044649c;
    }
    sym.strlcpy(iVar3 + 0x98,src,100);
code_r0xc0446114:
    uVar4 = 0xffffffff;
code_r0xc0446424:
    if (iStack_2c == *piVar1) {
        return uVar4;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_spi_hdl_fw -----

// ----- BEGIN sitronix_do_upgrade_hostdownload (T) [.kernel] file=0xc04464a0 runtime=0xc04464a0 -----

uint sym.sitronix_do_upgrade_hostdownload(void)

{
    int *piVar1;
    int *piVar2;
    int iVar3;
    uint extraout_r1;
    int32_t arg2;
    ulong uVar4;
    uchar uStack_2a;
    uchar uStack_29;
    uchar uStack_28;
    uchar uStack_27;
    uchar uStack_26;
    uchar uStack_25;
    int iStack_24;
    
    piVar2 = *0xc0446644;
    piVar1 = *0xc0446640;
    iStack_24 = **0xc0446640;
    *(**0xc0446644 + 0x91) = 1;
    sym.st_irq_off();
    iVar3 = sym.sitronix_spi_hdl_fw(*0xc0446648);
    if (iVar3 < 0) {
        sym.strlcpy(*piVar2 + 0x98,*0xc044664c,100);
        uVar4 = CONCAT44(extraout_r1,iVar3);
    }
    else {
        uStack_29 = 0;
        uStack_28 = 0xf3;
        uStack_27 = 0;
        uStack_26 = 0;
        uStack_25 = 0;
        sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
        uStack_28 = 0xf0;
        uStack_27 = 6;
        uStack_29 = 0;
        uStack_26 = 0;
        uStack_25 = 1;
        sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
        sym.msleep(0x14,arg2);
        uStack_27 = 0x23;
        uStack_26 = 0x50;
        uStack_29 = 0x53;
        uStack_28 = 0x71;
        uStack_25 = 0x4c;
        sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
        uStack_27 = 0x23;
        uStack_26 = 0x55;
        uStack_29 = 0x53;
        uStack_28 = 0x71;
        uStack_25 = 0x4c;
        sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
        uStack_27 = 0x23;
        uStack_26 = 0x41;
        uStack_29 = 0x53;
        uStack_28 = 0x71;
        uStack_25 = 0x4c;
        sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
        uStack_27 = 0x23;
        uStack_26 = 0x5a;
        uStack_29 = 0x53;
        uStack_28 = 0x71;
        uStack_25 = 0xc3;
        uVar4 = sym.sitronix_ts_addrmode_write_2(*piVar2,&uStack_2a,5);
    }
    sym.msleep(0x14,uVar4 >> 0x20);
    sym.st_irq_on();
    *(*piVar2 + 0x91) = 0;
    if (iStack_24 != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return uVar4;
}

// ----- END sitronix_do_upgrade_hostdownload -----

// ----- BEGIN sitronix_do_upgrade (T) [.kernel] file=0xc0446650 runtime=0xc0446650 -----

uint sym.sitronix_do_upgrade(void)

{
    int *piVar1;
    int *piVar2;
    uint32_t *puVar3;
    void *s1;
    int iVar4;
    void *s2;
    uint32_t uVar5;
    int iVar6;
    uint uVar7;
    uint32_t *arg2;
    uint32_t *puStack_20;
    int iStack_1c;
    
    puVar3 = *0xc0446748;
    piVar2 = *0xc0446744;
    piVar1 = *0xc0446740;
    iStack_1c = **0xc0446740;
    puStack_20 = NULL;
    if (*(**0xc0446744 + 0x2df) == '\0') {
        arg2 = *0xc0446748 + 1;
        **0xc0446748 = 0;
        iVar6 = 0;
        do {
            iVar4 = sym.request_firmware(&puStack_20,arg2,*(*piVar2 + 4) + 0x10);
            s1 = *0xc044674c;
            if (iVar4 == 0) {
                uVar5 = *puStack_20;
                s2 = puStack_20[1];
                if (0x13000 < uVar5) {
                    uVar5 = 0x13000;
                }
                *puVar3 = uVar5;
                sym.memcpy(s1,s2,*puVar3);
                *(*piVar2 + 0x2df) = 1;
                goto code_r0xc0446708;
            }
            iVar6 = iVar6 + 1;
        } while (iVar6 != 3);
        uVar7 = 0xfffffffe;
    }
    else {
code_r0xc0446708:
        if (*(*(*piVar2 + 0x10) + 1) == '\0') {
            uVar7 = sym.sitronix_do_upgrade_hostdownload();
        }
        else {
            uVar7 = sym.sitronix_do_upgrade_flash_icp_all();
        }
        sym.release_firmware(puStack_20);
        *puVar3 = 0;
    }
    if (iStack_1c != *piVar1) {
    //WARNING: Subroutine does not return
        sym.__stack_chk_fail();
    }
    return uVar7;
}

// ----- END sitronix_do_upgrade -----

// ----- BEGIN sitronix_replace_dump_buf (T) [.kernel] file=0xc0446750 runtime=0xc0446750 -----

void sym.sitronix_replace_dump_buf(void)

{
    char cVar1;
    void *pvVar2;
    char *pcVar3;
    char *pcVar4;
    
    pvVar2 = *0xc0446778;
    sym.memset(*0xc0446778,0,0x100);
    pcVar4 = pvVar2 + -1;
    pcVar3 = *0xc044677c;
    do {
        cVar1 = *pcVar3;
        pcVar4 = pcVar4 + 1;
        *pcVar4 = cVar1;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    return;
}

// ----- END sitronix_replace_dump_buf -----

// ----- BEGIN sitronix_vfswrite (T) [.kernel] file=0xc0446908 runtime=0xc0446908 -----

int32_t sym.sitronix_vfswrite(int32_t param_1,uint param_2,uint param_3,int32_t param_4)

{
    int32_t arg2;
    int32_t arg3;
    int32_t extraout_r2;
    int32_t arg1;
    
    if (*(*0xc044691c + 0x48) == '\0') {
        return param_1;
    }
    arg1 = *((&stack0xfffffff0 & 0xffffe000) + 8);
    sym.set_fs_3(0);
    sym.vfs_write(param_1,arg2,arg3,param_4);
    sym.set_fs_3(arg1);
    return extraout_r2;
}

// ----- END sitronix_vfswrite -----

// ----- BEGIN sitronix_set_default_test_criteria (T) [.kernel] file=0xc04495b8 runtime=0xc04495b8 -----

void sym.sitronix_set_default_test_criteria(void)

{
    int iVar1;
    
    iVar1 = **0xc044961c;
    *(iVar1 + 0x2d4) = *0xc0449620;
    *(iVar1 + 0x2d8) = 3000;
    *(iVar1 + 0x2b0) = 0x1c2;
    *(iVar1 + 0x2b4) = 100;
    *(iVar1 + 0x2b8) = 0x4b0;
    *(iVar1 + 700) = 500;
    *(iVar1 + 0x2c0) = 0;
    *(iVar1 + 0x2c4) = 0x50;
    *(iVar1 + 0x2c8) = 0x7d;
    *(iVar1 + 0x2cc) = 0x1e;
    *(iVar1 + 0x2d0) = 900;
    return;
}

// ----- END sitronix_set_default_test_criteria -----

// ----- BEGIN sitronix_replace_test_cmd (T) [.kernel] file=0xc0449624 runtime=0xc0449624 -----

void sym.sitronix_replace_test_cmd(void)

{
    return;
}

// ----- END sitronix_replace_test_cmd -----

// ----- BEGIN sitronix_request_test_criteria (T) [.kernel] file=0xc0449628 runtime=0xc0449628 -----

uint sym.sitronix_request_test_criteria(void)

{
    return 0;
}

// ----- END sitronix_request_test_criteria -----

// ----- BEGIN sitronix_touch_selftest (T) [.kernel] file=0xc0449630 runtime=0xc0449630 -----

void sym.sitronix_touch_selftest(void)

{
    int *piVar1;
    int32_t *piVar2;
    char *pcVar3;
    int iVar4;
    uint uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int iVar10;
    char *pcVar11;
    uint32_t auStack_78 [2];
    int32_t iStack_70;
    int *piStack_6c;
    uint uStack_68;
    uint uStack_64;
    uint8_t uStack_60;
    uint8_t uStack_5f;
    char acStack_5e [50];
    int iStack_2c;
    
    piVar2 = *0xc04498f0;
    pcVar3 = *0xc04498ec;
    iVar10 = *0xc04498e8;
    piVar1 = *0xc04498e4;
    iStack_2c = **0xc04498e4;
    *(*0xc04498e8 + 0x48) = 1;
    pcVar3 = sym.filp_open(pcVar3,0x241,0x1a4);
    piStack_6c = piVar1;
    iStack_70 = *((auStack_78 & 0xffffe000) + 8);
    if (0xfffff000 < pcVar3) {
        pcVar3 = NULL;
        *(iVar10 + 0x48) = 0;
    }
    sym.set_fs_8(0);
    uStack_68 = 0;
    uStack_64 = 0;
    sym.sitronix_ts_irq_enable(*piVar2,0);
    iVar4 = *piVar2;
    *(iVar4 + 0x91) = 1;
    sym.mutex_lock(iVar4 + 0x70);
    sym.st_record_ic_info(pcVar3,&uStack_68);
    sym.sitronix_get_ic_position(&uStack_60);
    auStack_78[0] = uStack_60 >> 4;
    sym.snprintf(acStack_5e,0x32,*0xc04498f4,(uStack_60 & 1) << 4 | uStack_5f);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    iVar4 = sym.st_test_normal_rawdata(pcVar3,&uStack_68);
    pcVar11 = *0xc04498f8;
    if (iVar4 != 0) {
        pcVar11 = *0xc04498fc;
    }
    sym.strcpy(acStack_5e,pcVar11);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    uVar6 = sym.st_test_open_mux_on_off(pcVar3,&uStack_68);
    pcVar11 = *0xc0449900;
    if (uVar6 != 0) {
        pcVar11 = *0xc0449904;
    }
    sym.strcpy(acStack_5e,pcVar11);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    uVar7 = sym.st_test_short_odd(pcVar3,&uStack_68);
    pcVar11 = *0xc0449908;
    if (uVar7 != 0) {
        pcVar11 = *0xc044990c;
    }
    sym.strcpy(acStack_5e,pcVar11);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    uVar8 = sym.st_test_short_even(pcVar3,&uStack_68);
    pcVar11 = *0xc0449910;
    if (uVar8 != 0) {
        pcVar11 = *0xc0449914;
    }
    sym.strcpy(acStack_5e,pcVar11);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    uVar9 = sym.st_test_std(pcVar3,&uStack_68);
    pcVar11 = *0xc0449918;
    if (uVar9 != 0) {
        pcVar11 = *0xc044991c;
    }
    sym.strcpy(acStack_5e,pcVar11);
    uVar5 = sym.strlen(acStack_5e);
    sym.sitronix_vfswrite(pcVar3,acStack_5e,uVar5,&uStack_68);
    if ((uVar7 | uVar6 | uVar8 | uVar9) < 0) {
        iVar4 = -1;
    }
    else {
        iVar4 = uVar6 + uVar7 + uVar8 + uVar9;
    }
    sym.set_fs_8(iStack_70);
    if (*(iVar10 + 0x48) != '\0') {
        sym.filp_close(pcVar3,0);
    }
    iVar10 = *piVar2;
    *(*0xc0449920 + 8) = iVar4 == 0;
    sym.mutex_unlock(iVar10 + 0x70);
    sym.sitronix_ts_mt_reset_process();
    iVar10 = *piVar2;
    *(iVar10 + 0x91) = 0;
    sym.sitronix_ts_irq_enable(iVar10,1);
    if (iStack_2c == *piStack_6c) {
        return;
    }
    //WARNING: Subroutine does not return
    sym.__stack_chk_fail();
}

// ----- END sitronix_touch_selftest -----

// ----- BEGIN sitronix_selftest_result_read (T) [.kernel] file=0xc0449924 runtime=0xc0449924 -----

uint8_t sym.sitronix_selftest_result_read(void)

{
    return *(*0xc0449934 + 8) ^ 1;
}

// ----- END sitronix_selftest_result_read -----

// ----- BEGIN sitronix_ts_init (t) [.kernel] file=0xc091a3a8 runtime=0xc091a3a8 -----

int sym.sitronix_ts_init(void)

{
    int iVar1;
    
    iVar1 = sym.sitronix_ts_i2c_init();
    if (iVar1 == 0) {
        sym.__platform_driver_register(*0xc091a3cc,0);
    }
    return iVar1;
}

// ----- END sitronix_ts_init -----
