// pseudo-c export driven by kallsyms-sitronix-20260704-092316.txt

// ----- BEGIN sitronix_ts_input_dev_init (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_input_dev_init (int32_t arg1, int32_t arg_0h, int32_t arg_4h, int32_t arg_0h_2, int32_t arg_4h_2, int32_t arg_0h_3, int32_t arg_4h_3, int32_t arg_0h_4, int32_t arg_4h_4, int32_t arg_0h_5, int32_t arg_4h_5) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cad8(x)
        push (r0, r1, r4, r5, r6, lr)
        r4 = r0       // arg1
        sym.input_allocate_device () // sym.input_allocate_device(0x0)
        (a, b) = compare (r0, 0)
        [r4 + 8] = r0
        mvneq r5, 0xb
        je 0xc043c644 // likely
        goto loc_0xc043c2e0;
    loc_0xc043c644:
        r0 = r5
        sp += 8
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043c608: // orphan
         r1 = [r4 + 8]
         ldr r0, [r6, r5, lsl 2]
         r5 += 1
         r1 += 0x1c
         sym._set_bit ()          // sym._set_bit(-1, 0x1b)
         (a, b) = compare (r5, 3)
         bne 0xc043c608           // likely

         goto loc_0xc043c624;
    loc_0xc043c624: // orphan
         r0 = [r4 + 8]
         sym.input_register_device () // sym.input_register_device(-1, 0x0)
         r5 = r0 - 0
         je 0xc043c644            // unlikely

         goto loc_0xc043c634;
    loc_0xc043c634: // orphan
         r0 = [r4 + 8]
         sym.input_free_device () // sym.input_free_device(-1)
         r3 = 0
         [r4 + 8] = r3

}

// ----- END sitronix_ts_input_dev_init -----

// ----- BEGIN sitronix_ts_remove (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_remove (int32_t arg1) {
        push (r4, r5, r6, lr)
        r4 = [r0 + 0x74] // arg1
        (a, b) = compare (r4, 0)
        je 0xc043c6e0 // unlikely
        goto loc_0xc043c664;
    loc_0xc043c6e0:
        r5 = [0xc043c6e8] // [0xc043c72c:4]=0xc0a5d4c8
        r0 = [r5]
        (a, b) = compare (r0, 0)
        je 0xc043c6fc // likely
        goto loc_0xc043c6f0;
    loc_0xc043c6fc:
        r0 = [r5 + 4]
        (a, b) = compare (r0, 0)
        je 0xc043c714 // unlikely
        goto loc_0xc043c708;
    loc_0xc043c714:
        (a, b) = compare (r4, 0)
        je 0xc043c724 // likely
        goto loc_0xc043c71c;
    loc_0xc043c724:
        r0 = 0
        pop (r4, r5, r6, pc)
        goto loc_0xc043c688;
        return r0;
    loc_0xc043c688:
        sym.destroy_workqueue () // sym.destroy_workqueue(0x0)
        
    loc_0xc043c68c:
        r0 = r4 + 0x58
        sym.fb_unregister_client () // sym.fb_unregister_client(0x58)
        r0 = [r4 + 0x64]
        (a, b) = compare (r0, 0)
        ble 0xc043c6a8 // likely
        goto loc_0xc043c6a0;
        return r0;
    loc_0xc043c6a0:
        r1 = r4
        sym.free_irq () // sym.free_irq(0x0, 0x0)
        
    loc_0xc043c6a8:
        r0 = [r4 + 0xc]
        (a, b) = compare (r0, 0)
        je 0xc043c6c0 // unlikely
        goto loc_0xc043c6b4;
        return r0;
    loc_0xc043c6b4:
        sym.input_unregister_device () // sym.input_unregister_device(0x0)
        r0 = [r4 + 0xc]
        sym.input_free_device () // sym.input_free_device(-1)
        
    loc_0xc043c6c0:
        r0 = [r4 + 8]
        (a, b) = compare (r0, 0)
        je 0xc043c6d8 // unlikely
        goto loc_0xc043c6cc;
        return r0;
    loc_0xc043c6cc:
        sym.input_unregister_device () // sym.input_unregister_device(0x0)
        r0 = [r4 + 8]
        sym.input_free_device () // sym.input_free_device(-1)
        
    loc_0xc043c6d8:
        r0 = r4 + 0x70
        sym.mutex_destroy () // sym.mutex_destroy(0x70)
        return r0;
    loc_0xc043c708: // orphan
         sym.kfree ()             // sym.kfree(0x0)
         r3 = 0
         [r5 + 4] = r3

         goto loc_0xc043c6f0;
    loc_0xc043c6f0: // orphan
         sym.kfree ()             // sym.kfree(0x0)
         r3 = 0
         [r5] = r3

         goto loc_0xc043c664;
    loc_0xc043c664: // orphan
         sym.sitronix_mt_stop ()
         sym.sitronix_remove_proc ()
         r0 = r4
         sym.sitronix_remove_st_dev ()
         r0 = r4
         sym.sitronix_remove_sysfs () // sym.sitronix_remove_sysfs(0x0)
         r0 = [r4 + 0x30]
         (a, b) = compare (r0, 0)
         je 0xc043c68c            // unlikely

}

// ----- END sitronix_ts_remove -----

// ----- BEGIN sitronix_ts_pen_up (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_pen_up (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_ts_pen_allup @ 0xc043c7bc(x)
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d3e8(x)
        push (r4, lr)
        r3 = r1       // arg2
        r2 = 0x2f     // '/'
        r1 = 3
        r4 = r0       // arg1
        sym.input_event () // sym.input_event(0x0, 0x3, 0x2f, 0x0)
        r2 = 0
        r0 = r4
        r1 = r2
        sym.input_mt_report_slot_state () // sym.input_mt_report_slot_state(0x0, 0x0, 0x0)
        r0 = r4
        r2 = 0
        r1 = 0x30     // '0'
        sym.input_report_abs () // sym.input_report_abs(0x0, 0x30)
        r0 = r4
        r2 = 0
        r1 = 0x3a     // ':'
        pop (r4, lr)  // r13
        goto sym.input_report_abs // sym.input_report_abs(0x0, 0x3a)
}

// ----- END sitronix_ts_pen_up -----

// ----- BEGIN sitronix_ts_pen_allup (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_pen_allup (int32_t arg1) {
        // CALL XREF from sym.sitronix_fb_notifier_callback @ 0xc043c924(x)
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d10c(x)
        push (r4, r5, r6, lr)
        r4 = r0       // arg1
        r5 = 0
        
    loc_0xc043c788:
        // CODE XREF from sym.sitronix_ts_pen_allup @ 0xc043c7c4(x)
        r3 = (byte) [r4 + 0x1e]
        (a, b) = compare (r5, r3)
        blt 0xc043c7b4 // likely
        goto loc_0xc043c794;
        return r0;
    loc_0xc043c794:
        r0 = [r4 + 8]
        r3 = 0
        r2 = 0x14a
        r1 = 1
        sym.input_event () // sym.input_event(-1, 0x1, 0x14a, 0x0)
        r0 = [r4 + 8]
        pop (r4, r5, r6, lr)
        goto sym.input_sync
}

// ----- END sitronix_ts_pen_allup -----

// ----- BEGIN sitronix_ts_irq_enable (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_irq_enable (int32_t arg1, int32_t arg2) {
        // XREFS: CALL 0xc043c978  CALL 0xc043ce3c  CALL 0xc0440df4
        // XREFS: CALL 0xc0440e34  CALL 0xc0441200  CALL 0xc0441240
        // XREFS: CALL 0xc044452c  CALL 0xc0445220  CALL 0xc044524c
        // XREFS: CALL 0xc04496ac  CALL 0xc04498c0
        push (r4, r5, r6, lr)
        r5 = r1 - 0   // arg2
        r4 = [0xc043c7d8] // [0xc043c80c:4]=0xc0a2d240
        r3 = (byte) [r4 + 0xa0]
        je 0xc043c7f8 // likely
        goto loc_0xc043c7dc;
    while (/* 0xc043c7f8 */) {
        // CODE XREF from sym.sitronix_ts_irq_enable @ 0xc043c808(x)
        [r4 + 0xa0] = (byte) r5
        r0 = 0
        pop (r4, r5, r6, pc)
    }
    loc_0xc043c800:
        r0 = [r0 + 0x64] // arg1
        sym.disable_irq_nosync ()
        goto 0xc043c7ec
        
        goto loc_0xc043c7e4;
        return r0;
    loc_0xc043c7e4:
        r0 = [r0 + 0x64] // arg1
        sym.enable_irq () // sym.enable_irq(-1)
        break;
}

// ----- END sitronix_ts_irq_enable -----

// ----- BEGIN sitronix_fb_notifier_callback (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_fb_notifier_callback (int32_t arg1, int32_t arg2, int32_t arg3) {
        // ICOD XREF from sym.sitronix_ts_probe @ 0xc043cc48(x)
        push (r4, r5, r6, lr)
        r6 = r2 - 0   // arg3
        je 0xc043c960 // likely
        goto loc_0xc043c81c;
    loc_0xc043c960:
        r0 = 0
        pop (r4, r5, r6, pc)
        goto loc_0xc043c844;
        return r0;
    loc_0xc043c844:
        r3 = [r3]
        (a, b) = compare (r3, 0)
        bne 0xc043c860 // likely
        goto loc_0xc043c850;
    loc_0xc043c860:
        r3 = [r6 + 4]
        (a, b) = compare (r3, 0)
        moveq r4, 0
        andne r4, r4, 1
        (a, b) = compare (r4, 0)
        je 0xc043c960 // likely
        goto loc_0xc043c878;
    loc_0xc043c878:
        r3 = [r3]
        (a, b) = compare (r3, 4)
        bne 0xc043c960 // likely
        goto loc_0xc043c884;
    loc_0xc043c884:
        r4 = [0xc043c88c] // [0xc043c980:4]=0xc0a5d4c8
        r0 = r5 - 0x20
        sym.cancel_work_sync ()
        r3 = 0
        r0 = [r4 + 8]
        r0 += 0x70
        [r0 + 0x19] = (byte) r3
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r3 = [r4 + 8]
        r2 = (byte) [r3 + 0x190]
        (a, b) = compare (r2, 0)
        je 0xc043c8c0 // unlikely
        goto loc_0xc043c8b4;
    loc_0xc043c8c0:
        sym.sitronix_mt_suspend ()
        
    loc_0xc043c8c4:
        r0 = [r4 + 8]
        r3 = (byte) [r0 + 0x190]
        (a, b) = compare (r3, 0)
        bne 0xc043c8e0 // likely
        goto loc_0xc043c8d4;
        goto loc_0xc043c8c0;
        return r0;
    loc_0xc043c8e0: // orphan
         r1 = 1
         sym.sitronix_ts_set_smart_wake_up () // sym.sitronix_ts_set_smart_wake_up(0x0, 0x1)
         r3 = [r4 + 8]
         r1 = 1
         r0 = [r3 + 0x64]
         sym.irq_set_irq_wake ()  // sym.irq_set_irq_wake(-1, 0x1)
         r3 = [r4 + 8]
         r2 = 1
         [r3 + 0x191] = (byte) r2

         goto loc_0xc043c94c;
    loc_0xc043c94c: // orphan
         r0 = [r4 + 8]
         r3 = 1
         r0 += 0x70
         [r0 - 4] = (byte) r3
         sym.mutex_unlock ()      // sym.mutex_unlock(0x6f)

         goto loc_0xc043c938;
    loc_0xc043c938: // orphan
         r3 = (byte) [r3 + 0x191]
         (a, b) = compare (r3, 0)
         je 0xc043c94c            // unlikely

         goto loc_0xc043c944;
    loc_0xc043c944: // orphan
         sym.sitronix_mode_restore ()
         sym.sitronix_swk_config_restore ()

         goto loc_0xc043c8d4;
    loc_0xc043c8d4: // orphan
         r5 = (byte) [r0 + 0x8b]
         (a, b) = compare (r5, 0)
         je 0xc043c968            // unlikely

    loc_0xc043c968: // orphan
         r1 = r5
         sym.sitronix_ts_set_smart_wake_up () // sym.sitronix_ts_set_smart_wake_up(0x0, 0x0)
         r1 = r5
         r0 = [r4 + 8]
         sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(-1, 0x0)
         
    loc_0xc043c904: // orphan
         // CODE XREF from sym.sitronix_fb_notifier_callback @ 0xc043c97c(x)
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)
         r1 = 1
         r0 = [r4 + 8]
         sym.sitronix_ts_powerdown () // sym.sitronix_ts_powerdown(-1, 0x1)
         r0 = 0xa
         sym.msleep ()            // sym.msleep(0xa, 0x1)
         r0 = [r4 + 8]
         sym.sitronix_ts_pen_allup () // sym.sitronix_ts_pen_allup(-1)
         r3 = [r4 + 8]
         r2 = (byte) [r3 + 0x190]
         (a, b) = compare (r2, 0)
         je 0xc043c94c            // unlikely

         goto loc_0xc043c8b4;
    loc_0xc043c8b4: // orphan
         r3 = (byte) [r3 + 0x8b]
         (a, b) = compare (r3, 0)
         je 0xc043c8c4            // unlikely

    loc_0xc043c850: // orphan
         r2 = r0 - 0x20           // arg1
         r1 = [r0 - 0x28]         // arg1
         r0 = 2
         sym.queue_work_on ()     // sym.queue_work_on(0x2, -1, 0xffffffe0)

}

// ----- END sitronix_fb_notifier_callback -----

// ----- BEGIN sitronix_ts_reset_device (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reset_device (int32_t arg1) {
        // XREFS: CALL 0xc043ca94  CALL 0xc043cac0  CALL 0xc043cdc4
        // XREFS: CALL 0xc043d114  CALL 0xc0440644  CALL 0xc0444780
        // XREFS: CALL 0xc04458b4  CALL 0xc0445c6c  CALL 0xc0446158
        // XREFS: CALL 0xc0447d30  CALL 0xc04482e4  CALL 0xc044841c
        // XREFS: CALL 0xc0448538  CALL 0xc04485a4  CALL 0xc0448610
        // XREFS: CALL 0xc0448694
        push (r4, lr)
        r4 = r0       // arg1
        r3 = [r0 + 0x10] // arg1
        r0 = [r3 + 0xc]
        sym.gpio_to_desc () // sym.gpio_to_desc(-1)
        r1 = 0
        sym.gpiod_direction_output_raw () // sym.gpiod_direction_output_raw(-1, 0x0)
        r0 = 1
        sym.msleep () // sym.msleep(0x1, 0x0)
        r3 = [r4 + 0x10]
        r0 = [r3 + 0xc]
        sym.gpio_to_desc () // sym.gpio_to_desc(-1)
        r1 = 1
        sym.gpiod_direction_output_raw () // sym.gpiod_direction_output_raw(-1, 0x1)
        r0 = 0x64     // 'd'
        sym.msleep () // sym.msleep(0x64, 0x1)
        r0 = 0
        pop (r4, pc)  // r13
}

// ----- END sitronix_ts_reset_device -----

// ----- BEGIN sitronix_ts_probe (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_probe (int32_t arg1, int32_t arg_0h, int32_t arg_4h, int32_t arg_0h_2, int32_t arg_4h_2) {
        push (r0, r1, r2, r4, r5, r6, r7, r8, sb, sl, fp, lr)
        r6 = 0
        r8 = [r0 + 0x70] // arg1
        r5 = [0xc043c9e0] // [0xc043cd5c:4]=0xc0a5d4c8
        (a, b) = compare (r8, r6)
        [r5 + 4] = r6
        [r5] = r6
        mvneq r6, 0x15
        je 0xc043cca8 // unlikely
        goto loc_0xc043c9f0;
    loc_0xc043cca8:
        // CODE XREF from sym.sitronix_ts_probe @ 0xc043cbb8(x)
        r0 = r6
        sp += 0xc
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        goto loc_0xc043ca10;
        return r0;
    loc_0xc043ca10:
        sl = r4 + 0x70
        r2 = r5 + 0xc
        r1 = [0xc043ca20] // [0xc043cd64:4]=0xc0802765 "&ts_data->mutex" // "&ts_data->mutex"
        fp = r4 + 0x58
        r0 = sl
        sym.__mutex_init () // sym.__mutex_init(0x70)
        r3 = 1
        [r4 + 0x89] = (byte) r3
        r1 = 0xdc0
        r3 = [r7]
        [r7 + 0x74] = r4
        [r4 + 0x10] = r8
        stm r4, (r3, r7)
        r3 = 2
        [r4 + 0x6c] = (byte) r6
        [r4 + 0x1c3] = (byte) r3
        [r4 + 0x2df] = (byte) r6
        [r4 + 0x2e0] = (byte) r6
        [r4 + 0x30] = r6
        [r4 + 0x2c] = r6
        r0 = [sb + 0x34]
        [r5 + 8] = r4
        sym.kmem_cache_alloc () // sym.kmem_cache_alloc(-1, 0xdc0)
        (a, b) = compare (r0, r6)
        [r5 + 4] = r0
        je 0xc043cd54 // unlikely
        goto loc_0xc043ca78;
    loc_0xc043cd54:
        r6 = ~0xb
        goto 0xc043cae8
        
    loc_0xc043cae8:
        // CODE XREF from sym.sitronix_ts_probe @ 0xc043cd58(x)
        r0 = r4
        sym.sitronix_remove_st_dev ()
        sym.sitronix_remove_proc ()
        r0 = r4
        sym.sitronix_remove_sysfs () // sym.sitronix_remove_sysfs(0x0)
        r0 = [r4 + 0x30]
        (a, b) = compare (r0, 0)
        je 0xc043cb0c // unlikely
        goto loc_0xc043cb08;
        goto loc_0xc043ca90;
        return r0;
    loc_0xc043ca90:
        r0 = r4
        sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(0x0)
        sym.sitronix_get_chip_id ()
        r3 = [r5 + 8]
        [r3 + 0x14] = (byte) r0
        sym.sitronix_get_ic_sfrver ()
        r3 = [r5 + 8]
        [r3 + 0x29] = (byte) r0
        sym.sitronix_set_default_test_criteria ()
        r0 = r6
        sym.sitronix_replace_dump_buf ()
        r0 = r4
        sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(0x0)
        r0 = r4
        sym.sitronix_ts_get_device_status () // sym.sitronix_ts_get_device_status(0x0)
        r0 = r4
        sym.sitronix_ts_get_device_info () // sym.sitronix_ts_get_device_info(0x0)
        r0 = r4
        sym.sitronix_ts_input_dev_init () // sym.sitronix_ts_input_dev_init(0x0, 0x0, 0x0, -1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
        r6 = r0 - 0
        je 0xc043cbbc // likely
        goto loc_0xc043cae4;
    loc_0xc043cbbc:
        r3 = (byte) [r4 + 0x8a]
        (a, b) = compare (r3, 0)
        bne 0xc043ccb4 // likely
        goto loc_0xc043cbc8;
    while (/* 0xc043ccb4 */) {
        while (/* 0xc043cbc8 */) {
            r0 = fp       // r13
            sym.fb_unregister_client () // sym.fb_unregister_client(0x178000)
            sym.sitronix_mt_stop ()
            r0 = [r4 + 0x64]
            (a, b) = compare (r0, 0)
            ble 0xc043cb2c // likely
            r0 = [r4 + 0xc]
            (a, b) = compare (r0, 0)
            je 0xc043cb4c // unlikely
            r0 = [r4 + 8]
            (a, b) = compare (r0, 0)
            je 0xc043cb6c // unlikely
            r0 = [r5]
            (a, b) = compare (r0, 0)
            je 0xc043cb84 // unlikely
            r0 = [r5 + 4]
            (a, b) = compare (r0, 0)
            je 0xc043cb9c // unlikely
            r0 = sl
            r8 = 0
            sym.mutex_destroy () // sym.mutex_destroy(0x0)
            [r7 + 0x74] = r8
            r0 = r4
            sym.kfree ()  // sym.kfree(0x0)
            [r5 + 8] = r8
            goto 0xc043cca8
            sym.kfree ()  // sym.kfree(0x0)
            r3 = 0
            [r5 + 4] = r3
            sym.kfree ()  // sym.kfree(0x0)
            r3 = 0
            [r5] = r3
            sym.input_unregister_device () // sym.input_unregister_device(0x0)
            r0 = [r4 + 8]
            sym.input_free_device () // sym.input_free_device(-1)
            r3 = 0
            [r4 + 8] = r3
            sym.input_unregister_device () // sym.input_unregister_device(0x0)
            r0 = [r4 + 0xc]
            sym.input_free_device () // sym.input_free_device(-1)
            r3 = 0
            [r4 + 0xc] = r3
            r1 = r4
            sym.free_irq () // sym.free_irq(0x0, 0x0)
            sym.destroy_workqueue () // sym.destroy_workqueue(0x0)
            // CODE XREF from sym.sitronix_ts_probe @ 0xc043cd50(x)
            r6 = ~0x15
        }
        while (/* 0xc043cbe0 */) {
        }
        while (/* 0xc043cc28 */) {
            r3 = [0xc043cc10] // [0xc043cd6c:4]=0xc080278e "sitronix_ts_workqueue" // "sitronix_ts_workqueue"
            r2 = 1
            r1 = [0xc043cc18] // [0xc043cd70:4]=0xe000a
            r0 = [0xc043cc1c] // [0xc043cd74:4]=0xc07f0212 "%s" // "%s"
            sym.alloc_workqueue () // sym.alloc_workqueue(0xc07f0212, 0xe000a, 0x1)
            (a, b) = compare (r0, 0)
            [r4 + 0x30] = r0
            je 0xc043cd54 // unlikely
        }
        while (/* 0xc043cc5c */) {
        }
        while (/* 0xc043cc6c */) {
        }
        while (/* 0xc043cc78 */) {
        }
        sym.sitronix_mode_backup () // sym.sitronix_mode_backup(0x0)
        sym.sitronix_swk_config_backup ()
        r3 = 1
        [r4 + 0xfe] = (byte) r3
        r0 = 0x2710   // '\x10\''
        r3 = sym.sitronix_ts_monitor_thread_v3 // [0xc043cd80:4]=0xc04406b8 sym.sitronix_ts_monitor_thread_v3
        [r4 + 0x108] = r3
        sym.sitronix_mt_start () // sym.sitronix_mt_start(0x2710)
    }
    while (/* 0xc043ccc4 */) {
    }
    loc_0xc043cd50:
        goto 0xc043cae4
            goto loc_0xc043cbc8;
        goto loc_0xc043cbe0;
        return r0;
    loc_0xc043ca78: // orphan
         r1 = 0xdc0
         r0 = [sb + 0x34]
         sym.kmem_cache_alloc ()  // sym.kmem_cache_alloc(-1, 0xdc0)
         (a, b) = compare (r0, r6)
         [r5] = r0
         je 0xc043cd54            // unlikely

}

// ----- END sitronix_ts_probe -----

// ----- BEGIN sitronix_ts_resume_work (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_resume_work (int32_t arg1) {
        // ICOD XREF from sym.sitronix_ts_probe @ 0xc043cc40(x)
        push (r4, r5, r6, lr)
        r4 = [0xc043cd94] // [0xc043ce44:4]=0xc0a5d4c8
        r3 = [r4 + 8]
        r5 = (byte) [r3 + 0x89]
        (a, b) = compare (r5, 0)
        je 0xc043cdac // unlikely
        return r0;
    loc_0xc043cdac:
        r0 = 0xc8
        sym.msleep () // sym.msleep(0xc8, 0x0)
        r0 = [r4 + 8]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r0 = [r4 + 8]
        sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(-1)
        r1 = r5
        r0 = [r4 + 8]
        sym.sitronix_ts_powerdown () // sym.sitronix_ts_powerdown(-1, 0x0)
        r0 = [r4 + 8]
        r3 = (byte) [r0 + 0x190]
        (a, b) = compare (r3, 0)
        je 0xc043ce38 // unlikely
        goto loc_0xc043cde4;
    loc_0xc043ce38:
        r1 = 1
        sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(0x0, 0x1)
        goto 0xc043cdf0
        
    loc_0xc043cdf0:
        // CODE XREF from sym.sitronix_ts_resume_work @ 0xc043ce40(x)
        r3 = [r4 + 8]
        r2 = 0
        [r3 + 0x191] = (byte) r2
        [r3 + 0x6c] = (byte) r2
        sym.sitronix_mode_restore ()
        sym.sitronix_swk_config_restore ()
        r0 = [r4 + 8]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        r3 = [r4 + 8]
        r2 = (byte) [r3 + 0x190]
        (a, b) = compare (r2, 0)
        je 0xc043ce30 // unlikely
        goto loc_0xc043ce24;
    loc_0xc043ce24: // orphan
         r3 = (byte) [r3 + 0x8b]
         (a, b) = compare (r3, 0)
         popeq (r4, r5, r6, pc)

    loc_0xc043cde4: // orphan
         r1 = r5
         r0 = [r0 + 0x64]
         sym.irq_set_irq_wake ()  // sym.irq_set_irq_wake(-1, 0x0)

         return r0;
    loc_0xc043cda0: // orphan
         r2 = 0
         [r3 + 0x89] = (byte) r2
         pop (r4, r5, r6, pc)

}

// ----- END sitronix_ts_resume_work -----

// ----- BEGIN sitronix_ts_report_swu (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_report_swu (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d090(x)
        // CALL XREF from sym.sitronix_stswu_show @ 0xc0440dbc(x)
        // CALL XREF from sym.st_proc_stswu_show @ 0xc0441280(x)
        push (r4, r5, r6, lr)
        r4 = r0       // arg1
        r0 = r1       // arg2
        sym.sitronix_ts_get_swu_keycode () // sym.sitronix_ts_get_swu_keycode(0x0)
        r5 = r0 - 0
        popeq (r4, r5, r6, pc) // r13
        goto loc_0xc043ce60;
        break;
}

// ----- END sitronix_ts_report_swu -----

// ----- BEGIN sitronix_ts_report_palm (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_report_palm (int32_t arg1) {
        r3 = 1
        r2 = 0x74     // 't'
        push (r4, lr)
        r1 = r3
        r4 = r0       // arg1
        sym.input_event () // sym.input_event(0x0, 0x1, 0x74, 0x1)
        r0 = r4
        sym.input_sync ()
        r0 = r4
        r3 = 0
        r2 = 0x74     // 't'
        r1 = 1
        sym.input_event () // sym.input_event(0x0, 0x1, 0x74, 0x0)
        r0 = r4
        pop (r4, lr)  // r13
        goto sym.input_sync
}

// ----- END sitronix_ts_report_palm -----

// ----- BEGIN sitronix_ts_report_proximity_demo (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_report_proximity_demo (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d320(x)
        (a, b) = compare (r1, 3) // arg2
        push (r4, lr)
        bne 0xc043cf38 // likely
        goto loc_0xc043cee8;
    loc_0xc043cf38:
        (a, b) = compare (r1, 5) // arg2
        popne (r4, pc)
        return r0;
            goto loc_0xc043cee8;
    loc_0xc043cee8:
        r4 = [0xc043cef0] // [0xc043cf78:4]=0xc0a5d4c8
        r2 = 0
        r0 = 0x28     // '('
        r1 = [r4 + 4]
        sym.sitronix_write_driver_cmd () // sym.sitronix_write_driver_cmd(0x28, 0x0, 0x0)
        r2 = 0
        r1 = [r4 + 4]
        r0 = 0x10
        sym.sitronix_write_driver_cmd () // sym.sitronix_write_driver_cmd(0x10, 0x0, 0x0)
        r0 = 0x14
        sym.msleep () // sym.msleep(0x14, 0x0)
        r1 = 1
        r0 = [r4 + 8]
        sym.sitronix_ts_powerdown () // sym.sitronix_ts_powerdown(0x0, 0x1)
        r0 = 0x14
        sym.msleep () // sym.msleep(0x14, 0x1)
        r0 = [r4 + 8]
        r1 = 1
        pop (r4, lr)
        goto sym.sitronix_ts_proximity_control_sensing // sym.sitronix_ts_proximity_control_sensing(0x0, 0x1)
}

// ----- END sitronix_ts_report_proximity_demo -----

// ----- BEGIN sitronix_ts_report_proximity (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_report_proximity (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d32c(x)
        (a, b) = compare (r1, 3) // arg2
        r2 = r1       // arg2
        push (r4, lr)
        r4 = r0       // arg1
        bne 0xc043cfa4 // likely
        goto loc_0xc043cf90;
    loc_0xc043cfa4:
        (a, b) = compare (r1, 4) // arg2
        bne 0xc043cfc0 // likely
        goto loc_0xc043cfac;
    loc_0xc043cfc0:
        (a, b) = compare (r1, 5) // arg2
        popne (r4, pc)
        goto loc_0xc043cfc8;
            goto loc_0xc043cfac;
    loc_0xc043cfac:
        // CODE XREF from sym.sitronix_ts_report_proximity @ 0xc043cfa0(x)
        r1 = 0x19
        sym.input_report_abs () // sym.input_report_abs(0x0, 0x19)
        r0 = r4
        pop (r4, lr)
        goto sym.input_sync
        return r0;
    loc_0xc043cf9c: // orphan
         // CODE XREF from sym.sitronix_ts_report_proximity @ 0xc043cfd4(x)
         [r3 + 0x8e] = (byte) r1
         
    loc_0xc043cf90: // orphan
         r3 = [0xc043cf98]        // [0xc043cfd8:4]=0xc0a5d4c8
         r1 = 1
         r3 = [r3 + 8]

}

// ----- END sitronix_ts_report_proximity -----

// ----- BEGIN sitronix_ts_irq_handler (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_irq_handler (int32_t arg1, int32_t arg2, int32_t arg_ch) {
        // ICOD XREF from sym.sitronix_ts_probe @ 0xc043cbf8(x)
        r3 = [0xc043cfe4] // [0xc043d418:4]=0xc0a04e08
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x14
        r2 = [r3]
        r4 = r1       // arg2
        r5 = (byte) [r1 + 0x1e] // arg2
        [var_4h] = r3
        [var_ch] = r2
        r2 = 0x5a     // 'Z'
        [var_ah] = (half) r2
        r2 = (byte) [r1 + 0x298] // arg2
        (a, b) = compare (r2, 0x14)
        bne 0xc043d044 // likely
        goto loc_0xc043d010;
    loc_0xc043d044:
        sb = r4 + 0x70
        r6 = (byte) [r1 + 0x25] // arg2
        sym.sitronix_mt_pause_one () // sym.sitronix_mt_pause_one(0x0)
        r0 = sb
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r3 = (byte) [r4 + 0x191]
        (a, b) = compare (r3, 0)
        je 0xc043d0c4 // unlikely
        goto loc_0xc043d064;
    while (/* 0xc043d0c4 */) {
        // CODE XREFS from sym.sitronix_ts_irq_handler @ 0xc043d294(x), 0xc043d2dc(x)
        r3 = (byte) [r4 + 0x298]
        (a, b) = compare (r3, 0x15)
        bne 0xc043d0b8 // likely
        r0 = sb
        sym.mutex_unlock () // sym.mutex_unlock(0x0)
        goto 0xc043d028
        r2 = 1
        r3 = 0
        [r4 + 0x2a8] = (byte) r2
        r1 = r2
        r0 = r4 + 0x29c
        sym.__wake_up () // sym.__wake_up(0x29c, 0x1, 0x1, 0x0)
    }
    loc_0xc043d0fc:
        r3 = (byte) [r4 + r8]
        (a, b) = compare (r3, 0)
        (>=) goto 0xc043d118 // likely
        goto loc_0xc043d108;
    loc_0xc043d118:
        r3 = (byte) [r4 + 0x2e0]
        (a, b) = compare (r3, 0)
        je 0xc043d130 // unlikely
        goto loc_0xc043d124;
    loc_0xc043d130:
        r3 = (byte) [r4 + 0x8a]
        (a, b) = compare (r3, 0)
        bne 0xc043d298 // likely
        goto loc_0xc043d13c;
    while (/* 0xc043d298 */) {
        r3 = (byte) [r4 + 0x8f]
        (a, b) = compare (r3, 0)
        je 0xc043d1f4 // unlikely
        r3 = (byte) [r4 + 0x8a]
        (a, b) = compare (r3, 0)
        bne 0xc043d2e0 // likely
        // CODE XREF from sym.sitronix_ts_irq_handler @ 0xc043d330(x)
        r5 = (byte) [r4 + 0x6c]
        (a, b) = compare (r5, 0)
        addeq r6, r4, 0x1d0
        addeq r6, r6, 1
        moveq r8, r5
        bne 0xc043d094 // likely
        // CODE XREF from sym.sitronix_ts_irq_handler @ 0xc043d3dc(x)
        r3 = (byte) [r4 + 0x1e]
        (a, b) = compare (r8, r3)
        blt 0xc043d334 // likely
        r3 = r5 + 0
        r2 = 0x14a
        r1 = 1
        r0 = [r4 + 8]
        movne r3, 1
        r8 = [0xc043d240] // [0xc043d41c:4]=0xc0a5d4c8
        sym.input_event () // sym.input_event(-1, 0x1, 0x14a, 0x0)
        r0 = [r4 + 8]
        sym.input_sync ()
        sl = [0xc043d250] // [0xc043d420:4]=0xc0a2d240
        r6 = [r4 + 8]
        r5 = 0
        r7 = (byte) [r4 + 0x1c9]
        fp = r8
        while (/* 0xc043d284 */) {
            r1 = 1
            r2 = (byte) [r8 + 0xc]
            r3 = r1 << r5
            r3 = r3
            (a, b) = compare (r3, r2)
            r3 &= r7
            bne 0xc043d3f0 // likely
            (a, b) = compare (r3, 0)
            movne r3, r1
            bne 0xc043d3f8 // unlikely
        }
        [arg_ch] = (byte) r7
        goto 0xc043d094
        r2 = 4
        r1 = r7
        r0 = var_ah_2
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x17800a, 0x0, 0x4)
        r3 = (byte) [r4 + 0x1c6]
        (a, b) = compare (r3, 8)
        je 0xc043d17c // unlikely
        r3 = (byte) [r4 + 0x8a]
        r5 = r4 + r5
        (a, b) = compare (r3, 0)
        r2 = (byte) [r5 + 0x1c5]
        je 0xc043d1e4 // unlikely
        r3 = (byte) [var_ah_2]
        (a, b) = compare (r2, r3)
        [var_ah_2] = (half) r3
        bne 0xc043d094 // unlikely
        r3 = (byte) [r4 + 0x8b]
        (a, b) = compare (r3, 0)
        je 0xc043d1e4 // unlikely
        r3 = (byte) [r4 + 0x1c6]
        (a, b) = compare (r3, 4)
        je 0xc043d1e4 // unlikely
        r3 = (byte) [r4 + 0x216]
        r1 = r4 + 0x214
        r2 = (byte) [r4 + 0x25]
        r1 += 2
        (a, b) = compare (r3, 1)
        r0 = var_ah_2
        ldrbne r3, [r4, 0x24]
        addne r2, r2, r3
        r5 = r2 << 1
        r5 += 1
        uxth r5, r5
        r2 = r5
        r5 = r4 + r5
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x17800a, 0x216, 0x3fd)
        r2 = (byte) [r5 + 0x216]
        r2 = (byte) [r4 + 0x1e]
        r1 = r4 + 0x1c8
        r1 += 2
        r0 = var_ah_2
        rsb r2, r2, r2, lsl 3
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x17800a, 0x1ca, 0x6f9)
    }
    while (/* 0xc043d2a4 */) {
    }
    while (/* 0xc043d2b0 */) {
    }
    loc_0xc043d2dc:
        goto 0xc043d094
        
        goto loc_0xc043d0a0;
        goto loc_0xc043d148;
        goto loc_0xc043d070;
        return r0;
    loc_0xc043d410: // orphan
         sp += 0x14
         pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)

    loc_0xc043d040: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc043d2e0: // orphan
         r3 = (byte) [r4 + 0x8b]
         (a, b) = compare (r3, 0)
         je 0xc043d200            // unlikely

    loc_0xc043d334: // orphan
         fp = (byte) [r6 - 7]
         (a, b) = compare (fp, 0x80)
         je 0xc043d3e0            // unlikely

    loc_0xc043d3e0: // orphan
         r1 = r8
         r0 = [r4 + 8]
         sym.sitronix_ts_pen_up () // sym.sitronix_ts_pen_up(-1, 0x0)
         
    loc_0xc043d3d4: // orphan
         // CODE XREF from sym.sitronix_ts_irq_handler @ 0xc043d3ec(x)
         r8 += 1
         r6 += 7
         
         goto loc_0xc043d340;
    loc_0xc043d340: // orphan
         sl = (byte) [r6 - 5]
         fp = fp << 8
         r3 = (byte) [r6 - 6]
         fp &= 0x3f00
         r7 = [r4 + 8]
         r2 = 0x2f                // '/'
         sl = sl << 8
         fp = r3 | fp
         r3 = sl & 0x3f00
         sl = (byte) [r6 - 4]
         r1 = 3
         r0 = r7
         sl |= r3
         r3 = r8
         sym.input_event ()       // sym.input_event(-1, 0x3, 0x2f, 0x0)
         r2 = 1
         r1 = 0
         r0 = r7
         sym.input_mt_report_slot_state () // sym.input_mt_report_slot_state(-1, 0x0, 0x1)
         r2 = fp
         r1 = 0x35                // '5'
         r0 = r7
         sym.input_report_abs ()  // sym.input_report_abs(-1, 0x35)
         r2 = sl
         r1 = 0x36                // '6'
         r0 = r7
         sym.input_report_abs ()  // sym.input_report_abs(-1, 0x36)
         r5 += 1
         r2 = 1
         r1 = 0x30                // '0'
         r0 = r7
         r5 = r5
         sym.input_report_abs ()  // sym.input_report_abs(-1, 0x30)
         r2 = 0xff
         r1 = 0x3a                // ':'
         r0 = r7
         sym.input_report_abs ()  // sym.input_report_abs(-1, 0x3a)

         goto loc_0xc043d224;
    loc_0xc043d3f0: // orphan
         r3 &= r3
         bne 0xc043d284           // unlikely

    loc_0xc043d3f8: // orphan
         r0 = r6
         ldr r2, [sl, r5, lsl 2]
         sym.input_event ()       // sym.input_event(0x0, 0x0, -1, 0x0)
         r0 = r6
         sym.input_sync ()
         
         goto loc_0xc043d278;
    loc_0xc043d2ec: // orphan
         r5 = (byte) [r4 + 0x1c6]
         ubfx r5, r5, 4, 3
         (a, b) = compare (r5, 0)
         je 0xc043d200            // unlikely

         goto loc_0xc043d2fc;
    loc_0xc043d2fc: // orphan
         r3 = (byte) [r4 + 0x8c]
         (a, b) = compare (r3, r5)
         je 0xc043d200            // unlikely

         goto loc_0xc043d308;
    loc_0xc043d308: // orphan
         r3 = (byte) [r4 + 0x8d]
         [r4 + 0x8c] = (byte) r5
         (a, b) = compare (r3, 0)
         je 0xc043d324            // unlikely

    loc_0xc043d324: // orphan
         r1 = r5
         r0 = [r4 + 0xc]
         sym.sitronix_ts_report_proximity () // sym.sitronix_ts_report_proximity(-1, 0x0)
         
         goto loc_0xc043d318;
    loc_0xc043d318: // orphan
         r1 = r5
         r0 = [r4 + 8]
         sym.sitronix_ts_report_proximity_demo () // sym.sitronix_ts_report_proximity_demo(-1)

         goto loc_0xc043d148;
    loc_0xc043d124: // orphan
         r1 = r4 + 0x2e8
         r0 = r4
         sym.sitronix_ts_get_exdiff () // sym.sitronix_ts_get_exdiff(0x0, 0x2e8)

         goto loc_0xc043d108;
    loc_0xc043d108: // orphan
         r0 = r4
         sym.sitronix_ts_pen_allup () // sym.sitronix_ts_pen_allup(0x0)
         r0 = r4
         sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(0x0)

         goto loc_0xc043d064;
    loc_0xc043d064: // orphan
         r3 = (byte) [r4 + 0x8b]
         (a, b) = compare (r3, 0)
         bne 0xc043d0c4           // likely

         goto loc_0xc043d070;
    loc_0xc043d070: // orphan
         r0 = r4
         sym.sitronix_ts_get_swu_gesture () // sym.sitronix_ts_get_swu_gesture(0x0)
         (a, b) = compare (r0, 0)
         blt 0xc043d094           // unlikely

         goto loc_0xc043d080;
    loc_0xc043d080: // orphan
         r1 = (byte) [r4 + 0x88]
         (a, b) = compare (r1, 0)
         je 0xc043d094            // unlikely

         goto loc_0xc043d08c;
    loc_0xc043d08c: // orphan
         r0 = [r4 + 8]
         sym.sitronix_ts_report_swu () // sym.sitronix_ts_report_swu(-1, 0x0)

         goto loc_0xc043d010;
    loc_0xc043d010: // orphan
         r2 = 1
         r3 = 0
         [r1 + 0x2a8] = (byte) r2 // arg2
         r0 = r4 + 0x29c
         r1 = r2
         sym.__wake_up ()         // sym.__wake_up(0x29c, 0x1, 0x1, 0x0)

}

// ----- END sitronix_ts_irq_handler -----

// ----- BEGIN sitronix_ts_reset_input_dev (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reset_input_dev (void) {
        // CALL XREF from sym.st_dev_function @ 0xc0444874(x)
        push (r4, lr)
        r4 = [0xc043d430] // [0xc043d464:4]=0xc0a5d4c8
        r0 = [r4 + 8]
        r3 = [r0 + 8]
        (a, b) = compare (r3, 0)
        popeq (r4, pc)
        goto loc_0xc043d43c;
        break;
}

// ----- END sitronix_ts_reset_input_dev -----

// ----- BEGIN sitronix_ts_i2c_dev_release (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_dev_release (void) {
        bx lr
}

// ----- END sitronix_ts_i2c_dev_release -----

// ----- BEGIN sitronix_ts_i2c_init (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_init (void) {
        // CALL XREF from sym.sitronix_ts_init @ 0xc091a3ac(x)
        r1 = [0xc043d474] // [0xc043d478:4]=0xc0a2d2e8
        r0 = 0
        goto sym.i2c_register_driver // sym.i2c_register_driver(0x0, 0xc0a2d2e8)
}

// ----- END sitronix_ts_i2c_init -----

// ----- BEGIN sitronix_ts_i2c_remove (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_remove (void) {
        r3 = [0xc043d484] // [0xc043d4c0:4]=0xc0a2d2e8
        push (r4, lr)
        r4 = [r3 + 0x118]
        (a, b) = compare (r4, 0)
        je 0xc043d4b8 // likely
        goto loc_0xc043d490;
    loc_0xc043d4b8:
        r0 = 0
        pop (r4, pc)
        goto loc_0xc043d49c;
        return r0;
    loc_0xc043d49c:
        sym.gpio_free () // sym.gpio_free(0x0)
        
    loc_0xc043d4a0:
        r0 = [r4 + 0xc]
        (a, b) = compare (r0, 0x1a0)
        bhs 0xc043d4b0 // likely
        goto loc_0xc043d4ac;
        return r0;
    loc_0xc043d4ac:
        sym.gpio_free () // sym.gpio_free(0x0)
        
    loc_0xc043d4b0:
        r0 = [0xc043d4b8] // [0xc043d4c4:4]=0xc0a2d390 // (pstr 0xc08027a4) "sitronix_ts_i2c"
        sym.platform_device_unregister () // sym.platform_device_unregister(0xc0a2d390)
        return r0;
}

// ----- END sitronix_ts_i2c_remove -----

// ----- BEGIN sitronix_ts_i2c_awrite (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_awrite (int32_t arg1, int32_t arg2, int32_t arg3) {
        push (r4, r5, lr)
        sp -= 0x14
        r5 = [0xc043d4d8] // [0xc043d548:4]=0xc0a04e08
        r4 = r1       // arg2
        ip = [r2]     // arg3
        r2 = r1 + 1   // arg2
        [var_8h] = r0 // arg1
        r1 = sp
        r3 = [r5]
        [var_4h] = (half) r2
        r2 = 1
        [var_ch] = r3
        r3 = 0x28     // '('
        [sp] = (half) r3
        r3 = 0
        [r0] = (byte) r3 // arg1
        r0 = [ip + 0x18]
        [var_0h] = (half) r3
        sym.i2c_transfer () // sym.i2c_transfer(-1, 0x177fe0, 0x1)
        (a, b) = compare (r0, 1)
        moveq r0, r4
        je 0xc043d52c // unlikely
        goto loc_0xc043d520;
    loc_0xc043d52c:
        r2 = [var_ch]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043d540 // unlikely
        goto loc_0xc043d53c;
    loc_0xc043d540:
        sp += 0x14
        pop (r4, r5, pc)
        return r0;
    loc_0xc043d520: // orphan
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)
         r0 = ~4

}

// ----- END sitronix_ts_i2c_awrite -----

// ----- BEGIN sitronix_ts_i2c_aread (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_aread (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg_30h) {
        push (r4, r5, lr)
        sp -= 0x24
        r4 = [0xc043d55c] // [0xc043d5ec:4]=0xc0a04e08
        r5 = 0
        [var_6h] = (half) r5
        r5 = r1 + 1   // arg2
        r1 -= 1       // arg2
        [var_ch] = r0 // arg1
        ip = [r4]
        r1 = ~r1
        r1 &= 0x5f    // arg2
        [var_18h] = r2 // arg3
        r2 = 2
        [var_1ch] = ip
        r1 = ~r1
        ip = [arg_30h]
        [var_6h] = (half) r5
        [var_14h] = (half) r3 // arg4
        lr = [ip]
        ip = 0x28     // '('
        [r0] = (byte) r1
        r1 = var_4h
        [var_4h] = (half) ip
        r0 = [lr + 0x18]
        [var_10h] = (half) ip
        ip = 1
        [var_10h] = (half) ip
        sym.i2c_transfer () // sym.i2c_transfer(-1, 0x177fd4, 0x2)
        (a, b) = compare (r0, 2)
        je 0xc043d5cc // unlikely
        goto loc_0xc043d5c4;
    loc_0xc043d5cc:
        r2 = [var_1ch]
        r0 = 0
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043d5e4 // unlikely
        goto loc_0xc043d5e0;
    loc_0xc043d5e4:
        sp += 0x24
        pop (r4, r5, pc)
        return r0;
    loc_0xc043d5c4: // orphan
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)

}

// ----- END sitronix_ts_i2c_aread -----

// ----- BEGIN sitronix_ts_i2c_dwrite (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_dwrite (int32_t arg1, int32_t arg2, int32_t arg3) {
        push (r4, r5, lr)
        sp -= 0x14    // "(\x01"
        r5 = [0xc043d600] // [0xc043d668:4]=0xc0a04e08
        r4 = r1       // arg2
        r3 = [r5]
        [var_ch] = r3
        r3 = [r2]     // arg3
        r2 = (word) [r3 + 2]
        [var_4h] = (half) r1 // arg2
        r1 = sp       // "(\x01"
        [var_8h] = r0 // arg1
        [sp] = (half) r2
        r2 = 0
        r0 = [r3 + 0x18]
        [var_0h] = (half) r2
        r2 = 1
        sym.i2c_transfer () // sym.i2c_transfer(-1, 0x177fe0, 0x1)
        (a, b) = compare (r0, 1)
        moveq r0, r4
        je 0xc043d64c // unlikely
        goto loc_0xc043d640;
    loc_0xc043d64c:
        r2 = [var_ch]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043d660 // unlikely
        goto loc_0xc043d65c;
    loc_0xc043d660:
        sp += 0x14
        pop (r4, r5, pc)
        return r0;
    loc_0xc043d640: // orphan
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)
         r0 = ~4

}

// ----- END sitronix_ts_i2c_dwrite -----

// ----- BEGIN sitronix_ts_i2c_dread (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_dread (int32_t arg1, int32_t arg2, int32_t arg3) {
        push (r4, r5, lr)
        sp -= 0x14
        r5 = [0xc043d67c] // [0xc043d6e0:4]=0xc0a04e08
        r4 = r1       // arg2
        r3 = [r5]
        [var_ch] = r3
        r3 = [r2]     // arg3
        r2 = (word) [r3 + 2]
        [var_4h] = (half) r1 // arg2
        r1 = sp
        [var_8h] = r0 // arg1
        [sp] = (half) r2
        r2 = 1
        r0 = [r3 + 0x18]
        [var_0h] = (half) r2
        sym.i2c_transfer () // sym.i2c_transfer(-1, 0x177fe0, 0x1)
        (a, b) = compare (r0, 1)
        moveq r0, r4
        je 0xc043d6c4 // unlikely
        goto loc_0xc043d6b8;
    loc_0xc043d6c4:
        r2 = [var_ch]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043d6d8 // unlikely
        goto loc_0xc043d6d4;
    loc_0xc043d6d8:
        sp += 0x14
        pop (r4, r5, pc)
        return r0;
    loc_0xc043d6b8: // orphan
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)
         r0 = ~4

}

// ----- END sitronix_ts_i2c_dread -----

// ----- BEGIN sitronix_ts_i2c_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_read (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        push (r4, r5, lr)
        r4 = r2       // arg3
        r5 = [0xc043d6f4] // [0xc043d784:4]=0xc0a04e08
        sp -= 0x24
        r3 = [r3]     // arg4
        ip = var_1ah
        r2 = [r5]
        [var_1ch] = r2
        r2 = (word) [r3 + 2] // arg4
        [var_8h] = ip
        [sp] = (half) r2
        r2 = 0
        [var_0h] = (half) r2
        r2 = 2
        [var_4h] = (half) r2
        ip = (word) [r3 + 2] // arg4
        [var_14h] = r1 // arg2
        r1 = r0 >> 8  // arg1
        [var_1ah] = (byte) r0
        [var_1ah] = (byte) r1
        r1 = sp
        r0 = [r3 + 0x18]
        [var_ch] = (half) ip
        ip = 1
        [var_10h] = (half) r4
        [var_ch] = (half) ip
        sym.i2c_transfer () // sym.i2c_transfer(-1, 0x177fd0, 0x2)
        (a, b) = compare (r0, 2)
        moveq r0, r4
        je 0xc043d768 // unlikely
        goto loc_0xc043d75c;
    loc_0xc043d768:
        r2 = [var_1ch]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043d77c // unlikely
        goto loc_0xc043d778;
    loc_0xc043d77c:
        sp += 0x24
        pop (r4, r5, pc)
        return r0;
    loc_0xc043d75c: // orphan
         r0 = 0x14
         sym.msleep ()            // sym.msleep(0x14, 0x0)
         r0 = ~4

}

// ----- END sitronix_ts_i2c_read -----

// ----- BEGIN sitronix_ts_i2c_exit (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_exit (void) {
        r0 = [pc]     // [0xc043d790:4]=0xc0a2d2e8
        goto sym.i2c_del_driver // sym.i2c_del_driver(0xc0a2d2e8)
}

// ----- END sitronix_ts_i2c_exit -----

// ----- BEGIN sitronix_ts_i2c_probe (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_probe (int32_t arg1) {
        push (r4, r5, r6, lr)
        r4 = r0       // arg1
        r0 = [r0 + 0x18] // arg1
        r3 = [r0 + 8] // arg1
        r3 = [r3 + 0x10]
        r3 ()         // 0xffffffff(-1, 0x0, 0x0, -1)
        (a, b) = compare (r0, 1)
        je 0xc043d840 // unlikely
        goto loc_0xc043d7b4;
    loc_0xc043d840:
        r0 = ~4
        pop (r4, r5, r6, pc)
        goto loc_0xc043d7c4;
        return r0;
    loc_0xc043d7c4:
        r3 = r5 + 0x358
        r2 = 0
        r1 = [0xc043d7d4] // [0xc043d84c:4]=0xc08027b4 "irq-gpio" // "irq-gpio"
        r0 = r6
        sym.of_get_named_gpio_flags () // sym.of_get_named_gpio_flags(0x0, 0xc08027b4, 0x0, 0x358)
        (a, b) = compare (r0, 0)
        [r5 + 0x354] = r0
        blt 0xc043d7ec // unlikely
        goto loc_0xc043d7e4;
    loc_0xc043d7ec:
        r3 = [0xc043d7f4] // [0xc043d854:4]=0xc0a2d648
        r2 = 0
        r1 = [0xc043d7fc] // [0xc043d858:4]=0xc08027c9 "rst-gpio" // "rst-gpio"
        r0 = r6
        sym.of_get_named_gpio_flags () // sym.of_get_named_gpio_flags(0x0, 0xc08027c9, 0x0, 0xc0a2d648)
        (a, b) = compare (r0, 0)
        [r5 + 0x35c] = r0
        blt 0xc043d814 // unlikely
        goto loc_0xc043d80c;
    loc_0xc043d814:
        r0 = [0xc043d81c] // [0xc043d860:4]=0xc0a2d638
        r3 = [0xc043d820] // [0xc043d864:4]=0xc0a5d4d8
        [r5 + 0x118] = r0
        r0 -= 0x2a8   // (pstr 0xc08027a4) "sitronix_ts_i2c"
        [r3] = r4
        r4 += 0x20
        [r5 + 0x100] = r4
        sym.platform_device_register () // sym.platform_device_register(0xc0a2d390)
        (a, b) = compare (r0, 0)
        mvnne r0, 0x12
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043d80c: // orphan
         r1 = [0xc043d814]        // [0xc043d85c:4]=0xc08027d2 "st_rst_gpio" // "st_rst_gpio"
         sym.gpio_request ()      // sym.gpio_request(0x0, 0xc08027d2)

         goto loc_0xc043d7e4;
    loc_0xc043d7e4: // orphan
         r1 = [0xc043d7ec]        // [0xc043d850:4]=0xc08027bd "st_irq_gpio" // "st_irq_gpio"
         sym.gpio_request ()      // sym.gpio_request(0x0, 0xc08027bd)

}

// ----- END sitronix_ts_i2c_probe -----

// ----- BEGIN sitronix_ts_i2c_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_i2c_write (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x14
        r6 = [0xc043d878] // [0xc043d92c:4]=0xc0a04e08
        sb = r1       // arg2
        r7 = [r3]     // arg4
        r3 = 0
        [sp] = r3
        r8 = r0       // arg1
        r1 = [r6]
        r0 = r2 + 2   // arg3
        [var_4h] = r3
        r4 = r2
        [var_8h] = r3
        r3 = (word) [r7 + 2]
        [var_ch] = r1
        r1 = 0xdc0
        [var_4h] = (half) r0
        [sp] = (half) r3
        sym.__kmalloc () // sym.__kmalloc(0x2, 0xdc0)
        r5 = r0 - 0
        mvneq r4, 0xb
        je 0xc043d90c // unlikely
        goto loc_0xc043d8c0;
    loc_0xc043d90c:
        r2 = [var_ch_2]
        r0 = r4
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc043d924 // unlikely
        goto loc_0xc043d920;
    loc_0xc043d924:
        sp += 0x14
        pop (r4, r5, r6, r7, r8, sb, pc)
        goto loc_0xc043d8f8;
        return r0;
    loc_0xc043d8f8:
        r0 = 8
        r4 = ~4
        sym.msleep () // sym.msleep(0x8, 0x0)
        
    loc_0xc043d904:
        r0 = r5
        sym.kfree ()  // sym.kfree(0x0)
        return r0;
    loc_0xc043d8c0: // orphan
         r3 = r8 >> 8
         r2 = r4
         [r5] = (byte) r3
         r1 = sb
         [r5 + 1] = (byte) r8
         r0 = r5 + 2
         [var_8h_2] = r5
         sym.memcpy () // void *memcpy(-1, 0, 0)
         r2 = 1
         r0 = [r7 + 0x18]
         r1 = sp
         sym.i2c_transfer ()      // sym.i2c_transfer(-1, 0x178004, 0x1)
         (a, b) = compare (r0, 1)
         je 0xc043d904            // unlikely

}

// ----- END sitronix_ts_i2c_write -----

// ----- BEGIN sitronix_ts_reg_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reg_read (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        // XREFS(25)
        [sp - 4]! = lr
        ip = r1       // arg2
        r1 = r2       // arg3
        r2 = r3       // arg4
        r3 = [r0 + 0x10] // arg1
        r0 = ip
        lr = [r3 + 0x18]
        r3 = [r3 + 0x14]
        ip = lr
        pop (lr)      // r13
        bx ip
}

// ----- END sitronix_ts_reg_read -----

// ----- BEGIN sitronix_ts_reg_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reg_write (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        // XREFS: CALL 0xc043dbfc  CALL 0xc043dc30  CALL 0xc043dd2c
        // XREFS: CALL 0xc043dde4  CALL 0xc043de60  CALL 0xc043dfc8
        // XREFS: CALL 0xc043e264  CALL 0xc043fd6c  CALL 0xc043fe2c
        // XREFS: CALL 0xc04401c0
        [sp - 4]! = lr
        ip = r1       // arg2
        r1 = r2       // arg3
        r2 = r3       // arg4
        r3 = [r0 + 0x10] // arg1
        r0 = ip
        lr = [r3 + 0x1c]
        r3 = [r3 + 0x14]
        ip = lr
        pop (lr)      // r13
        bx ip
}

// ----- END sitronix_ts_reg_write -----

// ----- BEGIN sitronix_ts_addrmode_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_addrmode_write (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS(43)
        [sp - 4]! = lr
        ip = r1       // arg2
        r3 = [r0 + 0x10] // arg1
        r1 = r2       // arg3
        r0 = ip
        lr = [r3 + 0x2c]
        r2 = [r3 + 0x14]
        r3 = lr
        pop (lr)      // r13
        bx r3
}

// ----- END sitronix_ts_addrmode_write -----

// ----- BEGIN sitronix_ts_get_device_status (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_device_status (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cac8(x)
        push (r0, r1, r2, r3, r4, lr)
        r1 = 1
        r4 = [0xc043d9d4] // [0xc043da0c:4]=0xc0a04e08
        r2 = var_4h
        r3 = [r4]
        [var_ch] = r3
        r3 = 8
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x1, 0x177fec, 0x8)
        (a, b) = compare (r0, 0)
        r2 = [var_ch]
        r3 = [r4]
        ldrbge r0, [sp, 4]
        andge r0, r0, 0xf
        (a, b) = compare (r2, r3)
        je 0xc043da04 // likely
        goto loc_0xc043da00;
    loc_0xc043da04:
        sp += 0x10
        pop (r4, pc)
        return r0;
}

// ----- END sitronix_ts_get_device_status -----

// ----- BEGIN sitronix_ts_get_fw_revision (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_fw_revision (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043eab8(x)
        push (r0, r1, r2, r4, r5, lr)
        r1 = 0
        r4 = [0xc043da20] // [0xc043da84:4]=0xc0a04e08
        r2 = sp
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x0, 0x177fe8, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043da68 // unlikely
        goto loc_0xc043da3c;
    loc_0xc043da68:
        r2 = [var_4h]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043da7c // unlikely
        goto loc_0xc043da78;
    loc_0xc043da7c:
        sp += 0xc
        pop (r4, r5, pc)
        return r0;
    loc_0xc043da3c: // orphan
         r3 = (byte) [sp]
         r2 = sp                  // r13
         r1 = 0xc
         r0 = r5
         [r5 + 0x15] = (byte) r3
         r3 = 4
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xc, 0x178000, 0x4)
         (a, b) = compare (r0, 0)
         ldrge r3, [sp]
         movge r0, 0
         strge r3, [r5, 0x16]

}

// ----- END sitronix_ts_get_fw_revision -----

// ----- BEGIN sitronix_ts_get_max_touches (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_max_touches (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043eae8(x)
        push (r0, r1, r2, r4, r5, lr)
        r1 = 9
        r4 = [0xc043da98] // [0xc043dad8:4]=0xc0a04e08
        r2 = var_3h
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x9, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        r2 = [var_4h]
        ldrbge r3, [sp, 3]
        movge r0, 0
        strbge r3, [r5, 0x1e]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043dad0 // likely
        goto loc_0xc043dacc;
    loc_0xc043dad0:
        sp += 0xc
        pop (r4, r5, pc)
        return r0;
}

// ----- END sitronix_ts_get_max_touches -----

// ----- BEGIN sitronix_ts_get_chip_id (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_chip_id (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043eaf8(x)
        push (r0, r1, r2, r4, r5, lr)
        r1 = 0xf4
        r4 = [0xc043daec] // [0xc043db2c:4]=0xc0a04e08
        r2 = var_3h
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf4, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        r2 = [var_4h]
        ldrbge r3, [sp, 3]
        movge r0, 0
        strbge r3, [r5, 0x14]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043db24 // likely
        goto loc_0xc043db20;
    loc_0xc043db24:
        sp += 0xc
        pop (r4, r5, pc)
        return r0;
}

// ----- END sitronix_ts_get_chip_id -----

// ----- BEGIN sitronix_ts_get_resolution (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_resolution (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043ead8(x)
        push (r0, r1, r2, r4, r5, lr)
        r1 = 5
        r5 = [0xc043db40] // [0xc043dbac:4]=0xc0a04e08
        r2 = sp
        r4 = r0       // arg1
        r3 = [r5]
        [var_4h] = r3
        r3 = 4
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x5, 0x177fe8, 0x4)
        (a, b) = compare (r0, 0)
        blt 0xc043db90 // unlikely
        goto loc_0xc043db5c;
    loc_0xc043db90:
        r2 = [var_4h]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043dba4 // unlikely
        goto loc_0xc043dba0;
    loc_0xc043dba4:
        sp += 0xc
        pop (r4, r5, pc)
        return r0;
    loc_0xc043db5c: // orphan
         r3 = (byte) [sp]
         r0 = 0
         r2 = (byte) [var_0h]
         r3 = r3 << 8
         r3 &= 0x3f00
         r3 = r2 | r3
         [r4 + 0x20] = (half) r3
         r3 = (byte) [var_0h]
         r2 = (byte) [var_0h]
         r3 = r3 << 8
         r3 &= 0x3f00
         r3 = r2 | r3
         [r4 + 0x22] = (half) r3

}

// ----- END sitronix_ts_get_resolution -----

// ----- BEGIN sitronix_ts_get_customer_info (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_customer_info (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043eac8(x)
        push (r0, r1, r4, r5, r6, lr)
        r1 = 0xf1
        r4 = [0xc043dbc0] // [0xc043dc54:4]=0xc0a04e08
        r2 = sp
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x177fe8, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043dc38 // unlikely
        goto loc_0xc043dbdc;
    loc_0xc043dc38:
        r2 = [var_4h]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043dc4c // unlikely
        goto loc_0xc043dc48;
    loc_0xc043dc4c:
        sp += 8
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043dbdc: // orphan
         r6 = (byte) [sp]
         r2 = sp                  // r13
         r1 = 0xf1
         r0 = r5
         bic r3, r6, 3
         r3 |= 1
         [sp] = (byte) r3
         r3 = 1
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0xf1, 0x178000, 0x1)
         r3 = 4
         r1 = 0xc
         r0 = r5
         r2 = sp                  // r13
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xc, 0x178000, 0x4)
         r1 = 0xf1
         r0 = r5
         r3 = [sp]
         r2 = sp                  // r13
         [sp] = (byte) r6
         [r5 + 0x1a] = r3
         r3 = 1
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0xf1, 0x178000, 0x1)
         r0 = 0

}

// ----- END sitronix_ts_get_customer_info -----

// ----- BEGIN sitronix_ts_get_misc_info (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_misc_info (int32_t arg1) {
        push (r0, r1, r4, r5, r6, lr)
        r6 = 0
        r5 = [0xc043dc68] // [0xc043dcd0:4]=0xc0a04e08
        r2 = var_3h
        [r0 + 0x190] = (byte) r6 // arg1
        r1 = 0xf0
        [r0 + 0x8a] = (byte) r6 // arg1
        r4 = r0       // arg1
        r3 = [r5]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf0, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043dcb4 // unlikely
        goto loc_0xc043dc90;
    loc_0xc043dcb4:
        r2 = [var_4h]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043dcc8 // unlikely
        goto loc_0xc043dcc4;
    loc_0xc043dcc8:
        sp += 8
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043dc90: // orphan
         r3 = (byte) [var_3h]
         r0 = r6
         [r4 + 0x8a] = (byte) r6
         r2 = r3 >> 7
         [r4 + 0x28] = (byte) r3
         [r4 + 0x190] = (byte) r2
         ubfx r3, r3, 4, 1
         [r4 + 0x193] = (byte) r2
         [r4 + 0x8f] = (byte) r3

}

// ----- END sitronix_ts_get_misc_info -----

// ----- BEGIN sitronix_ts_set_smart_wake_up (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_set_smart_wake_up (int32_t arg1, int32_t arg2) {
        // CALL XREFS from sym.sitronix_fb_notifier_callback @ 0xc043c8e4(x), 0xc043c96c(x)
        // CALL XREF from sym.sitronix_ts_mt_reset_process @ 0xc0440670(x)
        push (r0, r1, r4, r5, r6, lr)
        r6 = r1       // arg2
        r4 = [0xc043dce4] // [0xc043dd6c:4]=0xc0a04e08
        r2 = var_3h
        r1 = 0xf1
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043dd50 // unlikely
        goto loc_0xc043dd04;
    loc_0xc043dd50:
        r2 = [var_4h]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043dd64 // unlikely
        goto loc_0xc043dd60;
    loc_0xc043dd64:
        sp += 8
        pop (r4, r5, r6, pc)
        goto loc_0xc043dd38;
        return r0;
    loc_0xc043dd38:
        r3 = 1
        r2 = var_3h
        r1 = 0xf1
        r0 = r5
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x178003, 0x1)
        r0 = 0
        break;
    loc_0xc043dd04: // orphan
         r3 = (byte) [var_3h]
         (a, b) = compare (r6, 0)
         r2 = var_3h
         r1 = 0xf1
         andeq r3, r3, 0x7f
         r0 = r5
         mvnne r3, r3, lsl 25
         mvnne r3, r3, lsr 25
         [var_3h] = (byte) r3
         r3 = 1
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0xf1, 0x178003, 0x1)
         (a, b) = compare (r0, 0)
         blt 0xc043dd50           // unlikely

}

// ----- END sitronix_ts_set_smart_wake_up -----

// ----- BEGIN sitronix_ts_get_swu_keycode (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_swu_keycode (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_report_swu @ 0xc043ce54(x)
        r0 -= 0x63    // arg1
        r0 = r0       // arg1
        (a, b) = compare (r0, 0x65) // 'e' // arg1
        ldrls r3, [pc, 8] // [0xc043dd8c:4]=0xc0731e88
        ldrsbls r0, [r3, r0]
        movhi r0, 0
        bx lr
}

// ----- END sitronix_ts_get_swu_keycode -----

// ----- BEGIN sitronix_ts_powerdown (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_powerdown (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_fb_notifier_callback @ 0xc043c914(x)
        // CALL XREF from sym.sitronix_ts_resume_work @ 0xc043cdd0(x)
        // CALL XREFS from sym.sitronix_ts_report_proximity_demo @ 0xc043cf1c(x), 0xc043cf64(x)
        // CALL XREF from sym.sitronix_ts_mt_reset_process @ 0xc0440684(x)
        push (r0, r1, r4, r5, r6, lr)
        r6 = r1       // arg2
        r4 = [0xc043dda0] // [0xc043de08:4]=0xc0a04e08
        r2 = var_3h
        r1 = 2
        r5 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x2, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043ddec // unlikely
        goto loc_0xc043ddc0;
    loc_0xc043ddec:
        r2 = [var_4h]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043de00 // unlikely
        goto loc_0xc043ddfc;
    loc_0xc043de00:
        sp += 8
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043ddc0: // orphan
         r3 = (byte) [var_3h]
         (a, b) = compare (r6, 0)
         r2 = var_3h
         r1 = 2
         orrne r3, r3, 2
         andeq r3, r3, 0xfd
         r0 = r5
         [var_3h] = (byte) r3
         r3 = 1
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0x2, 0x178003, 0x1)
         r0 &= r0

}

// ----- END sitronix_ts_powerdown -----

// ----- BEGIN sitronix_ts_proximity_enable (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_proximity_enable (int32_t arg1, int32_t arg2) {
        // CALL XREFS from sym.sitronix_stproximity_store @ 0xc0441a30(x), 0xc0441a48(x)
        // CALL XREF from sym.st_proc_stproximity_write @ 0xc04437b0(x)
        // CALL XREF from sym.st_dev_function @ 0xc0444594(x)
        push (r0, r1, r4, r5, r6, lr)
        r5 = r1       // arg2
        r4 = [0xc043de1c] // [0xc043de94:4]=0xc0a04e08
        r2 = var_3h
        r1 = 2
        r6 = r0       // arg1
        r3 = [r4]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x2, 0x177feb, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc043de78 // unlikely
        goto loc_0xc043de3c;
    loc_0xc043de78:
        r2 = [var_4h]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043de8c // unlikely
        goto loc_0xc043de88;
    loc_0xc043de8c:
        sp += 8
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc043de3c: // orphan
         r3 = (byte) [var_3h]
         (a, b) = compare (r5, 0)
         r2 = var_3h
         r1 = 2
         orrne r3, r3, 0x20
         andeq r3, r3, 0xdf
         r0 = r6
         [var_3h] = (byte) r3
         r3 = 1
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0x2, 0x178003, 0x1)
         (a, b) = compare (r0, 0)
         ldrge r3, [pc, 0x28]     // [0xc043de98:4]=0xc0a5d4d0
         movge r0, 0
         ldrge r3, [r3]
         strbge r5, [r3, 0x8b]

}

// ----- END sitronix_ts_proximity_enable -----

// ----- BEGIN sitronix_ts_get_swu_gesture (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_swu_gesture (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d074(x)
        push (r0, r1, r4, r5, r6, lr)
        r6 = r0 + 0x1c4 // arg1
        r5 = [0xc043def8] // [0xc043df94:4]=0xc0a04e08
        r6 += 2
        r2 = 5
        r1 = 7
        r4 = r0       // arg1
        r3 = [r5]
        [var_4h] = r3
        r3 = 0x5a     // 'Z'
        [var_2h] = (half) r3
        r3 = (byte) [r0 + 0x2a] // arg1
        mla r3, r1, r3, r2
        r2 = r6
        r1 = 0x10
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x10, 0x1c6, 0x6fe)
        (a, b) = compare (r0, 0)
        blt 0xc043df78 // unlikely
        goto loc_0xc043df30;
    loc_0xc043df78:
        r2 = [var_4h]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043df8c // unlikely
        goto loc_0xc043df88;
    loc_0xc043df8c:
        sp += 8
        pop (r4, r5, r6, pc)
        goto loc_0xc043df3c;
        return r0;
    loc_0xc043df3c:
        r2 = 4
        r1 = r6
        r0 = var_2h
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x178002, 0x0, 0x4)
        r2 = (byte) [r4 + 0x2a]
        (a, b) = compare (r2, 0)
        je 0xc043df6c // unlikely
        goto loc_0xc043df58;
    loc_0xc043df6c:
        r3 = (byte) [r4 + 0x1c8]
        r0 = 0
        [r4 + 0x88] = (byte) r3
            goto loc_0xc043df58;
    loc_0xc043df58:
        r1 = r4 + 0x1c8
        rsb r2, r2, r2, lsl 3
        r1 += 2
        r0 = var_2h
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x178002, 0x1ca, 0x0)
        return r0;
    loc_0xc043df30: // orphan
         r3 = (byte) [r4 + 0x8f]
         (a, b) = compare (r3, 0)
         je 0xc043df6c            // unlikely

}

// ----- END sitronix_ts_get_swu_gesture -----

// ----- BEGIN sitronix_ts_get_xy_chs (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_xy_chs (int32_t arg1, int32_t arg_fh) {
        // CALL XREF from sym.sitronix_ts_get_device_info @ 0xc043eb08(x)
        push (r4, r5, lr)
        sp -= 0x1c
        r5 = [0xc043ea48] // [0xc043eaac:4]=0xc0a04e08
        r4 = r0       // arg1
        r2 = 0x12
        r1 = var_2h
        r0 = 2
        r3 = [r5]
        [var_14h] = r3
        sym.TDU_FWInfoRead () // sym.TDU_FWInfoRead(0x2, 0x177fda, 0x12)
        r3 = (byte) [var_4h]
        r2 = [var_14h]
        [r4 + 0x24] = (byte) r3
        r3 = (byte) [var_4h]
        [r4 + 0x25] = (byte) r3
        r3 = (byte) [var_4h]
        [r4 + 0x26] = (byte) r3
        r3 = (byte) [var_4h]
        ubfx r3, r3, 3, 4
        [r4 + 0x27] = (byte) r3
        r3 = (byte) [arg_fh]
        [r4 + 0x2a] = (byte) r3
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043eaa0 // likely
        goto loc_0xc043ea9c;
    loc_0xc043eaa0:
        r0 = 0
        sp += 0x1c
        pop (r4, r5, pc)
        return r0;
}

// ----- END sitronix_ts_get_xy_chs -----

// ----- BEGIN sitronix_ts_get_device_info (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_device_info (int32_t arg1) {
        // XREFS: CALL 0xc043cad0  CALL 0xc043d43c  CALL 0xc0440f1c
        // XREFS: CALL 0xc0441044  CALL 0xc0441110  CALL 0xc0445ca0
        // XREFS: CALL 0xc0448728
        push (r4, lr)
        r4 = r0       // arg1
        sym.sitronix_ts_get_fw_revision () // sym.sitronix_ts_get_fw_revision(0x0)
        (a, b) = compare (r0, 0)
        popne (r4, pc)
        goto loc_0xc043eac4;
        break;
    loc_0xc043ead4: // orphan
         r0 = r4
         sym.sitronix_ts_get_resolution () // sym.sitronix_ts_get_resolution(0x0)
         (a, b) = compare (r0, 0)
         popne (r4, pc)

    loc_0xc043eae4: // orphan
         r0 = r4
         sym.sitronix_ts_get_max_touches () // sym.sitronix_ts_get_max_touches(0x0)
         (a, b) = compare (r0, 0)
         popne (r4, pc)

    loc_0xc043eaf4: // orphan
         r0 = r4
         sym.sitronix_ts_get_chip_id () // sym.sitronix_ts_get_chip_id(0x0)
         (a, b) = compare (r0, 0)
         popne (r4, pc)

    loc_0xc043eb04: // orphan
         r0 = r4
         sym.sitronix_ts_get_xy_chs () // sym.sitronix_ts_get_xy_chs(0x0, 0x0)
         (a, b) = compare (r0, 0)
         popne (r4, pc)

    loc_0xc043eb14: // orphan
         r0 = r4
         pop (r4, lr)
         
}

// ----- END sitronix_ts_get_device_info -----

// ----- BEGIN sitronix_mode_switch_value (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mode_switch_value (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg_2h, int32_t arg_3h) {
        // CALL XREF from sym.sitronix_stmodeswitch_store @ 0xc0440d40(x)
        // CALL XREF from sym.sitronix_proc_grip_write @ 0xc04440b4(x)
        push (r0, r1, r2, r4, r5, r6, r7, lr)
        (a, b) = compare (r0, 8) // arg1
        r4 = [0xc043ec30] // [0xc043ecf4:4]=0xc0a04e08
        r3 = [r4]
        [var_4h] = r3
        ble 0xc043ec50 // likely
        goto loc_0xc043ec38;
    loc_0xc043ec50:
        (a, b) = compare (r0, 1) // arg1
        r6 = r0       // arg1
        r5 = r1       // arg2
        bne 0xc043ec78 // likely
        goto loc_0xc043ec60;
    while (/* 0xc043ec78 */) {
        // CODE XREF from sym.sitronix_mode_switch_value @ 0xc043ec74(x)
        r2 = [var_4h_2]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043ecec // unlikely
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        // CODE XREF from sym.sitronix_mode_switch_value @ 0xc043ece8(x)
        r0 = 0
        goto 0xc043ec3c
        r3 = [0xc043ec68] // [0xc043ecf8:4]=0xc0a5d4d0
        r3 = [r3]
        [r3 + 0x190] = (byte) r1 // arg2
        [r3 + 0x193] = (byte) r1 // arg2
    }
    while (/* 0xc043eca4 */) {
    }
    while (/* 0xc043ecc4 */) {
        r0 = ~0x15
    }
    loc_0xc043ecd4:
        r3 = [0xc043ecdc] // [0xc043ecf8:4]=0xc0a5d4d0
        r0 = [r3]
        r0 += r6
        [r0 + 0x192] = (byte) r5
        [r0 + 0x1a6] = (byte) r7
        goto 0xc043ec70
        
        return r0;
}

// ----- END sitronix_mode_switch_value -----

// ----- BEGIN sitronix_mode_switch (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mode_switch (void) {
        // XREFS: CALL 0xc0440d8c  CALL 0xc0443b88  CALL 0xc0443c64
        // XREFS: CALL 0xc0443d40  CALL 0xc0443e1c  CALL 0xc0443ef8
        // XREFS: CALL 0xc0443fd4
        r2 = 0
        goto sym.sitronix_mode_switch_value // sym.sitronix_mode_switch_value(0x0, 0x0, 0x0, 0x0, 0x0)
}

// ----- END sitronix_mode_switch -----

// ----- BEGIN sitronix_mode_backup (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mode_backup (int32_t arg_3h) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cc88(x)
        r3 = [0xc043ed0c] // [0xc043ed74:4]=0xc0a04e08
        push (r0, r1, r4, r5, r6, lr)
        r4 = 2
        r2 = [r3]
        r5 = r3
        r6 = [0xc043ed20] // [0xc043ed78:4]=0xc0a5d4d0
        [var_4h] = r2
        
    do {
        r2 = 1
        r1 = var_3h
        r0 = r4
        sym.TDU_FWControlRead () // sym.TDU_FWControlRead(0x0, 0x178003, 0x1)
        r3 = [r6]
        r3 += r4
        r4 += 1
        (a, b) = compare (r4, 8)
        r2 = (byte) [arg_3h]
        r1 = r2 >> 7
        r2 &= 0x7f
        [r3 + 0x192] = (byte) r1
        [r3 + 0x1a6] = (byte) r2
        bne 0xc043ed20 // likely
    } while (/* 0xc043ed20 */);
    loc_0xc043ed58:
        r2 = [var_4h_2]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc043ed6c // unlikely
        goto loc_0xc043ed68;
    loc_0xc043ed6c:
        sp += 8
        pop (r4, r5, r6, pc)
}

// ----- END sitronix_mode_backup -----

// ----- BEGIN sitronix_swk_config_backup (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_swk_config_backup (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cc8c(x)
        push (r4, lr)
        r4 = [0xc043ed88] // [0xc043edd8:4]=0xc0a5d4d0
        r1 = [r4]
        (a, b) = compare (r1, 0)
        popeq (r4, pc) // r13
        return r0;
        break;
}

// ----- END sitronix_swk_config_backup -----

// ----- BEGIN sitronix_swk_config_restore (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_swk_config_restore (void) {
        // CALL XREF from sym.sitronix_fb_notifier_callback @ 0xc043c948(x)
        // CALL XREF from sym.sitronix_ts_resume_work @ 0xc043ce04(x)
        // CALL XREF from sym.sitronix_proc_stswktapmode_write @ 0xc04439a4(x)
        // CALL XREF from sym.sitronix_proc_stswkselect_write @ 0xc0443ac8(x)
        r3 = [0xc043ede4] // [0xc043ee00:4]=0xc0a5d4d0
        r1 = [r3]
        (a, b) = compare (r1, 0)
        je lr
        r1 += 0x1b8
        r2 = 4
        r1 += 2
        r0 = 0
        goto sym.TDU_Cmdio_WriteSWKConfig // sym.TDU_Cmdio_WriteSWKConfig(0x0, 0x1ba, 0x4)
}

// ----- END sitronix_swk_config_restore -----

// ----- BEGIN sitronix_get_ic_position (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_get_ic_position (int32_t arg1) {
        // CALL XREF from sym.st_self_test @ 0xc04493a4(x)
        // CALL XREF from sym.sitronix_touch_selftest @ 0xc04496d4(x)
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x2c
        sl = [0xc043ee14] // [0xc043f09c:4]=0xc0a04e08
        r2 = 5
        r4 = [0xc043ee1c] // [0xc043f0a0:4]=0xc0a5d4d0
        r1 = var_1ah
        [var_ch] = r0 // arg1
        r5 = 0
        r3 = [sl]
        r8 = 0x53     // 'S'
        r0 = [r4]
        fp = 0x23     // '#'
        [var_1ah] = r5
        r7 = 3
        [var_1eh] = r5
        r6 = 6
        [var_24h] = r3
        r3 = 0x71     // 'q'
        [var_22h] = (half) r5
        sb = ~3
        [var_1ah] = (byte) r3
        r3 = ~0x5a
        [var_1ah] = (byte) r8
        [var_1eh] = (byte) r3
        r3 = 0x3c     // '<'
        [var_1ah] = (byte) fp
        [var_1eh] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fca, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x71     // 'q'
        r1 = var_1ah
        [var_1ah] = (byte) r3
        [var_1ah] = (byte) r8
        r3 = 0x14
        [var_1ah] = (byte) fp
        [var_1eh] = (byte) r3
        r3 = 0x55     // 'U'
        [var_1eh] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fca, 0x5)
        r2 = 9
        r0 = [r4]
        r3 = 0x5a     // 'Z'
        r1 = var_1ah
        [var_1eh] = (byte) r3
        [var_1ah] = (byte) r7
        r3 = ~0x62
        [var_1ah] = (byte) r6
        [var_1eh] = (byte) r3
        r3 = ~0x42
        [var_1ah] = (byte) sb
        [var_1eh] = (byte) r3
        [var_1eh] = (byte) r5
        [var_22h] = (byte) r5
        [var_22h] = (byte) r5
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fca, 0x9)
        (a, b) = compare (r0, r5)
        [var_10h] = sl
        (>=) goto 0xc043ef0c // likely
        goto loc_0xc043eef0;
    while (/* 0xc043ef0c */) {
        r0 = ~0
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        // CODE XREF from sym.sitronix_get_ic_position @ 0xc043f090(x)
        r3 = [var_10h]
        r2 = [var_24h]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc043f094 // unlikely
    }
    while (/* 0xc043ef40 */) {
    }
    while (/* 0xc043ef80 */) {
    }
    loc_0xc043f018:
        r0 = [sl]
        r1 = var_1ah
        r3 = [var_14h]
        r2 = [var_ch]
        r0 += r3
        r3 = (word) [r0 + 4]
        [var_1ah] = (byte) r8
        [var_1ah] = (byte) fp
        [r2] = (half) r3
        r2 = 5
        r0 = [r4]
        r3 = 0x71     // 'q'
        [var_1ah] = (byte) r3
        r3 = 0x41     // 'A'
        [var_1eh] = (byte) r3
        r3 = 0x4c     // 'L'
        [var_1eh] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(-1, 0x17801a, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x71     // 'q'
        r1 = var_1ah
        [var_1ah] = (byte) r8
        [var_1ah] = (byte) r3
        r3 = 0x5a     // 'Z'
        [var_1ah] = (byte) fp
        [var_1eh] = (byte) r3
        r3 = ~0x3c
        [var_1eh] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(-1, 0x17801a, 0x5)
        goto 0xc043eef4
        
        goto loc_0xc043ef08;
        return r0;
}

// ----- END sitronix_get_ic_position -----

// ----- BEGIN sitronix_get_chip_id (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_get_chip_id (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043ca98(x)
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x1c
        r4 = [0xc043f0bc] // [0xc043f1dc:4]=0xc0a04e08
        r2 = 5
        r5 = [0xc043f0c4] // [0xc043f1e0:4]=0xc0a5d4d0
        r1 = var_ch
        sb = 0x53     // 'S'
        r8 = 0x71     // 'q'
        r3 = [r4]
        r7 = 0x23     // '#'
        r0 = [r5]
        r6 = 0x55     // 'U'
        [var_14h] = r3
        r3 = 0
        [var_ch] = r3
        [var_10h] = r3
        r3 = ~0x5a
        [var_ch] = (byte) sb
        [var_10h] = (byte) r3
        r3 = 0x3c     // '<'
        [var_ch] = (byte) r8
        [var_10h] = (byte) r3
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r2 = 5
        r0 = [r5]
        r3 = 0x14
        r1 = var_ch
        [var_10h] = (byte) r3
        [var_10h] = (byte) r6
        [var_ch] = (byte) sb
        [var_ch] = (byte) r8
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r2 = 5
        r0 = [r5]
        r1 = var_ch
        [var_10h] = (byte) r6
        [var_10h] = (byte) r6
        [var_ch] = (byte) sb
        [var_ch] = (byte) r8
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r0 = [0xc043f160] // [0xc043f1e4:4]=0xc0a5d4cc
        r2 = ~0x7e
        r3 = [r0]
        [r3 + 1] = (byte) r2
        r2 = 1
        r3 = [r0]
        [r3 + 2] = (byte) r2
        r2 = 0x1e
        r3 = [r0]
        [r3 + 3] = (byte) r2
        r3 = [r5]
        r5 = [0xc043f18c] // [0xc043f1e8:4]=0xc0a5d4c8
        r3 = [r3 + 0x10]
        r2 = [r3 + 0x14]
        [sp] = r2
        r6 = [r3 + 0x28]
        r3 = 3
        r1 = r3
        r2 = [r5]
        r0 = [r0]
        r6 ()         // 0xffffffff(0x0, 0x3, 0x0, 0x3)
        (a, b) = compare (r0, 0)
        r2 = [var_14h]
        ldrge r3, [r5]
        mvnlt r0, 0
        addge r0, r3, r0
        r3 = [r4]
        ldrbge r0, [r0, 1]
        (a, b) = compare (r2, r3)
        je 0xc043f1d4 // likely
        goto loc_0xc043f1d0;
    loc_0xc043f1d4:
        sp += 0x1c    // "q"
        pop (r4, r5, r6, r7, r8, sb, pc)
        return r0;
}

// ----- END sitronix_get_chip_id -----

// ----- BEGIN sitronix_get_ic_sfrver (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_get_ic_sfrver (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043caa4(x)
        // CALL XREF from sym.st_record_ic_info @ 0xc04488f0(x)
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x1c
        r4 = [0xc043f1fc] // [0xc043f31c:4]=0xc0a04e08
        r2 = 5
        r5 = [0xc043f204] // [0xc043f320:4]=0xc0a5d4d0
        r1 = var_ch
        sb = 0x53     // 'S'
        r8 = 0x71     // 'q'
        r3 = [r4]
        r7 = 0x23     // '#'
        r0 = [r5]
        r6 = 0x55     // 'U'
        [var_14h] = r3
        r3 = 0
        [var_ch] = r3
        [var_10h] = r3
        r3 = ~0x5a
        [var_ch] = (byte) sb
        [var_10h] = (byte) r3
        r3 = 0x3c     // '<'
        [var_ch] = (byte) r8
        [var_10h] = (byte) r3
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r2 = 5
        r0 = [r5]
        r3 = 0x14
        r1 = var_ch
        [var_10h] = (byte) r3
        [var_10h] = (byte) r6
        [var_ch] = (byte) sb
        [var_ch] = (byte) r8
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r2 = 5
        r0 = [r5]
        r1 = var_ch
        [var_10h] = (byte) r6
        [var_10h] = (byte) r6
        [var_ch] = (byte) sb
        [var_ch] = (byte) r8
        [var_ch] = (byte) r7
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fd4, 0x5)
        r0 = [0xc043f2a0] // [0xc043f324:4]=0xc0a5d4cc
        r2 = ~0x7e
        r3 = [r0]
        [r3 + 1] = (byte) r2
        r2 = 1
        r3 = [r0]
        [r3 + 2] = (byte) r2
        r2 = ~0x3d
        r3 = [r0]
        [r3 + 3] = (byte) r2
        r3 = [r5]
        r5 = [0xc043f2cc] // [0xc043f328:4]=0xc0a5d4c8
        r3 = [r3 + 0x10]
        r2 = [r3 + 0x14]
        [sp] = r2
        r6 = [r3 + 0x28]
        r3 = 3
        r1 = r3
        r2 = [r5]
        r0 = [r0]
        r6 ()         // 0xffffffff(0x0, 0x3, 0x0, 0x3)
        (a, b) = compare (r0, 0)
        r2 = [var_14h]
        ldrge r3, [r5]
        mvnlt r0, 0
        addge r0, r3, r0
        r3 = [r4]
        ldrbge r0, [r0, 1]
        (a, b) = compare (r2, r3)
        je 0xc043f314 // likely
        goto loc_0xc043f310;
    loc_0xc043f314:
        sp += 0x1c    // "q"
        pop (r4, r5, r6, r7, r8, sb, pc)
        return r0;
}

// ----- END sitronix_get_ic_sfrver -----

// ----- BEGIN sitronix_write_driver_cmd (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_write_driver_cmd (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS: CALL 0xc043cef8  CALL 0xc043cf08  CALL 0xc043cf50
        // XREFS: CALL 0xc043f558  CALL 0xc0441ecc  CALL 0xc0442a3c
        (a, b) = compare (r2, 0x7a) // 'z' // arg3
        push (r3, r4, r5, r6, r7, r8, sb, sl, fp, lr) // "UU"
        mvngt r5, 0
        bgt 0xc043f418 // unlikely
        goto loc_0xc043f33c;
    loc_0xc043f418:
        r0 = r5
        pop (r3, r4, r5, r6, r7, r8, sb, sl, fp, pc)
        goto loc_0xc043f364;
        return r0;
    loc_0xc043f364:
        r5 = [0xc043f36c] // [0xc043f51c:4]=0xc0a5d4d0
        fp = 0x53     // 'S'
        sl = 0x71     // 'q'
        sb = 0x23     // '#'
        r3 = ~0x5a
        r2 = 5
        [r4 + 4] = (byte) r3
        r1 = r4
        r3 = 0x3c     // '<'
        [r4 + 1] = (byte) fp
        [r4 + 5] = (byte) r3
        [r4 + 2] = (byte) sl
        [r4 + 3] = (byte) sb
        r0 = [r5]
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x0, 0x5)
        r3 = 0x14
        r2 = 5
        [r4 + 4] = (byte) r3
        r1 = r4
        r3 = 0x55     // 'U'
        [r4 + 1] = (byte) fp
        [r4 + 5] = (byte) r3
        [r4 + 2] = (byte) sl
        [r4 + 3] = (byte) sb
        r0 = [r5]
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x0, 0x5)
        r3 = 3
        r2 = 5
        [r4 + 1] = (byte) r3
        r1 = r4
        r3 = 6
        r0 = [r5]
        [r4 + 2] = (byte) r3
        r3 = ~3
        [r4 + 3] = (byte) r3
        r3 = 0x5a     // 'Z'
        [r4 + 4] = (byte) r3
        r3 = ~0x62
        [r4 + 5] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x0, 0x5)
        (a, b) = compare (r0, 0)
        (>=) goto 0xc043f420 // likely
        goto loc_0xc043f40c;
    while (/* 0xc043f420 */) {
        r5 = ~0
        // CODE XREF from sym.sitronix_write_driver_cmd @ 0xc043f514(x)
        r0 = r4
        sym.kfree ()  // sym.kfree(0x0)
    }
    loc_0xc043f484:
        r3 = ~0x5a
        [r4 + 4] = (byte) r8
        [r4 + 5] = (byte) r3
        r2 = 5
        r1 = r4
        r0 = [r5]
        [r4 + 1] = (byte) fp
        r8 = 0x53     // 'S'
        [r4 + 2] = (byte) sl
        r7 = 0x71     // 'q'
        [r4 + 3] = (byte) sb
        r6 = 0x23     // '#'
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(-1, 0x0, 0x5)
        r3 = 0x41     // 'A'
        r2 = 5
        [r4 + 4] = (byte) r3
        r1 = r4
        r3 = 0x4c     // 'L'
        r0 = [r5]
        [r4 + 5] = (byte) r3
        [r4 + 1] = (byte) r8
        [r4 + 2] = (byte) r7
        [r4 + 3] = (byte) r6
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(-1, 0x0, 0x5)
        r3 = 0x5a     // 'Z'
        r0 = [r5]
        r2 = 5
        [r4 + 4] = (byte) r3
        r1 = r4
        r3 = ~0x3c
        [r4 + 1] = (byte) r8
        [r4 + 2] = (byte) r7
        [r4 + 3] = (byte) r6
        [r4 + 5] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(-1, 0x0, 0x5)
        r5 = r0
        goto 0xc043f410
        
        return r0;
}

// ----- END sitronix_write_driver_cmd -----

// ----- BEGIN sitronix_ts_proximity_control_sensing (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_proximity_control_sensing (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_stproximity_store @ 0xc0441a78(x)
        // CALL XREF from sym.st_proc_stproximity_write @ 0xc044380c(x)
        push (r0, r1, r2, r3, r4, lr)
        (a, b) = compare (r1, 0) // arg2
        r3 = [0xc043f530] // [0xc043f57c:4]=0xc0a04e08
        addne r1, sp, 4
        movne r0, 0x11
        moveq r0, 0x10
        r2 = [r3]
        r4 = r3
        [var_ch] = r2
        r2 = 0
        [var_4h] = r2
        [var_8h] = r2
        moveq r2, r1
        addeq r1, sp, 4
        sym.sitronix_write_driver_cmd () // sym.sitronix_write_driver_cmd(0x10, 0x177fec, 0x0)
        r0 = 0
        r2 = [var_ch]
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc043f574 // likely
        goto loc_0xc043f570;
    loc_0xc043f574:
        sp += 0x10
        pop (r4, pc)
        return r0;
}

// ----- END sitronix_ts_proximity_control_sensing -----

// ----- BEGIN sitronix_read_driver_cmd (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_read_driver_cmd (int32_t arg1, int32_t arg2, int32_t arg3) {
        // CALL XREF from sym.st_proc_stdrivercmd_write @ 0xc0441d7c(x)
        // CALL XREF from sym.sitronix_stdrivercmd_store @ 0xc04428ec(x)
        r3 = [0xc043f588] // [0xc043f848:4]=0xc0a04e08
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x3c
        r3 = [r3]
        sl = r0       // arg1
        [var_ch] = r1 // arg2
        r0 = var_14h
        [var_8h] = r2 // arg3
        r1 = 0
        r2 = 0x20
        [var_34h] = r3
        sym.memset () // void *memset(0x00000000, 0, -1)
        r3 = [var_ch]
        (a, b) = compare (r3, 0x1a)
        mvnhi r0, 0
        bhi 0xc043f828 // unlikely
        goto loc_0xc043f5c0;
    loc_0xc043f828:
        r3 = [0xc043f830] // [0xc043f848:4]=0xc0a04e08
        r2 = [var_34h_2]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc043f840 // likely
        goto loc_0xc043f83c;
    loc_0xc043f840:
        sp += 0x3c
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        return r0;
    loc_0xc043f5c0: // orphan
         r4 = [0xc043f5c8]        // [0xc043f84c:4]=0xc0a5d4d0
         r2 = 5
         r1 = var_14h_2
         sb = 0x23                // '#'
         r8 = ~0x5a
         r3 = 0x53                // 'S'
         r0 = [r4]
         r5 = 0
         [var_14h_2] = (byte) r3
         r3 = 0x71                // 'q'
         [var_14h_2] = (byte) sb
         r6 = 3
         [var_14h_2] = (byte) r3
         r3 = 0x3c                // '<'
         [var_18h] = (byte) r8
         r7 = 6
         [var_18h] = (byte) r3
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178014, 0x5)
         r2 = 5
         r0 = [r4]
         r3 = 0x53                // 'S'
         fp = 0x5a                // 'Z'
         r1 = var_14h_2
         [var_14h_2] = (byte) r3
         [var_14h_2] = (byte) sb
         r3 = 0x71                // 'q'
         [var_14h_2] = (byte) r3
         r3 = 0x14
         [var_18h] = (byte) r3
         r3 = 0x55                // 'U'
         [var_18h] = (byte) r3
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178014, 0x5)
         r2 = 9
         r0 = [r4]
         r3 = ~3
         r1 = var_14h_2
         [var_14h_2] = (byte) r3
         [var_14h_2] = (byte) r6
         r3 = ~0x62
         [var_14h_2] = (byte) r7
         [var_18h] = (byte) r3
         r3 = ~0x42
         [var_18h] = (byte) fp
         [var_18h] = (byte) r3
         [var_18h] = (byte) r5
         [var_1ch] = (byte) r5
         [var_1ch] = (byte) r5
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178014, 0x9)
         r2 = 5
         r0 = [r4]
         r3 = ~1
         r1 = var_14h_2
         [var_14h_2] = (byte) r3
         [var_14h_2] = (byte) r6
         [var_14h_2] = (byte) r7
         [var_18h] = (byte) r5
         [var_18h] = (byte) r8
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178014, 0x5)
         r2 = 7
         r0 = [r4]
         r3 = ~3
         r1 = var_14h_2
         [var_14h_2] = (byte) r3
         [var_18h] = (byte) sl
         r3 = ~0x61
         [var_14h_2] = (byte) r6
         [var_18h] = (byte) r3
         [var_14h_2] = (byte) r7
         [var_18h] = (byte) fp
         [var_18h] = (byte) r5
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178014, 0x7)
         r3 = ~0x7c
         sl = [0xc043f6e8]        // [0xc043f850:4]=0xc0a5d4cc
         r1 = r6
         [var_14h_2] = (byte) r3
         r3 = 7
         [var_14h_2] = (byte) r3
         r0 = var_14h_2
         r3 = [r4]
         [var_14h_2] = (byte) r5
         r3 = [r3 + 0x10]
         r2 = [r3 + 0x14]
         [sp] = r2
         r3 = [r3 + 0x30]
         r2 = [sl]
         ip = r3
         r3 = (word) [var_ch]
         ip ()                    // 0xffffffff(0x178014, 0x3, 0x0, 0x0)
         r1 = [sl]
         r2 = [var_ch]
         r1 += r0
         r0 = [var_ch_2]
         sym.memcpy () // void *memcpy(0, 0x00078300, 0)
         r2 = 5
         r0 = [r4]
         r3 = ~1
         r1 = var_1ch
         [var_1ch] = (byte) r3
         [var_1ch] = (byte) r6
         [var_1ch] = (byte) r7
         [var_18h_2] = (byte) r5
         [var_18h_2] = (byte) r8
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178018, 0x5)
         r2 = 9
         r0 = [r4]
         r3 = ~3
         r1 = var_1ch
         [var_1ch] = (byte) r3
         [var_1ch] = (byte) r6
         r3 = ~0x62
         [var_1ch] = (byte) r7
         [var_18h_2] = (byte) r3
         r3 = ~0x42
         [var_18h_2] = (byte) fp
         [var_18h_2] = (byte) r3
         [var_18h_2] = (byte) r5
         [var_1ch_2] = (byte) r6
         [var_1ch_2] = (byte) r5
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178018, 0x9)
         r2 = 5
         r0 = [r4]
         r3 = ~1
         r1 = var_1ch
         [var_1ch] = (byte) r3
         [var_1ch] = (byte) r6
         [var_1ch] = (byte) r7
         [var_18h_2] = (byte) r5
         [var_18h_2] = (byte) r8
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178018, 0x5)
         r2 = 5
         r0 = [r4]
         r3 = 0x53                // 'S'
         r1 = var_1ch
         [var_1ch] = (byte) r3
         [var_1ch] = (byte) sb
         r3 = 0x71                // 'q'
         [var_1ch] = (byte) r3
         r3 = 0x41                // 'A'
         [var_18h_2] = (byte) r3
         r3 = 0x4c                // 'L'
         [var_18h_2] = (byte) r3
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178018, 0x5)
         r2 = 5
         r0 = [r4]
         r3 = 0x53                // 'S'
         r1 = var_1ch
         [var_1ch] = (byte) r3
         [var_1ch] = (byte) sb
         r3 = 0x71                // 'q'
         [var_18h_2] = (byte) fp
         [var_1ch] = (byte) r3
         r3 = ~0x3c
         [var_18h_2] = (byte) r3
         sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x178018, 0x5)

}

// ----- END sitronix_read_driver_cmd -----

// ----- BEGIN sitronix_swite_driver_deep_standby (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_swite_driver_deep_standby (void) {
        r3 = [0xc043f85c] // [0xc043fb64:4]=0xc0a04e08
        r2 = 0x10
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x24
        r3 = [r3]
        r1 = 0
        r0 = var_ch
        r4 = [0xc043f878] // [0xc043fb68:4]=0xc0a5d4d0
        sb = 0x71     // 'q'
        r8 = 0x23     // '#'
        [var_1ch] = r3
        sym.memset () // void *memset(0x00000000, 0, -1)
        r2 = 5
        r0 = [r4]
        fp = ~0x5a
        r3 = 0x53     // 'S'
        r5 = 0
        r7 = 3
        r6 = 6
        sl = 0x5a     // 'Z'
        r1 = var_ch_2
        [var_ch_2] = (byte) r3
        [var_ch_2] = (byte) sb
        r3 = 0x3c     // '<'
        [var_ch_2] = (byte) r8
        [var_11h] = (byte) r3
        [var_10h] = (byte) fp
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x53     // 'S'
        r1 = var_ch_2
        [var_ch_2] = (byte) r3
        [var_ch_2] = (byte) sb
        r3 = 0x14
        [var_ch_2] = (byte) r8
        [var_10h] = (byte) r3
        r3 = 0x55     // 'U'
        [var_11h] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r2 = ~0x5d
        r0 = [r4]
        r3 = ~3
        [var_16h] = (byte) r2
        r1 = var_ch_2
        r2 = 0xb
        [var_ch_2] = (byte) r3
        [var_ch_2] = (byte) r7
        r3 = ~0x62
        [var_ch_2] = (byte) r6
        [var_11h] = (byte) r3
        r3 = 0x60     // '`'
        [var_10h] = (byte) sl
        [var_11h] = (byte) r3
        [var_4h] = r3
        [var_11h] = (byte) r5
        [var_11h] = (byte) sb
        [var_15h] = (byte) r8
        [var_16h] = (byte) r5
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0xb)
        r2 = 5
        r0 = [r4]
        r3 = ~1
        r1 = var_ch_2
        [var_ch_2] = (byte) r3
        [var_ch_2] = (byte) r7
        [var_ch_2] = (byte) r6
        [var_10h] = (byte) r5
        [var_11h] = (byte) fp
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r0 = 1
        sym.msleep () // sym.msleep(0x1, 0x177fc8)
        r3 = ~3
        r2 = ~0x5c
        r0 = [r4]
        [var_11h] = (byte) r3
        r3 = ~0x62
        [var_15h] = (byte) r3
        r1 = var_10h
        r3 = [var_ch]
        [var_1ch] = (byte) r2
        r2 = 8
        [var_11h] = (byte) r7
        [var_16h] = (byte) r3
        [var_11h] = (byte) r6
        [var_11h] = (byte) sl
        [var_16h] = (byte) r5
        [var_1ch] = (byte) sb
        [var_1ch] = (byte) r8
        [var_1ch] = (byte) r5
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x8)
        r2 = 5
        r0 = [r4]
        r3 = ~1
        r1 = var_10h
        [var_11h] = (byte) r3
        [var_11h] = (byte) r7
        [var_11h] = (byte) r6
        [var_11h] = (byte) r5
        [var_15h] = (byte) fp
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r0 = 1
        sym.msleep () // sym.msleep(0x1, 0x177fc8)
        r3 = ~3
        r2 = 8
        r0 = [r4]
        [var_16h] = (byte) r3
        r3 = ~0x62
        [var_1ch] = (byte) r3
        r1 = var_ch_3
        r3 = [var_ch_2]
        [var_15h] = (byte) r7
        [var_16h] = (byte) r6
        [var_1ch] = (byte) r3
        r3 = ~0x5b
        [var_1ch] = (byte) sl
        [var_16h_2] = (byte) r3
        [var_1ch] = (byte) r5
        [var_14h] = (byte) sb
        [var_14h] = (byte) r8
        [var_16h_2] = (byte) r5
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x8)
        r2 = 5
        r0 = [r4]
        r3 = ~1
        r1 = var_ch_3
        [var_16h] = (byte) r3
        [var_15h] = (byte) r7
        [var_16h] = (byte) r6
        [var_1ch] = (byte) r5
        [var_1ch] = (byte) fp
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r0 = 1
        sym.msleep () // sym.msleep(0x1, 0x177fc8)
        r2 = 9
        r0 = [r4]
        r3 = ~3
        r1 = var_1ch
        [var_1ch] = (byte) r3
        [var_1ch] = (byte) r7
        r3 = ~0x62
        [var_1ch] = (byte) r6
        [var_14h] = (byte) r3
        r3 = 0x4f     // 'O'
        [var_14h] = (byte) sl
        [var_16h_2] = (byte) r3
        r3 = 1
        [var_16h_2] = (byte) r5
        [var_16h_2] = (byte) r3
        [var_10h] = r3
        [var_16h_2] = (byte) r5
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x9)
        r2 = 5
        r0 = [r4]
        r3 = ~1
        r1 = var_1ch
        [var_1ch] = (byte) r3
        [var_1ch] = (byte) r7
        [var_1ch] = (byte) r6
        [var_14h] = (byte) r5
        [var_14h] = (byte) fp
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r3 = [var_10h]
        r0 = r3
        sym.msleep () // sym.msleep(0x1, 0x177fc8)
        r2 = 5
        r0 = [r4]
        r3 = 0x53     // 'S'
        r1 = var_14h
        [var_14h] = (byte) r3
        [var_16h_2] = (byte) sb
        r3 = 0x41     // 'A'
        [var_16h_2] = (byte) r8
        [var_16h_2] = (byte) r3
        r3 = 0x4c     // 'L'
        [var_16h_2] = (byte) r3
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x53     // 'S'
        r1 = var_14h
        [var_14h] = (byte) r3
        [var_16h_2] = (byte) sb
        r3 = ~0x3c
        [var_16h_2] = (byte) r8
        [var_16h_2] = (byte) r3
        [var_16h_2] = (byte) sl
        sym.sitronix_ts_addrmode_write () // sym.sitronix_ts_addrmode_write(0x0, 0x177fc8, 0x5)
        r3 = [0xc043fb4c] // [0xc043fb64:4]=0xc0a04e08
        r2 = [var_1ch_2]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc043fb5c // likely
        goto loc_0xc043fb58;
    loc_0xc043fb5c:
        sp += 0x24
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        return r0;
}

// ----- END sitronix_swite_driver_deep_standby -----

// ----- BEGIN sitronix_ts_read_raw_aa (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_read_raw_aa (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_ts_enable_raw @ 0xc043fec8(x)
        // CALL XREF from sym.sitronix_ts_get_rawdata @ 0xc043ff84(x)
        r3 = [0xc043fb74] // [0xc043fce8:4]=0xc08272d0
        push (r0, r1, r2, r4, r5, r6, r7, r8, sb, sl, fp, lr)
        r8 = r0       // arg1
        sb = r1       // arg2
        r0 = [r3 + 0x1c]
        r1 = 0xdc0
        sym.kmem_cache_alloc () // sym.kmem_cache_alloc(0x0, 0xdc0)
        r4 = r0 - 0
        mvneq sl, 0xb
        je 0xc043fc1c // likely
        goto loc_0xc043fb94;
    loc_0xc043fc1c:
        r0 = sl
        sp += 0xc
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        return r0;
    loc_0xc043fbe4: // orphan
         r3 = [r6]
         r5 = 0
         r7 = [0xc043fbf4]        // [0xc043fcec:4]=0xc0a5d4d0
         r6 = r5
         r3 = (byte) [r3 + 0x24]
         r3 = r3 << 1
         [var_4h] = r3

         goto loc_0xc043fc44;
    loc_0xc043fc44: // orphan
         r3 = 0x50                // 'P'
         r2 = r4
         r1 = 0x140
         r0 = r8
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x140, 0x0, 0x50)
         sl = r0 - 0
         blt 0xc043fc14           // unlikely

    loc_0xc043fc14: // orphan
         // CODE XREFS from sym.sitronix_ts_read_raw_aa @ 0xc043fc40(x), 0xc043fce4(x)
         r0 = r4
         sym.kfree ()             // sym.kfree(0x0)

         goto loc_0xc043fc60;
    loc_0xc043fc60: // orphan
         r3 = (byte) [r4]
         (a, b) = compare (r3, 0x13)
         bne 0xc043fcc8           // likely

    loc_0xc043fcc8: // orphan
         r0 = 1
         r6 += 1
         sym.msleep ()            // sym.msleep(0x1, 0x0)
         r3 = [var_4h_2]
         (a, b) = compare (r3, r6)
         (>=) 
    loc_0xc043fc00: // orphan
         r3 = [r7]
         r3 = (byte) [r3 + 0x24]
         (a, b) = compare (r5, r3)
         blt 0xc043fc44           // likely

         goto loc_0xc043fce0;
    loc_0xc043fce0: // orphan
         sl = ~1
         
         goto loc_0xc043fc6c;
    loc_0xc043fc6c: // orphan
         r3 = (byte) [r4 + 1]
         r0 = r4 + 4
         lr = (byte) [r4 + 2]
         r1 = 0
         r3 -= 3
         sl = (byte) [r4 + 3]
         add r3, r3, r3, lsr 31
         r3 = r3 >> 1

         goto loc_0xc043fc9c;
    loc_0xc043fc9c: // orphan
         r2 = [r7]
         fp = (byte) [r0 - 2]
         ip = (byte) [r2 + 0x25]
         r2 = r1 + sl
         r1 += 1
         mla ip, ip, lr, r2
         r2 = (byte) [r0 - 1]
         r2 |= fp
         r2 = (short) r2
         str r2, [sb, ip, lsl 2]
         
    loc_0xc043fc8c: // orphan
         // CODE XREF from sym.sitronix_ts_read_raw_aa @ 0xc043fcc4(x)
         (a, b) = compare (r1, r3)
         r0 += 2
         addge r5, r5, 1
         (>=) 
         goto loc_0xc043fc10;
    loc_0xc043fc10: // orphan
         sl = 0

         goto loc_0xc043fbbc;
    loc_0xc043fbbc: // orphan
         r3 = 0x50                // 'P'
         r2 = r4
         r1 = 0x140
         r0 = r8
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x140, 0x0, 0x50)
         sl = r0 - 0
         blt 0xc043fc14           // unlikely

         goto loc_0xc043fbd8;
    loc_0xc043fbd8: // orphan
         r3 = (byte) [r4]
         (a, b) = compare (r3, 0x10)
         bne 0xc043fc28           // likely

    loc_0xc043fc28: // orphan
         r7 += 1
         r0 = 1
         sym.msleep ()            // sym.msleep(0x1, 0x0)
         (a, b) = compare (r5, r7)
         (>=) 
    loc_0xc043fbb4: // orphan
         (a, b) = compare (r7, r5)
         je 0xc043fbe4            // likely

         goto loc_0xc043fc3c;
    loc_0xc043fc3c: // orphan
         sl = ~0
         
}

// ----- END sitronix_ts_read_raw_aa -----

// ----- BEGIN sitronix_ts_enable_raw (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_enable_raw (int32_t arg1, int32_t arg2, int32_t arg_4h) {
        // CALL XREFS from sym.sitronix_proc_strawdata_test_write @ 0xc0444248(x), 0xc04442a4(x)
        r2 = [0xc043fcf8] // [0xc043ff60:4]=0xc0a04e08
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x14
        r3 = [r2]
        r5 = [0xc043fd08] // [0xc043ff64:4]=0xc0a5d4dc
        [sp] = r2
        [var_ch] = r3
        r3 = [r5]
        (a, b) = compare (r3, r1) // arg2
        moveq r8, 0
        je 0xc043fdac // likely
        goto loc_0xc043fd1c;
    loc_0xc043fdac:
        // CODE XREFS from sym.sitronix_ts_enable_raw @ 0xc043fde8(x), 0xc043ff08(x)
        r3 = [sp]
        r0 = r8
        r2 = [var_ch]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc043ff58 // unlikely
        goto loc_0xc043fdc4;
    loc_0xc043ff58:
        sp += 0x14
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        goto loc_0xc043fd2c;
        return r0;
    loc_0xc043fd2c:
        (a, b) = compare (r1, 0) // arg2
        r7 = r0       // arg1
        bne 0xc043fdec // unlikely
        goto loc_0xc043fd38;
    loc_0xc043fdec:
        r3 -= 1
        (a, b) = compare (r3, 1)
        bls 0xc043ff44 // unlikely
        goto loc_0xc043fdf8;
    loc_0xc043ff44:
        r0 = 0
        r8 = r0
        goto 0xc043fef8
        
    loc_0xc043fef8:
        // CODE XREF from sym.sitronix_ts_enable_raw @ 0xc043ff4c(x)
        [r5] = sl
        return r0;
    loc_0xc043fd1c: // orphan
         (a, b) = compare (r1, 2) // arg2
         sl = r1                  // arg2
         mvngt r8, 0x15
         bgt 0xc043fdac           // unlikely

    loc_0xc043ff04: // orphan
         sym.kfree ()             // sym.kfree(0x0)
         
         goto loc_0xc043fdf8;
    loc_0xc043fdf8: // orphan
         r3 = 1
         r2 = var_ah
         r1 = 0xf1
         r4 = 6
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x17800a, 0x1)
         r3 = (byte) [var_ah]
         bic r3, r3, 0x5c
         r3 |= 0x58
         [var_ah] = (byte) r3

         goto loc_0xc043fe68;
    loc_0xc043fe68: // orphan
         r3 = (byte) [r7 + 0x25]
         r1 = 0xcc0
         fp = (byte) [r7 + 0x24]
         r6 = 5
         smulbb fp, fp, r3
         sb = fp << 2
         r0 = sb
         sym.__kmalloc ()         // sym.__kmalloc(0x3fc, 0xcc0)
         r2 = sb
         r1 = 0
         [r5 + 4] = r0
         sym.memset () // void *memset(-1, 0, -1)
         r1 = 0xcc0
         r0 = sb
         sym.__kmalloc ()         // sym.__kmalloc(0x3fc, 0xcc0)
         r3 = r0 + sb
         r4 = r0

         goto loc_0xc043ff50;
    loc_0xc043ff50: // orphan
         r0 = r4
         
    loc_0xc043fefc: // orphan
         // CODE XREF from sym.sitronix_ts_enable_raw @ 0xc043ff54(x)
         (a, b) = compare (r0, 0)
         je 0xc043fdac            // likely

         goto loc_0xc043fed4;
    loc_0xc043fed4: // orphan
         r3 = [arg_4h]
         r2 = r4

         goto loc_0xc043ff0c;
    loc_0xc043ff0c: // orphan
         ip = [r5 + 4]
         r0 = r2 - r4
         lr = [r2] + 4
         r1 = [ip + r0]
         r1 += lr
         [ip + r0] = r1
         
    loc_0xc043fedc: // orphan
         // CODE XREF from sym.sitronix_ts_enable_raw @ 0xc043ff24(x)
         (a, b) = compare (r3, r2)
         bne 0xc043ff0c           // unlikely

         goto loc_0xc043fee4;
    loc_0xc043fee4: // orphan
         r6 -= 1
         bne 0xc043feac           // likely

    loc_0xc043feac: // orphan
         r2 = sb
         r1 = 0
         r0 = r4
         [arg_4h] = r3
         sym.memset () // void *memset(0, 0, 0)
         r1 = r4
         r0 = r7
         sym.sitronix_ts_read_raw_aa () // sym.sitronix_ts_read_raw_aa(0x0, 0x0)
         r8 = r0 - 0
         blt 0xc043ff50           // unlikely

         goto loc_0xc043feec;
    loc_0xc043feec: // orphan
         // CODE XREF from sym.sitronix_ts_enable_raw @ 0xc043ff40(x)
         (a, b) = compare (r6, fp)
         bne 0xc043ff28           // likely

    loc_0xc043ff28: // orphan
         r7 = [r5 + 4]
         r1 = 5
         ldr r0, [r7, r6, lsl 2]
         sym.__aeabi_idiv ()      // sym.__aeabi_idiv(-1, 0x5)
         str r0, [r7, r6, lsl 2]
         r6 += 1
         
         goto loc_0xc043fef4;
    loc_0xc043fef4: // orphan
         r0 = r4

         goto loc_0xc043fe5c;
    loc_0xc043fe5c: // orphan
         r4 -= 1
         bne 0xc043fe1c           // likely

    loc_0xc043fe1c: // orphan
         r3 = 1
         r2 = var_ah_2            // "X"
         r1 = 0xf1
         r0 = r7
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0xf1, 0x17800a, 0x1)
         r0 = 0xa
         sym.msleep ()            // sym.msleep(0xa, 0xf1)
         r3 = 1
         r1 = 0xf1
         r0 = r7
         r2 = var_bh
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x17800b, 0x1)
         r2 = (byte) [var_bh]
         r3 = (byte) [var_ah_3]
         (a, b) = compare (r2, r3)
         je 0xc043fe68            // unlikely

         goto loc_0xc043fe64;
    loc_0xc043fe64: // orphan
         
    loc_0xc043fda8: // orphan
         // CODE XREF from sym.sitronix_ts_enable_raw @ 0xc043fe64(x)
         r8 = ~4

         goto loc_0xc043fd38;
    loc_0xc043fd38: // orphan
         r3 = 1
         r2 = var_ah              // "X"
         r1 = 0xf1
         r4 = 6
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x17800a, 0x1)
         r3 = (byte) [var_ah]
         bic r3, r3, 0x5c
         r3 |= 4
         [var_ah] = (byte) r3

    loc_0xc043fdc8: // orphan
         r0 = [r5 + 4]
         (a, b) = compare (r0, 0)
         je 0xc043fde0            // unlikely

    loc_0xc043fde0: // orphan
         r3 = 0
         [r5] = r3
         
         goto loc_0xc043fdd4;
    loc_0xc043fdd4: // orphan
         sym.kfree ()             // sym.kfree(0x0)
         r3 = 0
         [r5 + 4] = r3

         goto loc_0xc043fda0;
    loc_0xc043fda0: // orphan
         r4 -= 1
         bne 0xc043fd5c           // likely

    loc_0xc043fd5c: // orphan
         r3 = 1
         r2 = var_ah_2
         r1 = 0xf1
         r0 = r7
         sym.sitronix_ts_reg_write () // sym.sitronix_ts_reg_write(0x0, 0xf1, 0x17800a, 0x1)
         r0 = 0xa
         sym.msleep ()            // sym.msleep(0xa, 0xf1)
         r3 = 1
         r1 = 0xf1
         r0 = r7
         r2 = var_bh
         sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xf1, 0x17800b, 0x1)
         r2 = (byte) [var_bh]
         r8 = r0
         r3 = (byte) [var_ah_3]
         (a, b) = compare (r2, r3)
         je 0xc043fdc8            // unlikely

}

// ----- END sitronix_ts_enable_raw -----

// ----- BEGIN sitronix_ts_get_rawdata (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_rawdata (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_proc_strawdata_show @ 0xc044169c(x)
        // CALL XREF from sym.sitronix_proc_strawdata_test_read @ 0xc0441794(x)
        push (r4, r5, r6, lr)
        r4 = [0xc043ff74] // [0xc043ffe4:4]=0xc0a5d4dc
        r3 = [r4]
        (a, b) = compare (r3, 0)
        je 0xc043ffdc // likely
        goto loc_0xc043ff7c;
    loc_0xc043ffdc:
        r0 = ~0x46
        pop (r4, r5, r6, pc)
        goto loc_0xc043ff90;
         goto loc_0xc043ff90;
    loc_0xc043ff90:
        r3 = [r4]
        (a, b) = compare (r3, 2)
        je 0xc043ffa4 // unlikely
        return r0;
    loc_0xc043ffa4:
        r2 = (byte) [r6 + 0x25]
        r3 = (byte) [r6 + 0x24]
        smulbb r3, r3, r2
        r2 = r5
        add r3, r5, r3, lsl 2
        
    while (/* 0xc043ffb8 */) {
        r0 = [r4]
        pop (r4, r5, r6, pc)
    }
    loc_0xc043ffc0:
        r0 = [r4 + 4]
        r1 = r2 - r5
        r1 = [r0 + r1]
        r0 = [r2]
        r1 -= r0
        [r2] + 4 = r1
        goto loc_0xc043ffb8;
}

// ----- END sitronix_ts_get_rawdata -----

// ----- BEGIN sitronix_ts_set_rawdata_area (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_set_rawdata_area (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg_38h, int32_t arg_3ch, int32_t arg_40h, int32_t arg_44h, int32_t arg_48h) {
        push (r4, r5, lr)
        sp -= 0x2c
        r5 = [0xc043fff8] // [0xc0440168:4]=0xc0a04e08
        [var_bh] = (byte) r3 // arg4
        r3 = [arg_38h]
        [var_8h] = (byte) r2 // arg3
        r2 = [arg_3ch]
        [var_bh] = (byte) r3
        r3 = [arg_44h]
        r0 = [r5]
        [var_8h] = (byte) r2
        r2 = [arg_40h]
        [var_bh] = (byte) r3
        r3 = [arg_48h]
        [var_24h] = r0
        r0 = 6
        [var_7h] = (byte) r1 // arg2
        r1 = var_4h
        [var_4h] = (byte) r0
        r0 = 0xa
        [var_8h] = (byte) r2
        r2 = 0xb
        [var_4h] = (byte) r0
        r0 = 0
        [var_4h] = (byte) r0
        [var_2h] = (half) r0
        r0 = var_2h
        [var_bh] = (byte) r3
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x177fca, 0x177fcc, 0xb)
        r3 = (byte) [var_4h]
        r2 = var_28h
        r0 = var_4h
        r3 = r2 + r3
        r2 = (word) [var_2h]
        [r3 - 0x23] = (byte) r2
        sym.TDU_WriteIOCommand () // sym.TDU_WriteIOCommand(0x177fcc)
        (a, b) = compare (r0, 0)
        bne 0xc0440098 // likely
        goto loc_0xc0440080;
    while (/* 0xc0440098 */) {
        // CODE XREFS from sym.sitronix_ts_set_rawdata_area @ 0xc0440148(x), 0xc0440154(x)
        r0 = ~4
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        // CODE XREF from sym.sitronix_ts_set_rawdata_area @ 0xc044015c(x)
        r2 = [var_24h_2]
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0440160 // unlikely
    }
    loc_0xc04400a8:
        r0 = 0x14
        sym.msleep () // sym.msleep(0x14, 0x0)
        sym.TDU_GetH2DReady () // sym.TDU_GetH2DReady(0x14)
        (a, b) = compare (r0, 0)
        je 0xc044014c // unlikely
        goto loc_0xc04400bc;
    while (/* 0xc044014c */) {
        r2 = 0x20
        r1 = 0
        r0 = var_24h
        sym.memset () // void *memset(0x00000000, 0, -1)
        r2 = 3
        r3 = 6
        r1 = var_28h
        r0 = var_2h_2
        [var_28h] = (byte) r3
        r3 = 2
        [var_28h] = (byte) r3
        r3 = ~0x7f
        [var_28h] = (byte) r3
        r3 = 0
        [var_24h] = (half) r3
        sym.STChecksumCalculation () // sym.STChecksumCalculation(0x178006, 0x178008, 0x3)
        r3 = (byte) [var_28h]
        r2 = var_28h
        r0 = var_28h
        r3 = r2 + r3
        r2 = (word) [var_24h]
        [r3 - 0x23] = (byte) r2
        sym.TDU_WriteIOCommand () // sym.TDU_WriteIOCommand(0x178008)
        (a, b) = compare (r0, 0)
        je 0xc0440080 // unlikely
        sym.TDU_SetH2DReady ()
        (a, b) = compare (r0, 0)
        je 0xc0440080 // likely
        while (/* 0xc0440140 */) {
            r0 = 0x14
            sym.msleep () // sym.msleep(0x14, 0x0)
            sym.TDU_GetH2DReady () // sym.TDU_GetH2DReady(0x14)
            (a, b) = compare (r0, 0)
            bne 0xc0440158 // likely
        }
        goto 0xc0440080
    }
    loc_0xc0440154:
        goto 0xc0440080
            goto loc_0xc04400bc;
        goto loc_0xc0440120;
        return r0;
    loc_0xc0440158: // orphan
         r0 = 0
         
}

// ----- END sitronix_ts_set_rawdata_area -----

// ----- BEGIN sitronix_ts_exdiff_enable (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_exdiff_enable (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_mode_restore @ 0xc0440310(x)
        // CALL XREF from sym.sitronix_proc_stexdiff_write @ 0xc04438b0(x)
        push (r0, r1, r4, r5, r6, lr)
        r5 = r1       // arg2
        r6 = [0xc044017c] // [0xc0440278:4]=0xc0a04e08
        r2 = sp
        r1 = 0x130
        r4 = r0       // arg1
        r3 = [r6]
        [var_4h] = r3
        r3 = 1
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x130, 0x177fe8, 0x1)
        (a, b) = compare (r0, 0)
        blt 0xc0440228 // unlikely
        goto loc_0xc044019c;
    loc_0xc0440228:
        // CODE XREFS from sym.sitronix_ts_exdiff_enable @ 0xc0440250(x), 0xc044026c(x)
        r2 = [var_4h]
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc0440270 // unlikely
        goto loc_0xc0440238;
    loc_0xc0440270:
        sp += 8
        pop (r4, r5, r6, pc)
        goto loc_0xc04401cc;
        return r0;
    loc_0xc04401cc:
        r3 = 4
        r2 = sp       // r13
        r1 = 0x130
        r0 = r4
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0x130, 0x178000, 0x4)
        (a, b) = compare (r0, 0)
        blt 0xc0440228 // unlikely
        goto loc_0xc04401e8;
    loc_0xc04401e8:
        (a, b) = compare (r5, 0)
        r3 = (byte) [sp]
        je 0xc0440254 // likely
        goto loc_0xc04401f4;
    while (/* 0xc0440254 */) {
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        r0 = 0
        r3 = 0
        r0 = ~0x15
        [r4 + 0x2e0] = (byte) r3
        [r4 + 0x2e1] = (byte) r3
        [r4 + 0x2e4] = r3
        goto 0xc0440228
    }
    loc_0xc0440268:
        r0 = r5
        goto 0xc0440228
            goto loc_0xc04401f4;
    loc_0xc04401f4:
        (a, b) = compare (r3, 1)
        je 0xc044023c // likely
        goto loc_0xc04401fc;
        return r0;
    loc_0xc04401fc:
        r3 = (byte) [var_0h]
        (a, b) = compare (r3, 0)
        je 0xc044023c // unlikely
        goto loc_0xc0440208;
            goto loc_0xc0440208;
    loc_0xc0440208:
        r2 = 1
        [r4 + 0x2e0] = (byte) r2
        r2 = (byte) [var_0h]
        [r4 + 0x2e1] = (byte) r3
        r3 = (byte) [var_0h]
        r3 |= r2
        [r4 + 0x2e4] = r3
        return r0;
}

// ----- END sitronix_ts_exdiff_enable -----

// ----- BEGIN sitronix_mode_restore (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mode_restore (void) {
        // CALL XREF from sym.sitronix_fb_notifier_callback @ 0xc043c944(x)
        // CALL XREF from sym.sitronix_ts_resume_work @ 0xc043ce00(x)
        // CALL XREF from sym.sitronix_ts_mt_reset_process @ 0xc04406a0(x)
        r3 = [0xc0440284] // [0xc0440330:4]=0xc0a04e08
        push (r0, r1, r2, r4, r5, r6, r7, lr)
        r4 = 2
        r5 = [0xc0440290] // [0xc0440334:4]=0xc0a5d4d0
        r6 = r3
        r2 = [r3]
        r7 = r5
        [var_4h] = r2
        
    loc_0xc044029c:
        r3 = [r5]
        r1 = var_3h
        r0 = r4
        r3 += r4
        r2 = (byte) [r3 + 0x192]
        r3 = (byte) [r3 + 0x1a6]
        (a, b) = compare (r2, 0)
        movne r2, 0x80
        moveq r2, 0
        r3 = r2 | r3
        r2 = 1
        [var_2h] = (byte) r3
        sym.TDU_FWControlRead () // sym.TDU_FWControlRead(0x0, 0x178003, 0x1)
        r2 = (byte) [var_3h_2]
        r3 = (byte) [var_2h_2]
        (a, b) = compare (r2, r3)
        je 0xc04402f0 // likely
        goto loc_0xc04402e0;
        return r0;
    loc_0xc04402e0:
        r2 = 1
        r1 = var_2h
        r0 = r4
        sym.TDU_FWControlWrite () // sym.TDU_FWControlWrite(0x0, 0x178002, 0x1)
        
    while (/* 0xc04402f0 */) {
    }
    loc_0xc04402fc:
        r0 = [r7]
        r3 = (byte) [r0 + 0x2e0]
        (a, b) = compare (r3, 0)
        je 0xc0440314 // unlikely
        goto loc_0xc044030c;
    loc_0xc0440314:
        r2 = [var_4h]
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc0440328 // unlikely
        goto loc_0xc0440324;
    loc_0xc0440328:
        sp += 0xc
        pop (r4, r5, r6, r7, pc)
    loc_0xc044030c: // orphan
         r1 = 1
         sym.sitronix_ts_exdiff_enable () // sym.sitronix_ts_exdiff_enable(0x0, 0x1)

         goto loc_0xc04402e0;
}

// ----- END sitronix_mode_restore -----

// ----- BEGIN sitronix_ts_get_exdiff (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_get_exdiff (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d12c(x)
        push (r0, r1, r4, r5, r6, r7, r8, sb, sl, lr)
        r2 = r1       // arg2
        r5 = [0xc0440348] // [0xc04403f8:4]=0xc0a04e08
        r4 = r1       // arg2
        r1 = r0 + 0x2e4 // arg1
        r3 = [r5]
        r1 = (word) [r1]
        [var_4h] = r3
        r3 = 0
        [var_2h] = (half) r3
        r3 = 0x65     // 'e'
        sym.sitronix_ts_reg_read () // sym.sitronix_ts_reg_read(0x0, 0xffff, 0x0, 0x65)
        r6 = r0 - 0
        blt 0xc04403d8 // unlikely
        goto loc_0xc0440370;
    loc_0xc04403d8:
        r2 = [var_4h]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc04403f0 // unlikely
        goto loc_0xc04403ec;
    loc_0xc04403f0:
        sp += 8
        pop (r4, r5, r6, r7, r8, sb, sl, pc)
        goto loc_0xc0440394;
        return r0;
    loc_0xc0440394:
        r8 = [0xc044039c] // [0xc04403fc:4]=0xc08027de "%4d," // "%4d,"
        r7 = r4 + 0x62
        sb = [0xc04403a4] // [0xc0440400:4]=0xc08106b1 "." // "\n"
        
    loc_0xc04403a0:
        sl = r4 + 0xe
        return r0;
    loc_0xc0440370: // orphan
         r2 = 0x64                // 'd'
         r1 = r4
         r0 = var_2h
         sym.STChecksumCalculation () // sym.STChecksumCalculation(0x178002, 0x0, 0x64)
         r2 = (byte) [r4 + 0x64]
         r3 = (byte) [var_2h]
         (a, b) = compare (r2, r3)
         mvnne r6, 4
         bne 0xc04403d8           // unlikely

    loc_0xc04403a4: // orphan
         r3 = (byte) [r4 + 2]
         r0 = r8
         r1 = (byte) [r4 + 3]
         r4 += 2
         r1 |= r3
         r1 = (short) r1
         sym.printk ()
         (a, b) = compare (sl, r4)
         bne 0xc04403a4           // likely

         goto loc_0xc04403c8;
    loc_0xc04403c8: // orphan
         r0 = sb
         sym.printk ()
         (a, b) = compare (r4, r7)
         bne 0xc04403a0           // unlikely

}

// ----- END sitronix_ts_get_exdiff -----

// ----- BEGIN sitronix_ts_addrmode_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_addrmode_write_1 (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS: CALL 0xc0440488  CALL 0xc04404b4  CALL 0xc04404f4
        // XREFS: CALL 0xc04405a4  CALL 0xc04405d8  CALL 0xc0440604
        [sp - 4]! = lr
        ip = r1       // arg2
        r3 = [r0 + 0x10] // arg1
        r1 = r2       // arg3
        r0 = ip
        lr = [r3 + 0x2c]
        r2 = [r3 + 0x14]
        r3 = lr
        pop (lr)      // r13
        bx r3
}

// ----- END sitronix_ts_addrmode_write -----

// ----- BEGIN sitronix_ts_mt_reset_process (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_mt_reset_process (void) {
        // XREFS: CALL 0xc0440728  CALL 0xc0440830  CALL 0xc044086c
        // XREFS: CALL 0xc0440e20  CALL 0xc0441230  CALL 0xc04498ac
        push (r4, lr)
        r4 = [0xc0440644] // [0xc04406b4:4]=0xc0a5d4d0
        r0 = [r4]
        sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(0x0)
        r0 = [r4]
        r3 = (byte) [r0 + 0x6c]
        (a, b) = compare (r3, 0)
        je 0xc0440694 // unlikely
        goto loc_0xc0440658;
    loc_0xc0440694:
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        sym.sitronix_mode_restore ()
        r0 = [r4]
        r0 += 0x70
        pop (r4, lr)
        goto sym.mutex_unlock // sym.mutex_unlock(0x6f)
        return r0;
}

// ----- END sitronix_ts_mt_reset_process -----

// ----- BEGIN sitronix_ts_monitor_thread_v3 (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_monitor_thread_v3 (int32_t arg1) {
        // ICOD XREF from sym.sitronix_ts_probe @ 0xc043cc9c(x)
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x14
        r7 = [0xc04406c8] // [0xc044088c:4]=0xc0a04e08
        r6 = 0x7d0
        r5 = [0xc04406d0] // [0xc0440890:4]=0xc0a5d4d0
        r4 = [0xc04406d4] // [0xc0440894:4]=0xc0a5d4e4
        r3 = [r7]
        [var_ch] = r3
        r3 = 0
        [sp] = r3
        [var_4h] = r3
        [var_8h] = r3
        r3 = [r5]
        r0 = [r3 + 0x100]
        sym.msleep () // sym.msleep(-1, 0x0)
        
    loc_0xc04406f4:
        // CODE XREF from sym.sitronix_ts_monitor_thread_v3 @ 0xc044073c(x)
        sym.kthread_should_stop ()
        r8 = r0 - 0
        je 0xc0440718 // likely
        goto loc_0xc0440700;
        return r0;
    loc_0xc0440700:
        r2 = [var_ch_2]
        r0 = 0
        r3 = [r7]
        (a, b) = compare (r2, r3)
        je 0xc0440884 // unlikely
        goto loc_0xc0440714;
    loc_0xc0440884:
        sp += 0x14
        pop (r4, r5, r6, r7, r8, sb, pc)
        return r0;
    loc_0xc0440740: // orphan
         r2 = (byte) [r0 + 0xfd]
         (a, b) = compare (r2, 0)
         bne 0xc0440734           // likely

    loc_0xc0440734: // orphan
         // CODE XREFS from sym.sitronix_ts_monitor_thread_v3 @ 0xc0440844(x), 0xc0440880(x)
         r0 = r6
         sym.msleep ()            // sym.msleep(0x0, 0x0)
         
    loc_0xc044074c: // orphan
         r2 = (word) [r0 + 0x90]
         (a, b) = compare (r2, 0)
         bne 0xc0440734           // likely

         goto loc_0xc0440758;
    loc_0xc0440758: // orphan
         r8 = [r4]
         (a, b) = compare (r8, 0)
         strne r2, [r4]
         bne 0xc0440734           // likely

         goto loc_0xc0440768;
    loc_0xc0440768: // orphan
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r3 = [r5]
         r2 = 0xc
         r0 = r8
         r3 = [r3 + 0x10]
         sb = [r3 + 0x18]
         r3 = [r3 + 0x14]
         r1 = sp                  // r13
         sb ()                    // 0xffffffff(0x0, 0x178000, 0xc, -1)
         r8 = r0
         r0 = [r5]
         r0 += 0x70
         sym.mutex_unlock ()      // sym.mutex_unlock(0x6f)
         (a, b) = compare (r8, 0)
         blt 0xc0440858           // unlikely

    loc_0xc0440858: // orphan
         r3 = [r4 + 0xc]
         r3 += 1
         [r4 + 0xc] = r3
         (a, b) = compare (r3, 1)
         ble 0xc0440734           // likely

         goto loc_0xc044086c;
    loc_0xc044086c: // orphan
         sym.sitronix_ts_mt_reset_process ()
         r6 = 0x7d0
         r3 = 0
         [r4 + 0xc] = r3
         [r4 + 8] = r3
         
         goto loc_0xc04407a8;
    loc_0xc04407a8: // orphan
         r3 = (byte) [var_1h]
         r3 &= 0xf
         (a, b) = compare (r3, 6)
         je 0xc0440858            // unlikely

         goto loc_0xc04407b8;
    loc_0xc04407b8: // orphan
         r2 = (byte) [r4 + 4]
         r3 = (byte) [var_ah]
         (a, b) = compare (r2, r3)
         bne 0xc0440848           // likely

    loc_0xc0440848: // orphan
         r3 = 0
         r6 = 0x7d0
         [r4 + 8] = r3
         
    loc_0xc044080c: // orphan
         // CODE XREF from sym.sitronix_ts_monitor_thread_v3 @ 0xc0440854(x)
         r3 = (byte) [var_ah]
         [r4 + 4] = (byte) r3
         r3 = (byte) [var_ah]
         [r4 + 5] = (byte) r3
         r3 = [r4 + 8]
         (a, b) = compare (r3, 2)
         ble 0xc044083c           // likely

    loc_0xc044083c: // orphan
         r3 = 0
         [r4 + 0xc] = r3
         
         goto loc_0xc0440828;
    loc_0xc0440828: // orphan
         r6 = 0
         [r4 + 8] = r6
         sym.sitronix_ts_mt_reset_process ()
         [r4 + 8] = r6
         r6 = 0x7d0

         goto loc_0xc04407c8;
    loc_0xc04407c8: // orphan
         r2 = (byte) [r4 + 5]
         r3 = (byte) [var_ah]
         (a, b) = compare (r2, r3)
         bne 0xc0440848           // likely

         goto loc_0xc04407d8;
    loc_0xc04407d8: // orphan
         r0 = [r5]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x6f)
         sym.sitroinx_ts_check_display_off () // sym.sitroinx_ts_check_display_off(0x6f)
         r3 = [r4 + 8]
         r3 += 1
         [r4 + 8] = r3
         (a, b) = compare (r0, 1)
         r0 = [r5]
         r0 += 0x70
         moveq r6, 0x7d0
         movne r6, 0x1f4
         sym.mutex_unlock ()      // sym.mutex_unlock(0x6f)

         goto loc_0xc0440728;
    loc_0xc0440728: // orphan
         sym.sitronix_ts_mt_reset_process ()
         r3 = [r5]
         [r3 + 0xfc] = (byte) r8

         goto loc_0xc0440700;
    loc_0xc0440714: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
}

// ----- END sitronix_ts_monitor_thread_v3 -----

// ----- BEGIN sitronix_mt_pause_one (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_pause_one (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_irq_handler @ 0xc043d04c(x)
        // CALL XREF from sym.sitronix_mt_resume @ 0xc044090c(x)
        // CALL XREF from sym.sitronix_mt_start @ 0xc044098c(x)
        r3 = [0xc04408a0] // [0xc04408b8:4]=0xc0a5d4d0
        r3 = [r3]
        r3 = (byte) [r3 + 0xfe]
        (a, b) = compare (r3, 0)
        ldrne r3, [pc, 0xc] // [0xc04408bc:4]=0xc0a5d4e4
        movne r2, 1
        strne r2, [r3] // arg3
        bx lr
}

// ----- END sitronix_mt_pause_one -----

// ----- BEGIN sitronix_mt_pause (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_pause (void) {
        // CALL XREF from sym.sitronix_stmt_store @ 0xc0440ee0(x)
        // CALL XREF from sym.st_dev_open @ 0xc0440ef0(x)
        // CALL XREF from sym.st_proc_stmt_write @ 0xc0443488(x)
        // CALL XREFS from sym.sitronix_proc_strawdata_test_write @ 0xc0444298(x), 0xc04442d0(x)
        r3 = [0xc04408c8] // [0xc04408d4:4]=0xc0a5d4d0
        r2 = 1
        r3 = [r3]
        [r3 + 0x90] = (byte) r2
        bx lr
}

// ----- END sitronix_mt_pause -----

// ----- BEGIN sitronix_mt_restore (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_restore (void) {
        // CALL XREF from sym.st_dev_release @ 0xc0440eac(x)
        // CALL XREF from sym.sitronix_stmt_store @ 0xc0440ed0(x)
        // CALL XREF from sym.st_proc_stmt_write @ 0xc0443470(x)
        // CALL XREF from sym.sitronix_proc_strawdata_test_write @ 0xc044424c(x)
        r3 = [0xc04408e0] // [0xc04408ec:4]=0xc0a5d4d0
        r2 = 0
        r3 = [r3]
        [r3 + 0x90] = (byte) r2
        bx lr
}

// ----- END sitronix_mt_restore -----

// ----- BEGIN sitronix_mt_suspend (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_suspend (void) {
        // CALL XREF from sym.sitronix_fb_notifier_callback @ 0xc043c8c0(x)
        r3 = [0xc04408f8] // [0xc0440904:4]=0xc0a5d4d0
        r2 = 1
        r3 = [r3]
        [r3 + 0xfd] = (byte) r2
        bx lr
}

// ----- END sitronix_mt_suspend -----

// ----- BEGIN sitronix_mt_resume (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_resume (int32_t arg1) {
        push (r4, lr)
        sym.sitronix_mt_pause_one () // sym.sitronix_mt_pause_one(0x0)
        r2 = 0
        r3 = [0xc044091c] // [0xc0440924:4]=0xc0a5d4d0
        r3 = [r3]
        [r3 + 0xfd] = (byte) r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_mt_resume -----

// ----- BEGIN sitronix_mt_stop (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_stop (void) {
        // CALL XREF from sym.sitronix_ts_remove @ 0xc043c664(x)
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cb14(x)
        push (r4, lr)
        r4 = [0xc0440934] // [0xc0440968:4]=0xc0a5d4d0
        r3 = [r4]
        (a, b) = compare (r3, 0)
        popeq (r4, pc) // r13
        goto loc_0xc044093c;
        break;
    loc_0xc0440948: // orphan
         r0 = [r3 + 0x104]
         (a, b) = compare (r0, 0)
         popeq (r4, pc)

    loc_0xc0440954: // orphan
         sym.kthread_stop ()      // sym.kthread_stop(0x0)
         r3 = [r4]
         r2 = 0
         [r3 + 0x104] = r2
         pop (r4, pc)

}

// ----- END sitronix_mt_stop -----

// ----- BEGIN sitronix_mt_start (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_mt_start (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cca4(x)
        push (r4, r5, r6, lr)
        r4 = [0xc0440978] // [0xc04409f4:4]=0xc0a5d4d0
        r3 = [r4]
        (a, b) = compare (r3, 0)
        popeq (r4, r5, r6, pc) // r13
        goto loc_0xc0440980;
        break;
    loc_0xc044098c: // orphan
         sym.sitronix_mt_pause_one () // sym.sitronix_mt_pause_one(0x0)
         r3 = [0xc0440998]        // [0xc04409f8:4]=0xc0a5d4e4
         r5 = [r4]
         r2 = 0
         [r3 + 8] = r2
         [r3 + 0xc] = r2
         r3 = [r5 + 0x104]
         (a, b) = compare (r3, r2)
         [r5 + 0x100] = r0
         bne 0xc04409dc           // likely

    loc_0xc04409dc: // orphan
         r3 = [r4]
         r2 = [r3 + 0x104]
         if (r2 != 0x1000)
         movhi r2, 0
         strhi r2, [r3, 0x104]
         pop (r4, r5, r6, pc)

    loc_0xc04409b4: // orphan
         r3 = [0xc04409bc]        // [0xc04409fc:4]=0xc08027e3 "Sitronix Monitor Thread" // "Sitronix Monitor Thread"
         r2 = ~0
         r1 = r5
         r0 = [r5 + 0x108]
         sym.kthread_create_on_node () // sym.kthread_create_on_node(-1, 0x0, -1, 0xc08027e3, 0x0, 0x0)
         if (r0 != 0x1000)
         r6 = r0
         bhi 0xc04409d8           // unlikely

    loc_0xc04409d8: // orphan
         [r5 + 0x104] = r6

         goto loc_0xc04409d4;
    loc_0xc04409d4: // orphan
         sym.wake_up_process ()

}

// ----- END sitronix_mt_start -----

// ----- BEGIN sitronix_ts_reg_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reg_read_1 (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        // CALL XREF from sym.sitronix_stcmdio_store @ 0xc04422a4(x)
        // CALL XREF from sym.st_proc_stcmdio_write @ 0xc0442ec0(x)
        // CALL XREFS from sym.st_dev_function @ 0xc04445c4(x), 0xc0444850(x)
        [sp - 4]! = lr
        ip = r1       // arg2
        r1 = r2       // arg3
        r2 = r3       // arg4
        r3 = [r0 + 0x10] // arg1
        r0 = ip
        lr = [r3 + 0x18]
        r3 = [r3 + 0x14]
        ip = lr
        pop (lr)      // r13
        bx ip
}

// ----- END sitronix_ts_reg_read -----

// ----- BEGIN sitronix_stproximity_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stproximity_show (int32_t arg1) {
        r3 = [0xc0440ae4] // [0xc0440b08:4]=0xc0a5d4d0
        r0 = r2       // arg3
        r2 = [0xc0440aec] // [0xc0440b0c:4]=0xc07e17a6 "false" // "false"
        r3 = [r3]
        r1 = (byte) [r3 + 0x8b]
        r3 = [0xc0440af8] // [0xc0440b10:4]=0xc07e17c1 "true" // "true"
        (a, b) = compare (r1, 0)
        r1 = 0xc8
        moveq r3, r2
        r2 = [0xc0440b08] // [0xc0440b14:4]=0xc08027fb "proximity_enabled = %s." // "proximity_enabled = %s\n"
        goto sym.snprintf // int snprintf(0, -1, "proximity_enabled = %s\n", "true")
}

// ----- END sitronix_stproximity_show -----

// ----- BEGIN sitronix_stmodeswitch_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stmodeswitch_show (int32_t arg1) {
        push (r0, r1, r2, r4, r5, r6, r7, r8, sb, lr)
        sb = r2       // arg3
        r6 = [0xc0440b28] // [0xc0440bbc:4]=0xc0a5d4d0
        r5 = 0
        r7 = [0xc0440b30] // [0xc0440bc0:4]=0xc07edaee "on" // "on"
        r4 = 1
        r8 = [0xc0440b38] // [0xc0440bc4:4]=0xc07e2705 "off" // "off"
        
    loc_0xc0440b34:
        (a, b) = compare (r4, 7)
        r0 = sb + r5
        bne 0xc0440b8c // likely
        goto loc_0xc0440b40;
        return r0;
    loc_0xc0440b40:
        r2 = [r6]
        r1 = 0x64     // 'd'
        r3 = (byte) [r2 + 0x199]
        r2 = (byte) [r2 + 0x1ad]
        (a, b) = compare (r3, 0)
        [var_4h] = r2
        movne r3, r7
        moveq r3, r8
        r2 = [0xc0440b68] // [0xc0440bc8:4]=0xc0802813 "modeID = %d , flag = %s , value = %x." // "modeID = %d , flag = %s , value = %x\n"
        [sp] = r3
        r3 = r4
        sym.snprintf () // int snprintf(0, -1, "modeID = %d , flag = %s , value = %x\n", 0, "", -1)
        
    while (/* 0xc0440b70 */) {
    }
    loc_0xc0440b80:
        r0 = r5
        sp += 0xc
        pop (r4, r5, r6, r7, r8, sb, pc)
}

// ----- END sitronix_stmodeswitch_show -----

// ----- BEGIN sitronix_stselftest_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stselftest_show (int32_t arg1) {
        r3 = [0xc0440bd8] // [0xc0440bec:4]=0xc0a5d4d0
        r0 = r2       // arg3
        r1 = 0xc8
        r2 = [0xc0440be4] // [0xc0440bf0:4]=0xc0802852 "Sitronix Self Test Result = %d ( 0 == success, >0 failed sensor number, < 0 err) ." // "Sitronix Self Test Result = %d ( 0 == success, >0 failed sensor"
        r3 = [r3]
        r3 = [r3 + 0x2ac]
        goto sym.snprintf // int snprintf(0, -1, "Sitronix Self Test Result = ", 0xffffffff)
}

// ----- END sitronix_stselftest_show -----

// ----- BEGIN sitronix_stupgrade_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stupgrade_show (int32_t arg1) {
        r3 = [0xc0440bfc] // [0xc0440c34:4]=0xc0a5d4d0
        push (r0, r1, r2, lr)
        r0 = r2       // arg3
        r2 = [r3]
        r3 = [0xc0440c0c] // [0xc0440c38:4]=0xc07d45c7 "success" // "success"
        r2 += 0x98
        r1 = [r2 - 4]
        [sp] = r2
        r2 = [0xc0440c1c] // [0xc0440c3c:4]=0xc0802ba0 "fail" // "fail"
        (a, b) = compare (r1, 0)
        r1 = 0x3e8
        movlt r3, r2  // "fail"
        r2 = [0xc0440c2c] // [0xc0440c40:4]=0xc08028a5 "upgrade result = %s.message: %s." // "upgrade result = %s\nmessage: %s\n"
        sym.snprintf () // int snprintf(0, -1, "upgrade result = %s\nmessage: %s\n", "fail", NULL)
        sp += 0xc     // r13
        pop (pc)
}

// ----- END sitronix_stupgrade_show -----

// ----- BEGIN sitronix_stmt_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stmt_show (int32_t arg1) {
        r3 = [0xc0440c4c] // [0xc0440c70:4]=0xc0a5d4d0
        r0 = r2       // arg3
        r2 = [0xc0440c54] // [0xc0440c74:4]=0xc07e17a6 "false" // "false"
        r3 = [r3]
        r1 = (byte) [r3 + 0x90]
        r3 = [0xc0440c60] // [0xc0440c78:4]=0xc07e17c1 "true" // "true"
        (a, b) = compare (r1, 0)
        r1 = 0xc8
        moveq r3, r2
        r2 = [0xc0440c70] // [0xc0440c7c:4]=0xc08028c6 "is_pause_mt = %s." // "is_pause_mt = %s\n"
        goto sym.snprintf // int snprintf(0, -1, "is_pause_mt = %s\n", "true")
}

// ----- END sitronix_stmt_show -----

// ----- BEGIN sitronix_strequestfw_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_strequestfw_show (int32_t arg1) {
        push (r4, lr)
        r0 = r2       // arg3
        r1 = [0xc0440c90] // [0xc0440c98:4]=0xc08028d8 "sitronix_strequestfw_show." // "sitronix_strequestfw_show\n"
        sym.strcpy () // char *strcpy(0, "sitronix_strequestfw_sho")
        r0 = 0x1a
        pop (r4, pc)
}

// ----- END sitronix_strequestfw_show -----

// ----- BEGIN sitronix_stmodeswitch_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stmodeswitch_store (int32_t arg1, int32_t arg2) {
        push (r0, r1, r2, r3, r4, r5, r6, r7, r8, lr)
        r8 = r3       // arg4
        r6 = [0xc0440cac] // [0xc0440d9c:4]=0xc0a04e08
        r7 = r2       // arg3
        r1 = r7
        r2 = 3
        r0 = var_9h
        r4 = 0
        r3 = [r6]
        [var_9h] = (half) r4
        [var_9h] = (byte) r4
        [var_ch] = r3
        sym.strlcpy () // char *strlcpy("", 0, -1)
        r1 = 0x10
        r2 = var_4h
        r0 = var_9h_2
        sym._kstrtoul () // sym._kstrtoul(0x177fe5, 0x10)
        r1 = (byte) [r7 + 3]
        r7 = [0xc0440cec] // [0xc0440da0:4]=0xc0a5d4d0
        r5 = [var_4h_2]
        (a, b) = compare (r5, 7)
        bne 0xc0440d70 // likely
        goto loc_0xc0440cf4;
    loc_0xc0440d70:
        r4 = r1 - 0x30
        r0 = [r7]
        movne r4, 1
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r1 = r4
        r0 = r5
        sym.sitronix_mode_switch ()
        goto 0xc0440d44
        
    loc_0xc0440d44:
        // CODE XREF from sym.sitronix_stmodeswitch_store @ 0xc0440d90(x)
        r0 = [r7]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        r0 = r8
        r2 = [var_ch]
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc0440d94 // unlikely
        goto loc_0xc0440d64;
        goto loc_0xc0440cfc;
        return r0;
    loc_0xc0440cfc:
        (a, b) = compare (r1, 0x31) // '1'
        je 0xc0440d20 // unlikely
        goto loc_0xc0440d04;
    loc_0xc0440d20:
        r4 = 1
        
    loc_0xc0440d24:
        // CODE XREFS from sym.sitronix_stmodeswitch_store @ 0xc0440d1c(x), 0xc0440d6c(x)
        r5 = 1
        goto loc_0xc0440d0c;
        return r0;
    loc_0xc0440d0c:
        (a, b) = compare (r1, 0x33) // '3'
        movne r5, r4
        bne 0xc0440d28 // likely
        goto loc_0xc0440d18;
    loc_0xc0440d28:
        r0 = [r7]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r2 = r4
        r1 = r5
        r0 = 7
        sym.sitronix_mode_switch_value () // sym.sitronix_mode_switch_value(0x7, 0x0, 0x0, 0x0, 0x0)
            goto loc_0xc0440d18;
    loc_0xc0440d18:
        r4 = 3
        goto 0xc0440d24
    loc_0xc0440d64: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0440cf4: // orphan
         (a, b) = compare (r1, 0x30) // '0'
         je 0xc0440d24            // unlikely

    loc_0xc0440d04: // orphan
         (a, b) = compare (r1, 0x32) // '2'
         je 0xc0440d68            // unlikely

    loc_0xc0440d68: // orphan
         r4 = 2
         
         goto loc_0xc0440d0c;
}

// ----- END sitronix_stmodeswitch_store -----

// ----- BEGIN sitronix_stswu_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stswu_show (int32_t arg1) {
        r3 = [0xc0440dac] // [0xc0440dd4:4]=0xc0a5d4d0
        r1 = 0xb0
        push (r4, lr)
        r4 = r2       // arg3
        r3 = [r3]
        r0 = [r3 + 8]
        sym.sitronix_ts_report_swu () // sym.sitronix_ts_report_swu(-1, 0xb0)
        r1 = [0xc0440dc8] // [0xc0440dd8:4]=0xc08028f3 "swu ok" // "swu ok"
        r0 = r4
        sym.strcpy () // char *strcpy(0, "swu ok")
        r0 = 6
        pop (r4, pc)
}

// ----- END sitronix_stswu_show -----

// ----- BEGIN sitronix_stselftest_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stselftest_store (int32_t arg1) {
        push (r4, r5, r6, r7, r8, lr)
        r1 = 0
        r4 = [0xc0440dec] // [0xc0440e40:4]=0xc0a5d4d0
        r6 = r3       // arg4
        r5 = 1
        r0 = [r4]
        sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(0x0, 0x0)
        r0 = [r4]
        r0 += 0x70
        [r0 + 0x21] = (byte) r5
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r7 = [r4]
        sym.st_self_test () // sym.st_self_test(0x70, 0x0, 0x0, 0x0)
        [r7 + 0x2ac] = r0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        sym.sitronix_ts_mt_reset_process ()
        r0 = [r4]
        r3 = 0
        r1 = r5
        [r0 + 0x91] = (byte) r3
        sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(0x0, 0x1)
        r0 = r6
        pop (r4, r5, r6, r7, r8, pc) // r13
}

// ----- END sitronix_stselftest_store -----

// ----- BEGIN sitronix_stupgrade_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stupgrade_store (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, lr)
        r5 = r3       // arg4
        r3 = (byte) [r2] // arg3
        r4 = [0xc0440e58] // [0xc0440ea4:4]=0xc0a5d4d0
        (a, b) = compare (r3, 0x31) // '1'
        ldreq r3, [r4]
        moveq r2, 1
        r0 = [r4]
        strbeq r2, [r3, 0x2de] // arg3
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r6 = [r4]
        sym.sitronix_do_upgrade ()
        [r6 + 0x94] = r0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        r2 = [r4]
        r3 = 0
        r0 = [r2 + 0x94]
        [r2 + 0x2de] = (byte) r3
        (a, b) = compare (r0, r3)
        movge r0, r5
        pop (r4, r5, r6, pc) // r13
}

// ----- END sitronix_stupgrade_store -----

// ----- BEGIN sitronix_stmt_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stmt_store (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, lr)
        r5 = r3       // arg4
        r3 = (byte) [r2] // arg3
        r4 = r2       // arg3
        (a, b) = compare (r3, 0x31) // '1'
        bne 0xc0440ed4 // likely
        goto loc_0xc0440ed0;
    loc_0xc0440ed4:
        r3 = (byte) [r4]
        (a, b) = compare (r3, 0x30) // '0'
        bne 0xc0440ee4 // likely
        goto loc_0xc0440ee0;
    loc_0xc0440ee4:
        r0 = r5
        pop (r4, r5, r6, pc)
        return r0;
    loc_0xc0440ed0: // orphan
         sym.sitronix_mt_restore ()

}

// ----- END sitronix_stmt_store -----

// ----- BEGIN sitronix_icinfo_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_icinfo_show (int32_t arg1, int32_t arg_38h) {
        push (r4, r5, lr)
        sp -= 0x44
        r4 = [0xc0440f0c] // [0xc0440fc4:4]=0xc0a5d4d0
        r5 = r2       // arg3
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r0 = [r4]
        sym.sitronix_ts_get_device_info () // sym.sitronix_ts_get_device_info(0x0)
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        r2 = [r4]
        r0 = r5
        r1 = (byte) [r2 + 0x28]
        r3 = (byte) [r2 + 0x14]
        [arg_38h] = r1
        r1 = (byte) [r2 + 0x1e]
        [var_34h] = r1
        r1 = (byte) [r2 + 0x25]
        [var_30h] = r1
        r1 = (byte) [r2 + 0x24]
        [var_2ch] = r1
        r1 = (word) [r2 + 0x22]
        [var_28h] = r1
        r1 = (word) [r2 + 0x20]
        [var_24h] = r1
        r1 = (byte) [r2 + 0x1d]
        [var_20h] = r1
        r1 = (byte) [r2 + 0x1c]
        [var_1ch] = r1
        r1 = (byte) [r2 + 0x1b]
        [var_18h] = r1
        r1 = (byte) [r2 + 0x1a]
        [var_14h] = r1
        r1 = (byte) [r2 + 0x19]
        [var_10h] = r1
        r1 = (byte) [r2 + 0x18]
        [var_ch] = r1
        r1 = (byte) [r2 + 0x17]
        [var_8h] = r1
        r1 = (byte) [r2 + 0x16]
        [var_4h] = r1
        r1 = 0x3e8
        r2 = (byte) [r2 + 0x15]
        [sp] = r2
        r2 = [0xc0440fbc] // [0xc0440fc8:4]=0xc08028fa "Sitronix touch.Chip ID = %02X.FW Verison = %02X.FW Revision = %02X %02X %02X %02X.Customer Info = %02X %02X %02X %02X.Resolution = %d x %d.Channels = %d x %d.Max touches = %d.Misc. Info = 0x%X." // "Sitronix touch\nChip ID = %02X\nFW Verison = %02X\nFW Revision = %"
        sym.snprintf () // int snprintf(0, -1, "Sitronix touch\nChip ID = %02X\nFW Verison = %02X\nFW Revision = %02X %02X %02X %02X\nCustomer Info = %02X %02X %02X %02X\nResolution = %d x %d\nChannels = %d x %d\nMax touches = %d\nMisc. Info = 0x%X\n", 0xff, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1)
        sp += 0x44
        pop (r4, r5, pc)
}

// ----- END sitronix_icinfo_show -----

// ----- BEGIN sitronix_create_proc (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_create_proc (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cc6c(x)
        push (r4, r5, r6, r7, r8, lr)
        r1 = 0
        r0 = [0xc044157c] // [0xc04415d8:4]=0xc0802a09 "sitronix" // "sitronix"
        r6 = 0
        sym.proc_mkdir () // sym.proc_mkdir(0xc0802a09)
        r4 = [0xc0441588] // [0xc04415dc:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
        r3 = [0xc044158c] // [0xc04415e0:4]=0xc0a5d4f8
        r8 = 1
        r7 = r4 + 0x398
        r5 = r3
        [r3] = r0
        
    loc_0xc0441598:
        // CODE XREF from sym.sitronix_create_proc @ 0xc04415d4(x)
        (a, b) = compare (r4, r7)
        bne 0xc04415a8 // unlikely
        return r0;
        return r0;
    loc_0xc04415a0:
        r0 = r6
        pop (r4, r5, r6, r7, r8, pc)
}

// ----- END sitronix_create_proc -----

// ----- BEGIN sitronix_remove_proc (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_remove_proc (void) {
        // CALL XREF from sym.sitronix_ts_remove @ 0xc043c668(x)
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043caf0(x)
        push (r4, r5, r6, lr)
        r4 = 0
        r5 = [0xc04415f4] // [0xc044163c:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
        r6 = [0xc04415f8] // [0xc0441640:4]=0xc0a5d4f8 // (pstr 0xc0802a09) "sitronix"
        
    loc_0xc04415f4:
        r3 = r5 + r4
        r3 = [r3 + 4]
        (a, b) = compare (r3, 0)
        je 0xc0441610 // unlikely
        goto loc_0xc0441604;
        return r0;
    loc_0xc0441604:
        r1 = [r6]
        r0 = [r4 + r5]
        sym.remove_proc_entry () // sym.remove_proc_entry(-1, -1, 0x0)
        
    while (/* 0xc0441610 */) {
    }
    loc_0xc044161c:
        r3 = [0xc0441624] // [0xc0441640:4]=0xc0a5d4f8 // (pstr 0xc0802a09) "sitronix"
        r3 = [r3]     // "sitronix"
        (a, b) = compare (r3, 0)
        popeq (r4, r5, r6, pc)
        goto loc_0xc044162c;
        goto loc_0xc0441610;
}

// ----- END sitronix_remove_proc -----

// ----- BEGIN sitronix_proc_strawdata_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_strawdata_show (int32_t arg1) {
        // ICOD XREF from sym.st_proc_strawdata_open @ 0xc0441510(x)
        push (r4, r5, r6, r7, r8, sb, sl, lr)
        r8 = r0       // arg1
        r4 = [0xc044166c] // [0xc0441744:4]=0xc0a5d4d0
        r1 = 0xcc0
        r3 = [r4]
        r0 = (byte) [r3 + 0x24]
        r3 = (byte) [r3 + 0x25]
        smulbb r0, r0, r3
        r0 = r0 << 2
        sym.__kmalloc () // sym.__kmalloc(0x3fc, 0xcc0)
        r6 = r0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = r6
        r0 = [r4]
        sym.sitronix_ts_get_rawdata () // sym.sitronix_ts_get_rawdata(0x0, 0x3fc)
        r5 = r0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        (a, b) = compare (r5, 0)
        blt 0xc04416ec // unlikely
        goto loc_0xc04416b8;
    loc_0xc04416ec:
        (a, b) = compare (r6, 0)
        je 0xc04416fc // likely
        goto loc_0xc04416f4;
    loc_0xc04416fc:
        r0 = r5
        pop (r4, r5, r6, r7, r8, sb, sl, pc)
        return r0;
    loc_0xc04416b8: // orphan
         (a, b) = compare (r5, 1)
         r0 = r8
         sb = [0xc04416c8]        // [0xc0441748:4]=0xc0802a28 "%5d " // "%5d "
         r7 = 0
         ldrne r1, [pc, 0x7c]     // [0xc044174c:4]=0xc0802a1e ".Delta:.." // "\nDelta:\n\n"
         ldreq r1, [pc, 0x7c]     // [0xc0441750:4]=0xc0802a12 ".Rawdata:.."
         sym.seq_printf ()        // sym.seq_printf(0x0)
         sl = [0xc04416dc]        // [0xc0441754:4]=0xc08106b1 "." // "\n"

    loc_0xc0441720: // orphan
         r3 = [r4]
         r2 = (byte) [r3 + 0x24]
         (a, b) = compare (r5, r2)
         blt 0xc0441704           // likely

    loc_0xc0441704: // orphan
         r3 = (byte) [r3 + 0x25]
         r1 = sb
         r0 = r8
         mla r3, r5, r3, r7
         r5 += 1
         ldr r2, [r6, r3, lsl 2]
         sym.seq_printf ()        // sym.seq_printf(0x0)

         goto loc_0xc0441730;
    loc_0xc0441730: // orphan
         r1 = sl
         r0 = r8
         sym.seq_printf ()        // sym.seq_printf(0x0)
         r7 += 1
         
    loc_0xc04416d8: // orphan
         // CODE XREF from sym.sitronix_proc_strawdata_show @ 0xc0441740(x)
         r3 = [r4]
         r5 = 0
         r3 = (byte) [r3 + 0x25]
         (a, b) = compare (r7, r3)
         blt 0xc0441720           // likely

}

// ----- END sitronix_proc_strawdata_show -----

// ----- BEGIN sitronix_proc_strawdata_test_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_strawdata_test_read (void) {
        push (r4, r5, r6, lr)
        r1 = 0xcc0
        r4 = [0xc0441768] // [0xc04417c4:4]=0xc0a5d4d0
        r3 = [r4]
        r0 = (byte) [r3 + 0x24]
        r3 = (byte) [r3 + 0x25]
        smulbb r0, r0, r3
        r0 = r0 << 2
        sym.__kmalloc () // sym.__kmalloc(0x3fc, 0xcc0)
        r6 = r0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = r6
        r0 = [r4]
        sym.sitronix_ts_get_rawdata () // sym.sitronix_ts_get_rawdata(0x0, 0x3fc)
        r5 = r0
        r0 = [r4]
        r5 &= r5
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        (a, b) = compare (r6, 0)
        je 0xc04417bc // unlikely
        goto loc_0xc04417b4;
    loc_0xc04417bc:
        r0 = r5
        pop (r4, r5, r6, pc)
        return r0;
}

// ----- END sitronix_proc_strawdata_test_read -----

// ----- BEGIN sitronix_stcmdio_show.part.3 (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stcmdio_show.part.3 (int32_t arg1) {
        push (r4, r5, r6, r7, r8, sb, sl, lr)
        r6 = r0       // arg1
        r1 = [0xc04417d8] // [0xc0441864:4]=0xc0802a2d "Data :" // "Data :"
        sym.strcpy () // char *strcpy(0, "Data :")
        r2 = [0xc04417e0] // [0xc0441868:4]=0xc0a5d4d0
        r3 = [r2]
        r3 = [r3 + 0x188]
        add r3, r3, r3, lsl 1
        r3 += 6
        (a, b) = compare (r3, 0x1000)
        bhs 0xc044182c // unlikely
        goto loc_0xc04417f4;
    loc_0xc044182c:
        r0 = r6
        r3 = 0x1000
        r2 = [0xc044183c] // [0xc0441878:4]=0xc0802a34 "The total string length > PAGE_SIZE (%ld), please split many times to read." // "The total string length > PAGE_SIZE (%ld), please split many ti"
        r1 = 0xc8
        pop (r4, r5, r6, r7, r8, sb, sl, lr)
        goto sym.snprintf // int snprintf(0, -1, "The total string length ", 0x1000)
        return r0;
    loc_0xc0441844: // orphan
         r3 = [r8]
         r2 = sb
         r1 = 0xa
         r3 = (byte) [r3 + r5]
         r5 += 1
         sym.snprintf () // int snprintf(0, -1, 0, 0xff)
         r4 += r0
         
    loc_0xc0441808: // orphan
         // CODE XREF from sym.sitronix_stcmdio_show.part.3 @ 0xc0441860(x)
         r3 = [r7]
         r0 = r6 + r4
         r3 = [r3 + 0x188]
         (a, b) = compare (r5, r3)
         blo 0xc0441844           // likely

         return r0;
    loc_0xc044181c: // orphan
         r1 = [0xc0441824]        // [0xc0441874:4]=0xc08106b1 "." // "\n"
         sym.strcpy () // char *strcpy(0, "\n")
         r0 = r4 + 1
         pop (r4, r5, r6, r7, r8, sb, sl, pc)

}

// ----- END sitronix_stcmdio_show.part.3 -----

// ----- BEGIN sitronix_stdrivercmd_show.part.1 (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stcmdio_show.part.3 (int32_t arg1) {
        push (r4, r5, r6, r7, r8, sb, sl, lr)
        r6 = r0       // arg1
        r1 = [0xc04417d8] // [0xc0441864:4]=0xc0802a2d "Data :" // "Data :"
        sym.strcpy () // char *strcpy(0, "Data :")
        r2 = [0xc04417e0] // [0xc0441868:4]=0xc0a5d4d0
        r3 = [r2]
        r3 = [r3 + 0x188]
        add r3, r3, r3, lsl 1
        r3 += 6
        (a, b) = compare (r3, 0x1000)
        bhs 0xc044182c // unlikely
        goto loc_0xc04417f4;
    loc_0xc044182c:
        r0 = r6
        r3 = 0x1000
        r2 = [0xc044183c] // [0xc0441878:4]=0xc0802a34 "The total string length > PAGE_SIZE (%ld), please split many times to read." // "The total string length > PAGE_SIZE (%ld), please split many ti"
        r1 = 0xc8
        pop (r4, r5, r6, r7, r8, sb, sl, lr)
        goto sym.snprintf // int snprintf(0, -1, "The total string length ", 0x1000)
        return r0;
    loc_0xc0441844: // orphan
         r3 = [r8]
         r2 = sb
         r1 = 0xa
         r3 = (byte) [r3 + r5]
         r5 += 1
         sym.snprintf () // int snprintf(0, -1, 0, 0xff)
         r4 += r0
         
    loc_0xc0441808: // orphan
         // CODE XREF from sym.sitronix_stcmdio_show.part.3 @ 0xc0441860(x)
         r3 = [r7]
         r0 = r6 + r4
         r3 = [r3 + 0x188]
         (a, b) = compare (r5, r3)
         blo 0xc0441844           // likely

         return r0;
    loc_0xc044181c: // orphan
         r1 = [0xc0441824]        // [0xc0441874:4]=0xc08106b1 "." // "\n"
         sym.strcpy () // char *strcpy(0, "\n")
         r0 = r4 + 1
         pop (r4, r5, r6, r7, r8, sb, sl, pc)

}

// ----- END sitronix_stdrivercmd_show.part.1 -----

// ----- BEGIN sitronix_stfwinfo_show.part.2 (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stcmdio_show.part.3 (int32_t arg1) {
        push (r4, r5, r6, r7, r8, sb, sl, lr)
        r6 = r0       // arg1
        r1 = [0xc04417d8] // [0xc0441864:4]=0xc0802a2d "Data :" // "Data :"
        sym.strcpy () // char *strcpy(0, "Data :")
        r2 = [0xc04417e0] // [0xc0441868:4]=0xc0a5d4d0
        r3 = [r2]
        r3 = [r3 + 0x188]
        add r3, r3, r3, lsl 1
        r3 += 6
        (a, b) = compare (r3, 0x1000)
        bhs 0xc044182c // unlikely
        goto loc_0xc04417f4;
    loc_0xc044182c:
        r0 = r6
        r3 = 0x1000
        r2 = [0xc044183c] // [0xc0441878:4]=0xc0802a34 "The total string length > PAGE_SIZE (%ld), please split many times to read." // "The total string length > PAGE_SIZE (%ld), please split many ti"
        r1 = 0xc8
        pop (r4, r5, r6, r7, r8, sb, sl, lr)
        goto sym.snprintf // int snprintf(0, -1, "The total string length ", 0x1000)
        return r0;
    loc_0xc0441844: // orphan
         r3 = [r8]
         r2 = sb
         r1 = 0xa
         r3 = (byte) [r3 + r5]
         r5 += 1
         sym.snprintf () // int snprintf(0, -1, 0, 0xff)
         r4 += r0
         
    loc_0xc0441808: // orphan
         // CODE XREF from sym.sitronix_stcmdio_show.part.3 @ 0xc0441860(x)
         r3 = [r7]
         r0 = r6 + r4
         r3 = [r3 + 0x188]
         (a, b) = compare (r5, r3)
         blo 0xc0441844           // likely

         return r0;
    loc_0xc044181c: // orphan
         r1 = [0xc0441824]        // [0xc0441874:4]=0xc08106b1 "." // "\n"
         sym.strcpy () // char *strcpy(0, "\n")
         r0 = r4 + 1
         pop (r4, r5, r6, r7, r8, sb, sl, pc)

}

// ----- END sitronix_stfwinfo_show.part.2 -----

// ----- BEGIN sitronix_stfwinfo_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stfwinfo_show (int32_t arg1) {
        r3 = [0xc0441884] // [0xc04418e8:4]=0xc0a5d4d0
        push (r0, r1, r2, lr)
        r0 = r2       // arg3
        r3 = [r3]
        r2 = [r3 + 0x10c]
        (a, b) = compare (r2, 0)
        bne 0xc04418b0 // likely
        goto loc_0xc0441898;
    loc_0xc04418b0:
        r2 = [r3 + 0x174]
        (a, b) = compare (r2, 0)
        bne 0xc04418dc // likely
        return r0;
    loc_0xc04418dc:
        sp += 0xc
        pop (lr)
        goto sym.sitronix_stcmdio_show.part.3 // sym.sitronix_stcmdio_show.part.3(0x0)
    loc_0xc0441898: // orphan
         r3 += 0x110
         r2 = [0xc04418a4]        // [0xc04418ec:4]=0xc0802a80 "fwinfo fail.mesage = %s." // "fwinfo fail\nmesage = %s\n"
         r1 = 0x64                // 'd'
         sp += 0xc
         pop (lr) // int snprintf(0, -1, "fwinfo fail\nmesage = %s\n", "")

}

// ----- END sitronix_stfwinfo_show -----

// ----- BEGIN sitronix_stdrivercmd_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stdrivercmd_show (int32_t arg1) {
        r3 = [0xc04418fc] // [0xc0441964:4]=0xc0a5d4d0
        push (r0, r1, r2, lr)
        r0 = r2       // arg3
        r2 = [r3]
        r3 = [r2 + 0x10c]
        (a, b) = compare (r3, 0)
        bne 0xc0441928 // likely
        goto loc_0xc0441910;
    loc_0xc0441928:
        r3 = [r2 + 0x174]
        (a, b) = compare (r3, 0)
        bne 0xc0441958 // likely
        return r0;
    loc_0xc0441958:
        sp += 0xc
        pop (lr)
        goto sym.sitronix_stcmdio_show.part.3 // sym.sitronix_stcmdio_show.part.3(0x0)
    loc_0xc0441910: // orphan
         r3 = r2 + 0x110
         r1 = 0x64                // 'd'
         r2 = [0xc0441920]        // [0xc0441968:4]=0xc0802ac6 "driver cmd fail.mesage = %s." // "driver cmd fail\nmesage = %s\n"
         sp += 0xc
         pop (lr) // int snprintf(0, -1, "driver cmd fail\nmesage = %s\n", "")

}

// ----- END sitronix_stdrivercmd_show -----

// ----- BEGIN sitronix_stcmdio_show (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stcmdio_show (int32_t arg1) {
        r3 = [0xc0441978] // [0xc04419e8:4]=0xc0a5d4d0
        push (r0, r1, r2, lr)
        r0 = r2       // arg3
        r3 = [r3]
        r2 = [r3 + 0x10c]
        (a, b) = compare (r2, 0)
        bne 0xc04419a4 // likely
        goto loc_0xc044198c;
    loc_0xc04419a4:
        r2 = [r3 + 0x174]
        (a, b) = compare (r2, 0)
        bne 0xc04419dc // likely
        return r0;
    loc_0xc04419dc:
        sp += 0xc
        pop (lr)
        goto sym.sitronix_stcmdio_show.part.3 // sym.sitronix_stcmdio_show.part.3(0x0)
    loc_0xc044198c: // orphan
         r3 += 0x110
         r2 = [0xc0441998]        // [0xc04419ec:4]=0xc0802b11 "cmdio fail.mesage = %s." // "cmdio fail\nmesage = %s\n"
         r1 = 0x64                // 'd'
         sp += 0xc
         pop (lr) // int snprintf(0, -1, "cmdio fail\nmesage = %s\n", "")

}

// ----- END sitronix_stcmdio_show -----

// ----- BEGIN sitronix_stproximity_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stproximity_store (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, lr)
        r6 = r3       // arg4
        r4 = [0xc0441a04] // [0xc0441a90:4]=0xc0a5d4d0
        r0 = [r4]
        r3 = (byte) [r0 + 0x8a]
        (a, b) = compare (r3, 0)
        je 0xc0441a88 // unlikely
        goto loc_0xc0441a10;
    loc_0xc0441a88:
        r0 = r6
        pop (r4, r5, r6, pc)
        goto loc_0xc0441a28;
        return r0;
    loc_0xc0441a28:
        r1 = 1
        r0 = [r4]
        sym.sitronix_ts_proximity_enable () // sym.sitronix_ts_proximity_enable(-1, 0x1)
        
    loc_0xc0441a34:
        r3 = (byte) [r5]
        (a, b) = compare (r3, 0x30) // '0'
        bne 0xc0441a4c // likely
        goto loc_0xc0441a40;
        return r0;
    loc_0xc0441a40:
        r1 = 0
        r0 = [r4]
        sym.sitronix_ts_proximity_enable () // sym.sitronix_ts_proximity_enable(-1, 0x0)
        
    loc_0xc0441a4c:
        r3 = (byte) [r5]
        (a, b) = compare (r3, 0x32) // '2'
        bne 0xc0441a7c // likely
        goto loc_0xc0441a58;
        return r0;
    loc_0xc0441a58:
        r0 = [r4]
        r3 = (byte) [r0 + 0x8b]
        (a, b) = compare (r3, 0)
        je 0xc0441a7c // unlikely
        goto loc_0xc0441a68;
    loc_0xc0441a7c:
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
            goto loc_0xc0441a68;
    loc_0xc0441a68:
        r3 = (byte) [r0 + 0x6c]
        (a, b) = compare (r3, 0)
        je 0xc0441a7c // unlikely
        goto loc_0xc0441a74;
        return r0;
    loc_0xc0441a74:
        r1 = 1
        sym.sitronix_ts_proximity_control_sensing () // sym.sitronix_ts_proximity_control_sensing(0x0, 0x1)
        break;
}

// ----- END sitronix_stproximity_store -----

// ----- BEGIN sitronix_stcmdio_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stcmdio_store (int32_t arg1, int32_t arg2, int32_t arg_0h) {
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        fp = r2       // arg3
        r2 = [0xc0442190] // [0xc0442588:4]=0xc0a04e08
        sp -= 0x2c
        sb = [0xc0442198] // [0xc044258c:4]=0xc0a5d4d0
        sl = var_1ah
        [var_ch] = r3 // arg4
        r5 = 0
        r3 = [r2]
        r7 = r5
        r4 = r5
        r8 = r5
        r1 = r5
        r6 = sl
        [var_24h] = r3
        r3 = [sb]
        [var_8h] = r5
        [var_4h] = r5
        [r3 + 0x10c] = r5
        r3 = r5
        [var_10h] = r2
        
    loc_0xc04421d4:
        // CODE XREF from sym.sitronix_stcmdio_store @ 0xc0442464(x)
        r2 = [var_ch]
        (a, b) = compare (r8, r2)
        bne 0xc04422d8 // unlikely
        goto loc_0xc04421e0;
        return r0;
    loc_0xc04421e0:
        r2 = r8 - r1
        r0 = sl
        r1 = fp + r1  // r13
        r3 = 0
        [var_1ah] = r3
        [sl + 4] = r3
        [sl + 8] = (half) r3
        sym.strlcpy () // char *strlcpy(0, "", 0)
        r0 = sl
        r6 = [0xc044220c] // [0xc044258c:4]=0xc0a5d4d0
        sym.strlen () // size_t strlen(0)
        r1 = r0
        r0 = sl
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
        (a, b) = compare (r0, 0)
        ldrge r3, [pc, 0x36c] // [0xc0442590:4]=0xc0a5d4cc
        ldrge r3, [r3]
        strbge r0, [r3, r5]
        addge r5, r5, 1
        (a, b) = compare (r4, 1)
        bne 0xc0442550 // likely
        goto loc_0xc0442234;
    while (/* 0xc0442550 */) {
        r0 = [sb]
        ldmib sp, (r1, r2)
        r3 = r0 + 0x178
        r0 += 0x70
        add r2, r2, r1, lsl 8
        [r3] = (half) r2
        [r0 + 0x104] = r4
        [r0 + 0x118] = r5
        [r0 + 0x11c] = r7
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r2 = r7 - 6
        clz r2, r2
        r3 = r4 & 1
        r2 = r2 >> 5
        (a, b) = compare (r3, r2)
        je 0xc044249c // likely
        while (/* 0xc0442510 */) {
            r2 = (byte) [fp + r8]
            (a, b) = compare (r2, 0x20)
            bne 0xc0442460 // likely
            r8 += 1
            goto 0xc04421d4
            r2 = r8 - r1
            [var_14h] = r3
            r2 += 1
            r3 = 0
            r1 = fp + r1  // r13
            [r6] = r3
            [r6 + 4] = r3
            r0 = r6
            [r6 + 8] = (half) r3
            sym.strlcpy () // char *strlcpy(0, "", -1)
            r3 = [var_14h_2]
            (a, b) = compare (r3, 0)
            bne 0xc0442370 // likely
            (a, b) = compare (r3, 1)
            bne 0xc04423ac // likely
            (a, b) = compare (r3, 2)
            bne 0xc04423e8 // likely
            (a, b) = compare (r3, 3)
            bne 0xc0442424 // likely
            r0 = r6
            [var_14h_2] = r3
            sym.strlen () // size_t strlen(0)
            r1 = r0
            r0 = r6
            sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
            (a, b) = compare (r0, 0)
            blt 0xc0442468 // unlikely
            r3 = [0xc0442470] // [0xc044258c:4]=0xc0a5d4d0
            r2 = 0x64     // 'd'
            r1 = [0xc0442478] // [0xc04425ac:4]=0xc0802b94 "parser data fail" // "parser data fail"
            r0 = [r3]
            goto 0xc0442348
            // CODE XREFS from sym.sitronix_stcmdio_store @ 0xc04423a8(x), 0xc04423e4(x), 0xc0442420(x), 0xc0442478(x), 0xc044257c(x)
            r0 += 0x110
            r7 = ~4
            sym.strlcpy () // char *strlcpy("", 0, 0)
            sym.__stack_chk_fail () // void __stack_chk_fail(void)
            r2 = [0xc044244c] // [0xc0442590:4]=0xc0a5d4cc
            r3 = [var_14h_3]
            r2 = [r2]
            r3 += 1
            [r2 + r5] = (byte) r0
            r5 += 1
            r0 = r6
            sym.strlen () // size_t strlen(0)
            r1 = r0
            r0 = r6
            sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
            r3 = r0 - 0
            [var_8h_2] = r3
            (>=) goto 0xc0442494 // likely
            r3 = 4
            goto 0xc044245c
            // CODE XREFS from sym.sitronix_stcmdio_store @ 0xc0442480(x), 0xc0442488(x), 0xc0442490(x), 0xc0442498(x)
            r1 = r8 + 1
            r3 = [0xc0442418] // [0xc044258c:4]=0xc0a5d4d0
            r2 = 0x64     // 'd'
            r1 = [0xc0442420] // [0xc04425a8:4]=0xc0802c07 "parser addr_l fail" // "parser addr_l fail"
            r0 = [r3]
            goto 0xc0442348
            r0 = r6
            sym.strlen () // size_t strlen(0)
            r1 = r0
            r0 = r6
            sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
            r3 = r0 - 0
            [var_4h_2] = r3
            (>=) goto 0xc044248c // likely
            r3 = 3
            goto 0xc044245c
            r3 = [0xc04423dc] // [0xc044258c:4]=0xc0a5d4d0
            r2 = 0x64     // 'd'
            r1 = [0xc04423e4] // [0xc04425a4:4]=0xc0802bf4 "parser addr_h fail" // "parser addr_h fail"
            r0 = [r3]
            goto 0xc0442348
            r0 = r6
            sym.strlen () // size_t strlen(0)
            r1 = r0
            r0 = r6
            sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
            (a, b) = compare (r0, 6)
            r7 = r0
            bls 0xc0442484 // likely
            r3 = 2
            goto 0xc044245c
            r3 = [0xc04423a0] // [0xc044258c:4]=0xc0a5d4d0
            r2 = 0x64     // 'd'
            r1 = [0xc04423a8] // [0xc04425a0:4]=0xc0802bdd "io type must be 0 to 6" // "io type must be 0 to 6"
            r0 = [r3]
            goto 0xc0442348
            r0 = r6
            sym.strlen () // size_t strlen(0)
            r1 = r0
            r0 = r6
            sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x0, 0x0)
            (a, b) = compare (r0, 1)
            r4 = r0
            bls 0xc044247c // likely
            r3 = 1
            goto 0xc044245c
            r3 = [0xc0442340] // [0xc044258c:4]=0xc0a5d4d0
            r2 = 0x64     // 'd'
            r1 = [0xc0442348] // [0xc044259c:4]=0xc0802b66 "write or read must be 0 or 1" // "write or read must be 0 or 1"
            r0 = [r3]
            r4 ^= 1
            r4 &= 1
            (a, b) = compare (r2, r4)
            je 0xc04424dc // likely
            r7 -= 6
            movne r7, 1
            (a, b) = compare (r3, r7)
            je 0xc0442510 // likely
            r0 = [r6]
            r0 += 0x70
            sym.mutex_unlock () // sym.mutex_unlock(0x6f)
            (a, b) = compare (r7, 0)
            (>=) goto 0xc044253c // likely
            // CODE XREFS from sym.sitronix_stcmdio_store @ 0xc04422d4(x), 0xc044254c(x)
            r3 = [var_10h_2]
            r0 = r7
            r2 = [arg_0h]
            r3 = [r3]
            (a, b) = compare (r2, r3)
            je 0xc0442580 // unlikely
            r0 = [r6]
            r2 = 0x64     // 'd'
            r1 = [0xc04422d0] // [0xc0442598:4]=0xc0802bcf "I2C/SPI error" // "I2C/SPI error"
            r0 += 0x110
            sym.strlcpy () // char *strlcpy("", "I2C/SPI error", -1)
            goto 0xc0442354
            r0 = [sb]
            r2 = [0xc04424f8] // [0xc0442594:4]=0xc0a5d4c8
            r1 = r0 + 0x178
            r3 = [r0 + 0x188]
            r2 = [r2]
            r1 = (word) [r1]
            r0 = [r0 + 0x18c]
            sym.TDU_CmdioRead () // sym.TDU_CmdioRead(-1, 0xffff, 0x0, -1)
            goto 0xc04422a8
            r3 = [sb]
            r0 = r3 + 0x178
            r1 = [r3 + 0x10]
            r2 = [r3 + 0x188]
            r0 = (word) [r0]
            r4 = [r1 + 0x1c]
            r3 = [r1 + 0x14]
            uxth r2, r2
            r1 = [0xc04424d4] // [0xc0442590:4]=0xc0a5d4cc
            r1 = [r1]
            r4 ()         // 0xffffffff(0xffff, 0x0, -1, -1)
            goto 0xc04422a8
        }
        r3 = [r6]
        r2 = 1
        r7 = r8
        [r3 + 0x10c] = r2
        goto 0xc0442354
        r0 = [sb]
        r2 = [0xc0442524] // [0xc0442590:4]=0xc0a5d4cc
        r1 = r0 + 0x178
        r3 = [r0 + 0x188]
        r2 = [r2]
        r1 = (word) [r1]
        r0 = [r0 + 0x18c]
        sym.TDU_CmdioWrite () // sym.TDU_CmdioWrite(-1, 0xffff, 0x0, -1)
        goto 0xc04422a8
        // CODE XREFS from sym.sitronix_stcmdio_store @ 0xc04424d8(x), 0xc044250c(x), 0xc0442538(x)
        r7 = r0
        r0 = [sb]
        r2 = [0xc0442294] // [0xc0442594:4]=0xc0a5d4c8
        r1 = r0 + 0x178
        r3 = r0 + 0x188
        r2 = [r2]
        r3 = (word) [r3]
        r1 = (word) [r1]
        sym.sitronix_ts_reg_read_1 () // sym.sitronix_ts_reg_read_1(-1, 0xffff, 0x0, 0xffff)
    }
    while (/* 0xc044255c */) {
    }
    loc_0xc0442570:
        r0 = [r6]
        r2 = 0x64     // 'd'
        r1 = [0xc0442580] // [0xc04425b0:4]=0xc0802c1a "io type 3 and 4 must write even number of data" // "io type 3 and 4 must write even number of data"
        goto 0xc0442348
        
        return r0;
    loc_0xc0442234: // orphan
         r3 = [0xc044223c]        // [0xc0442590:4]=0xc0a5d4cc
         r3 = [r3]
         r2 = (byte) [r3]
         r5 = (byte) [r3 + 1]
         add r5, r5, r2, lsl 8

}

// ----- END sitronix_stcmdio_store -----

// ----- BEGIN sitronix_stfwinfo_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stfwinfo_store (int32_t arg1, int32_t arg2, int32_t arg_0h) {
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        r8 = r2       // arg3
        r2 = [0xc04425c4] // [0xc04427e0:4]=0xc0a04e08
        sp -= 0x24
        r5 = [0xc04425cc] // [0xc04427e4:4]=0xc0a5d4d0
        r4 = 0
        [var_8h] = r3 // arg4
        r7 = r4
        r3 = [r2]
        sl = r4
        fp = [0xc04425e4] // [0xc04427e8:4]=0xc0a5d4cc
        r6 = r4
        r1 = r4
        sb = r4
        [var_1ch] = r3
        r3 = [r5]
        [var_4h] = r4
        [var_ch] = r2
        [r3 + 0x10c] = r4
        
    loc_0xc0442600:
        // CODE XREF from sym.sitronix_stfwinfo_store @ 0xc0442780(x)
        r3 = [var_8h]
        (a, b) = compare (r6, r3)
        bne 0xc04426d0 // unlikely
        goto loc_0xc044260c;
        return r0;
    loc_0xc044260c:
        r2 = r6 - r1
        r0 = var_12h
        r1 = r8 + r1
        r3 = 0
        [var_12h] = r3
        [var_16h] = r3
        [var_1ah] = (half) r3
        sym.strlcpy () // char *strlcpy("", 0, 0)
        r0 = var_12h_2
        sym.strlen () // size_t strlen("")
        r1 = r0
        r0 = var_12h_2
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x17801a, 0x178016)
        (a, b) = compare (r0, 0)
        ldrge r3, [pc, 0x19c] // [0xc04427e8:4]=0xc0a5d4cc
        ldrge r3, [r3]
        strbge r0, [r3, r4]
        addge r4, r4, 1
        (a, b) = compare (r7, 1)
        r0 = [r5]
        ldreq r3, [pc, 0x184] // [0xc04427e8:4]=0xc0a5d4cc
        r0 += 0x70
        ldreq r3, [r3]
        ldrbeq r2, [r3]
        ldrbeq r4, [r3, 1]
        r3 = [var_1ch]
        addeq r4, r4, r2, lsl 8
        [r0 + 0x104] = r7
        [r0 + 0x118] = r4
        [r0 + 0x11c] = r3
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r3 = [r5]
        r1 = [0xc0442694] // [0xc04427ec:4]=0xc0a5d4c8
        r2 = [r3 + 0x188]
        r1 = [r1]
        r0 = [r3 + 0x18c]
        sym.TDU_FWInfoRead () // sym.TDU_FWInfoRead(-1, 0x0, -1)
        r4 = r0
        r0 = [r5]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        (a, b) = compare (r4, 0)
        (>=) goto 0xc04427c4 // unlikely
        goto loc_0xc04426b8;
    loc_0xc04427c4:
        r3 = [r5]
        r2 = 1
        r4 = r6
        [r3 + 0x10c] = r2
        goto 0xc044273c
        
    loc_0xc044273c:
        // CODE XREFS from sym.sitronix_stfwinfo_store @ 0xc04426cc(x), 0xc04427d4(x)
        r3 = [var_ch_2]
        r0 = r4
        r2 = [arg_0h]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc04427d8 // unlikely
        goto loc_0xc0442754;
    loc_0xc044277c: // orphan
         r6 += 1
         
    loc_0xc04426dc: // orphan
         r2 = r6 - r1
         r0 = var_12h
         r2 += 1
         r1 = r8 + r1
         [var_12h] = sb
         [var_16h] = sb
         [var_1ah] = (half) sb
         sym.strlcpy () // char *strlcpy("", 0, -1)
         (a, b) = compare (sl, 0)
         r0 = var_12h_2
         bne 0xc0442758           // unlikely

    loc_0xc0442758: // orphan
         (a, b) = compare (sl, 1)
         bne 0xc0442784           // likely

    loc_0xc0442784: // orphan
         sym.strlen () // size_t strlen(0)
         r1 = r0
         r0 = var_12h_2
         sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
         (a, b) = compare (r0, 0)
         ldrge r2, [fp]
         addge sl, sl, 1
         strbge r0, [r2, r4]
         addge r4, r4, 1
         (>=) 
    loc_0xc0442778: // orphan
         // CODE XREF from sym.sitronix_stfwinfo_store @ 0xc04427c0(x)
         r1 = r6 + 1

         goto loc_0xc04427ac;
    loc_0xc04427ac: // orphan
         r0 = [r5]
         r2 = 0x64                // 'd'
         r1 = [0xc04427bc]        // [0xc04427f8:4]=0xc0802b94 "parser data fail" // "parser data fail"
         
    loc_0xc0442730: // orphan
         // CODE XREF from sym.sitronix_stfwinfo_store @ 0xc04427b8(x)
         r0 += 0x110
         r4 = ~4
         sym.strlcpy () // char *strlcpy("", 0, 0)

         return r0;
    loc_0xc04427d8: // orphan
         sp += 0x24
         pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)

    loc_0xc0442754: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0442760: // orphan
         sym.strlen () // size_t strlen(0)
         sl = 2
         r1 = r0
         r0 = var_12h_2
         sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
         [var_1ch] = r0

         goto loc_0xc0442708;
    loc_0xc0442708: // orphan
         sym.strlen () // size_t strlen(0)
         r1 = r0
         r0 = var_12h_2
         sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
         (a, b) = compare (r0, 1)
         r7 = r0
         bls 0xc04427bc           // unlikely

    loc_0xc04427bc: // orphan
         sl = 1
         
         goto loc_0xc0442724;
    loc_0xc0442724: // orphan
         r0 = [r5]
         r2 = 0x64                // 'd'
         r1 = [0xc0442734]        // [0xc04427f4:4]=0xc0802b66 "write or read must be 0 or 1" // "write or read must be 0 or 1"

         goto loc_0xc044260c;
    loc_0xc04426b8: // orphan
         r0 = [r5]
         r2 = 0x64                // 'd'
         r1 = [0xc04426c8]        // [0xc04427f0:4]=0xc0802bcf "I2C/SPI error" // "I2C/SPI error"
         r0 += 0x110
         sym.strlcpy () // char *strlcpy("", "I2C/SPI error", -1)
         
}

// ----- END sitronix_stfwinfo_store -----

// ----- BEGIN sitronix_stdrivercmd_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_stdrivercmd_store (int32_t arg1, int32_t arg2, int32_t arg_0h) {
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        r8 = r2       // arg3
        r2 = [0xc044280c] // [0xc0442a84:4]=0xc0a04e08
        sp -= 0x24
        r5 = [0xc0442814] // [0xc0442a88:4]=0xc0a5d4d0
        r4 = 0
        [var_8h] = r3 // arg4
        r7 = r4
        r3 = [r2]
        sl = r4
        fp = [0xc044282c] // [0xc0442a8c:4]=0xc0a5d4cc
        r6 = r4
        r1 = r4
        sb = r4
        [var_1ch] = r3
        r3 = [r5]
        [var_4h] = r4
        [var_ch] = r2
        [r3 + 0x10c] = r4
        
    loc_0xc0442848:
        // CODE XREF from sym.sitronix_stdrivercmd_store @ 0xc0442a0c(x)
        r3 = [var_8h]
        (a, b) = compare (r6, r3)
        bne 0xc0442920 // likely
        goto loc_0xc0442854;
        return r0;
    loc_0xc0442854:
        r2 = r6 - r1
        r0 = var_12h
        r1 = r8 + r1
        r3 = 0
        [var_12h] = r3
        [var_16h] = r3
        [var_1ah] = (half) r3
        sym.strlcpy () // char *strlcpy("", 0, 0)
        r0 = var_12h_2
        sym.strlen () // size_t strlen("")
        r1 = r0
        r0 = var_12h_2
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x17801a, 0x178016)
        (a, b) = compare (r0, 0)
        ldrge r3, [pc, 0x1f8] // [0xc0442a8c:4]=0xc0a5d4cc
        ldrge r3, [r3]
        strbge r0, [r3, r4]
        addge r4, r4, 1
        (a, b) = compare (r7, 1)
        bne 0xc0442a58 // likely
        goto loc_0xc04428a4;
    while (/* 0xc0442a58 */) {
        r2 = (byte) [r8 + r6]
        (a, b) = compare (r2, 0x20)
        bne 0xc0442a08 // likely
        r6 += 1
        goto 0xc0442848
        r2 = r6 - r1
        r0 = var_12h
        r2 += 1
        r1 = r8 + r1
        [var_12h] = sb
        [var_16h] = sb
        [var_1ah] = (half) sb
        sym.strlcpy () // char *strlcpy("", 0, -1)
        (a, b) = compare (sl, 0)
        r0 = var_12h_2
        bne 0xc04429a8 // unlikely
        (a, b) = compare (sl, 1)
        bne 0xc04429dc // likely
        sym.strlen () // size_t strlen(0)
        r1 = r0
        r0 = var_12h_2
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
        (a, b) = compare (r0, 0)
        blt 0xc0442a10 // unlikely
        r0 = [r5]
        r2 = 0x64     // 'd'
        r1 = [0xc0442a20] // [0xc0442aa0:4]=0xc0802b94 "parser data fail" // "parser data fail"
        goto 0xc0442980
        // CODE XREFS from sym.sitronix_stdrivercmd_store @ 0xc04429d8(x), 0xc0442a1c(x), 0xc0442a78(x)
        r0 += 0x110
        r4 = ~4
        sym.strlcpy () // char *strlcpy("", 0, 0)
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        r2 = [fp]
        sl += 1
        [r2 + r4] = (byte) r0
        r4 += 1
        sym.strlen () // size_t strlen(0)
        r1 = r0
        r0 = var_12h_2
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
        r3 = r0 - 0
        [var_1ch] = r3
        (>=) goto 0xc0442a28 // likely
        sl = 2
        goto 0xc0442a04
        // CODE XREFS from sym.sitronix_stdrivercmd_store @ 0xc0442a24(x), 0xc0442a2c(x)
        r1 = r6 + 1
        r0 = [r5]
        r2 = 0x64     // 'd'
        r1 = [0xc04429dc] // [0xc0442a9c:4]=0xc0802b83 "parser addr fail" // "parser addr fail"
        goto 0xc0442980
        sym.strlen () // size_t strlen(0)
        r1 = r0
        r0 = var_12h_2
        sym.st_formatinput.constprop.9 () // sym.st_formatinput.constprop.9(0x178016, 0x0)
        (a, b) = compare (r0, 1)
        r7 = r0
        bls 0xc0442a20 // unlikely
        sl = 1
        goto 0xc0442a04
        r0 = [r5]
        r2 = 0x64     // 'd'
        r1 = [0xc0442984] // [0xc0442a98:4]=0xc0802b66 "write or read must be 0 or 1" // "write or read must be 0 or 1"
        r0 = [r5]
        r2 = (word) [var_1ch]
        r3 = r0 + 0x178
        r0 += 0x70
        [r3] = (half) r2
        [r0 + 0x104] = r7
        [r0 + 0x118] = r4
        sym.mutex_lock () // sym.mutex_lock(0x6f)
        r3 = [r5]
        (a, b) = compare (r7, 1)
        r2 = [r3 + 0x188]
        bne 0xc0442a30 // likely
        r1 = [0xc0442a38] // [0xc0442a8c:4]=0xc0a5d4cc
        r0 = (byte) [r3 + 0x178]
        r1 = [r1]
        sym.sitronix_write_driver_cmd () // sym.sitronix_write_driver_cmd(0xff, 0x0, 0x0)
        goto 0xc04428f0
        // CODE XREF from sym.sitronix_stdrivercmd_store @ 0xc0442a40(x)
        r4 = r0
        r0 = [r5]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        (a, b) = compare (r4, 0)
        (>=) goto 0xc0442a44 // likely
        r3 = [r5]
        r2 = 1
        r4 = r6
        [r3 + 0x10c] = r2
        goto 0xc044298c
        // CODE XREFS from sym.sitronix_stdrivercmd_store @ 0xc044291c(x), 0xc0442a54(x)
        r3 = [var_ch_2]
        r0 = r4
        r2 = [var_1ch]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc0442a7c // unlikely
        r0 = [r5]
        r2 = 0x64     // 'd'
        r1 = [0xc0442918] // [0xc0442a94:4]=0xc0802bcf "I2C/SPI error" // "I2C/SPI error"
        r0 += 0x110
        sym.strlcpy () // char *strlcpy("", "I2C/SPI error", -1)
        goto 0xc044298c
        r1 = [0xc04428e8] // [0xc0442a90:4]=0xc0a5d4c8
        r0 = (byte) [r3 + 0x178]
        r1 = [r1]
        sym.sitronix_read_driver_cmd () // sym.sitronix_read_driver_cmd(0xff, 0x0, 0x0)
    }
    loc_0xc0442a6c:
        r0 = [r5]
        r2 = 0x64     // 'd'
        r1 = [0xc0442a7c] // [0xc0442aa4:4]=0xc0802ba5 "driver cmd must write even number of data" // "driver cmd must write even number of data"
        goto 0xc0442980
        
        return r0;
    loc_0xc04428a4: // orphan
         r3 = [0xc04428ac]        // [0xc0442a8c:4]=0xc0a5d4cc
         r3 = [r3]
         r4 = (byte) [r3]

}

// ----- END sitronix_stdrivercmd_store -----

// ----- BEGIN sitronix_copystring_without_line (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_copystring_without_line (int32_t arg1, int32_t arg2) {
        // CALL XREF from sym.sitronix_strequestfw_store @ 0xc044326c(x)
        push (r4, r5, r6, lr)
        r5 = r1       // arg2
        r6 = r0       // arg1
        sym.strlen () // size_t strlen(0)
        r1 = r6
        r4 = r0
        r4 -= 1
        r2 = r0
        r0 = r5
        sym.strlcpy () // char *strlcpy(0, 0, 0)
        r3 = (byte) [r6 + r4]
        r0 = 0
        (a, b) = compare (r3, 0xa)
        moveq r3, 0
        strbeq r3, [r5, r4]
        pop (r4, r5, r6, pc)
}

// ----- END sitronix_copystring_without_line -----

// ----- BEGIN sitronix_strequestfw_store (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_strequestfw_store (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, r8, lr)
        r7 = r3       // arg4
        r5 = [0xc0443220] // [0xc04433a0:4]=0xc0a04e08
        sp -= 0x28
        r0 = r2       // arg3
        r4 = r2       // arg3
        r3 = [r5]
        [var_24h] = r3
        r3 = 0
        [var_8h] = r3
        sym.strlen () // size_t strlen(0)
        (a, b) = compare (r0, 0xc8)
        mvnhi r4, 0x15
        bhi 0xc0443354 // unlikely
        goto loc_0xc0443248;
    loc_0xc0443354:
        r2 = [var_24h]
        r0 = r4
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443398 // unlikely
        goto loc_0xc0443368;
    loc_0xc0443398:
        sp += 0x28
        pop (r4, r5, r6, r7, r8, pc)
        goto loc_0xc0443264;
        return r0;
    loc_0xc0443264:
        r1 = r6
        r0 = r4
        sym.sitronix_copystring_without_line () // sym.sitronix_copystring_without_line(0x0, 0x0)
        r8 = [0xc0443278] // [0xc04433a8:4]=0xc0a5d4d0
        r1 = r6
        r3 = [r8]
        r2 = [r3 + 4]
        r2 += 0x10
        r0 = var_8h_2
        sym.request_firmware () // sym.request_firmware(0x178008, 0x0, 0xf)
        (a, b) = compare (r0, 0)
        mvnne r4, 1
        bne 0xc044334c // likely
        goto loc_0xc0443298;
    loc_0xc044334c:
        r0 = r6
        sym.kfree ()  // sym.kfree(0x0)
            goto loc_0xc0443298;
    loc_0xc0443298:
        r0 = [var_24h]
        r3 = [r0]
        (a, b) = compare (r3, 0x1000)
        bls 0xc044336c // likely
        goto loc_0xc04432a8;
        return r0;
    loc_0xc04432a8:
        r3 = var_1ch
        r2 = var_10h
        [var_4h] = r3
        r1 = var_ch
        r3 = var_18h
        [sp] = r3
        r3 = var_8h_2
        r0 = [r0 + 4]
        sym.st_check_fw () // sym.st_check_fw(-1, 0x17800c, 0x178010, 0x178014, 0x0, 0x0)
        r4 = r0 - 0
        bne 0xc044336c // likely
        goto loc_0xc04432d4;
    while (/* 0xc044336c */) {
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        r3 = [r8]
        r2 = 1
        r0 = [var_24h]
        [r3 + 0x2df] = (byte) r2
        sym.release_firmware () // sym.release_firmware(0x178016)
        (a, b) = compare (r4, 0)
        moveq r4, r7
    }
    loc_0xc0443384:
        r3 = [var_24h]
        r1 = 0x10000
        r2 = [var_20h]
        r0 = [r3 + 4]
        goto 0xc044332c
        
    loc_0xc044332c:
        // CODE XREF from sym.sitronix_strequestfw_store @ 0xc0443394(x)
        sym.st_set_dump () // sym.st_set_dump(0x0, 0x0)
        goto loc_0xc0443300;
        return r0;
    loc_0xc0443300:
        r0 = [r2 + 4]
        r1 = var_20h
        r0 += r3
        sym.st_check_cfg () // sym.st_check_cfg(-1, 0x178020)
        r4 = r0 - 0
        bne 0xc0443330 // likely
        goto loc_0xc0443318;
            goto loc_0xc0443318;
    loc_0xc0443318:
        r3 = [var_24h]
        r1 = [var_18h]
        r2 = [var_20h]
        r0 = [r3 + 4]
        r0 += r1
        return r0;
    loc_0xc04432d4: // orphan
         r3 = [var_24h]
         r1 = [var_ch]
         r2 = [var_10h]
         r0 = [r3 + 4]
         r0 += r1
         sym.st_set_dump ()       // sym.st_set_dump(0x0, 0x0)
         r2 = [var_24h]
         r3 = [var_18h]
         r1 = [r2]
         (a, b) = compare (r1, r3)
         bls 0xc0443330           // likely

}

// ----- END sitronix_strequestfw_store -----

// ----- BEGIN sitronix_copycmd_without_line (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_copycmd_without_line (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS: CALL 0xc044344c  CALL 0xc0443510  CALL 0xc044368c
        // XREFS: CALL 0xc0443764  CALL 0xc0443860  CALL 0xc0443928
        // XREFS: CALL 0xc0443a0c  CALL 0xc0443b48  CALL 0xc0443c24
        // XREFS: CALL 0xc0443d00  CALL 0xc0443ddc  CALL 0xc0443eb8
        // XREFS: CALL 0xc0443f94  CALL 0xc0444070  CALL 0xc044420c
        (a, b) = compare (r0, 0) // arg1
        je lr
        push (r4, lr)
        r4 = r2 - 1   // arg3
        r3 = r1       // arg2
        bpl 0xc04433fc // unlikely
        goto loc_0xc04433c4;
    loc_0xc04433fc:
        r2 = r4
        r1 = r0       // arg1
        r0 = r3
        sym._copy_from_user_44 () // sym._copy_from_user_44(0x0, 0x0, 0x0)
        r4 = r0
        goto 0xc04433ec
        
    loc_0xc04433ec:
        // CODE XREF from sym.sitronix_copycmd_without_line @ 0xc0443410(x)
        (a, b) = compare (r4, 0)
        movge r0, r4
        mvnlt r0, 4
        pop (r4, pc)
        goto loc_0xc04433d4;
        return r0;
    loc_0xc04433d4:
        r1 = 1
        r0 = [0xc04433e0] // [0xc0443418:4]=0xc07ccde8 "./include/linux/thread_info.h" // "./include/linux/thread_info.h"
        [r2] = (byte) r1
        r2 = 9
        r1 = 0x96
        sym.warn_slowpath_fmt () // sym.warn_slowpath_fmt(0xc07ccde8, 0x96, 0x9, 0x0, 0x0, 0x0)
        break;
}

// ----- END sitronix_copycmd_without_line -----

// ----- BEGIN sitronix_proc_stexdiff_write (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_stexdiff_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r6 = [0xc0443840] // [0xc04438f0:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r7 = r2       // arg3
        r3 = [r6]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        bgt 0xc04438e0 // unlikely
        goto loc_0xc044386c;
    loc_0xc04438e0:
        r7 = ~0x15
        goto 0xc04438c0
        
    loc_0xc04438c0:
        // CODE XREF from sym.sitronix_proc_stexdiff_write @ 0xc04438e4(x)
        r2 = [var_ch_2]
        r0 = r7
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc04438e8 // unlikely
        goto loc_0xc04438d4;
        goto loc_0xc0443884;
        return r0;
    loc_0xc0443884:
        r1 = [r4 + 0x30c]
        r0 = var_6h
        sym.strcmp () // int strcmp("\x17", "")
        r4 = r0 - 0
        bne 0xc04438e0 // likely
        goto loc_0xc0443898;
    loc_0xc0443898:
        // CODE XREF from sym.sitronix_proc_stexdiff_write @ 0xc04438dc(x)
        r5 = [0xc04438a0] // [0xc04438f8:4]=0xc0a5d4d0
        r0 = [r5]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = r4
        r0 = [r5]
        sym.sitronix_ts_exdiff_enable () // sym.sitronix_ts_exdiff_enable(0x0, 0x0)
        r0 = [r5]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x70)
        break;
    loc_0xc04438d4: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc044386c: // orphan
         r4 = [0xc0443874]        // [0xc04438f4:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_6h
         r1 = [r4 + 0x308]        // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         je 0xc04438d8            // unlikely

    loc_0xc04438d8: // orphan
         r4 = 1
         
}

// ----- END sitronix_proc_stexdiff_write -----

// ----- BEGIN sitronix_proc_stswktapmode_write (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_stswktapmode_write (int32_t arg1, int32_t arg2) {
        push (r0, r1, r2, r3, r4, r5, r6, lr)
        r0 = r1       // arg2
        r4 = [0xc044390c] // [0xc04439d4:4]=0xc0a04e08
        r1 = var_2h
        r5 = r2       // arg3
        r3 = [r4]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fe2, 0x0)
        (a, b) = compare (r0, 0)
        bgt 0xc0443964 // unlikely
        goto loc_0xc0443934;
    loc_0xc0443964:
        r5 = ~0x15
        goto 0xc04439b4
        
    loc_0xc04439b4:
        // CODE XREF from sym.sitronix_proc_stswktapmode_write @ 0xc0443968(x)
        r2 = [var_ch_2]
        r0 = r5
        r3 = [r4]
        (a, b) = compare (r2, r3)
        je 0xc04439cc // unlikely
        goto loc_0xc04439c8;
        goto loc_0xc044394c;
        return r0;
    loc_0xc044394c:
        r1 = [r6 + 0x33c]
        r0 = var_6h
        sym.strcmp () // int strcmp("\x17", "")
        (a, b) = compare (r0, 0)
        moveq r2, 2
        je 0xc0443970 // unlikely
        goto loc_0xc0443964;
    loc_0xc0443970:
        r3 = [0xc0443978] // [0xc04439dc:4]=0xc0a5d4d0
        r0 = [r3]
        r6 = r3
        (a, b) = compare (r0, 0)
        je 0xc04439b4 // likely
        goto loc_0xc0443984;
    loc_0xc0443984:
        r3 = (byte) [r0 + 0x1ba]
        (a, b) = compare (r2, 2)
        r0 += 0x70
        bic r3, r3, 3
        orrne r3, r3, 1
        orreq r3, r3, 2
        [r0 + 0x14a] = (byte) r3
        sym.mutex_lock () // sym.mutex_lock(0x70)
        sym.sitronix_swk_config_restore ()
        r0 = [r6]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
            goto loc_0xc0443964;
    loc_0xc04439c8: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0443934: // orphan
         r6 = [0xc044393c]        // [0xc04439d8:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_6h
         r1 = [r6 + 0x338]        // "1"
         sym.strcmp () // int strcmp("\x17", "1")
         (a, b) = compare (r0, 0)
         je 0xc044396c            // unlikely

    loc_0xc044396c: // orphan
         r2 = 1

         goto loc_0xc0443984;
}

// ----- END sitronix_proc_stswktapmode_write -----

// ----- BEGIN sitronix_proc_stswkselect_write (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_stswkselect_write (int32_t arg1, int32_t arg2) {
        push (r0, r1, r2, r3, r4, r5, r6, lr)
        r0 = r1       // arg2
        r5 = [0xc04439f0] // [0xc0443b00:4]=0xc0a04e08
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fe2, 0x0)
        (a, b) = compare (r0, 0)
        bgt 0xc0443a6c // unlikely
        goto loc_0xc0443a18;
    loc_0xc0443a6c:
        r6 = ~0x15
        goto 0xc0443ad8
        
    loc_0xc0443ad8:
        // CODE XREF from sym.sitronix_proc_stswkselect_write @ 0xc0443a70(x)
        r2 = [var_ch_2]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443af8 // unlikely
        goto loc_0xc0443aec;
        goto loc_0xc0443a2c;
        return r0;
    loc_0xc0443a2c:
        r1 = [0xc0443a34] // [0xc0443b08:4]=0xc07ca440 "1" // "1"
        r0 = var_6h
        sym.strcmp () // int strcmp("\x17", "1")
        (a, b) = compare (r0, 0)
        je 0xc0443a74 // unlikely
        goto loc_0xc0443a40;
    loc_0xc0443a74:
        r0 = 1
        
    loc_0xc0443a78:
        // CODE XREF from sym.sitronix_proc_stswkselect_write @ 0xc0443af4(x)
        r2 = [0xc0443a80] // [0xc0443b14:4]=0xc0a5d4d0
        r3 = [r2]
        r4 = r2
        (a, b) = compare (r3, 0)
        je 0xc0443ad8 // likely
        goto loc_0xc0443a8c;
        goto loc_0xc0443a54;
        return r0;
    loc_0xc0443a54:
        r1 = [0xc0443a5c] // [0xc0443b10:4]=0xc07d9e94 "3" // "3"
        r0 = var_6h
        sym.strcmp () // int strcmp("\x17", "3")
        (a, b) = compare (r0, 0)
        moveq r0, 3
        je 0xc0443a78 // unlikely
        goto loc_0xc0443a6c;
        return r0;
        return r0;
    loc_0xc0443a8c:
        (a, b) = compare (r0, 2)
        r2 = 0
        [r3 + 0x1ba] = r2
        je 0xc0443abc // unlikely
        goto loc_0xc0443a9c;
    loc_0xc0443abc:
        [r3 + 0x1ba] = (byte) r0
        
    loc_0xc0443ac0:
        r0 = r3 + 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        sym.sitronix_swk_config_restore ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        goto loc_0xc0443aac;
        return r0;
    loc_0xc0443aac:
        (a, b) = compare (r0, 1)
        ldrne r2, [r3, 0x1be]
        strne r2, [r3, 0x1ba]
        bne 0xc0443ac0 // likely
        goto loc_0xc0443abc;
        return r0;
        return r0;
    loc_0xc0443aec: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0443a18: // orphan
         r1 = [0xc0443a20]        // [0xc0443b04:4]=0xc07c97fa "0" // "0"
         r0 = var_6h
         sym.strcmp () // int strcmp("\x17", "0")
         (a, b) = compare (r0, 0)
         je 0xc0443a78            // unlikely

    loc_0xc0443a9c: // orphan
         (a, b) = compare (r0, 3)
         moveq r2, 0xf
         strbeq r2, [r3, 0x1bb]
         je 0xc0443ac0            // unlikely

    loc_0xc0443a40: // orphan
         r1 = [0xc0443a48]        // [0xc0443b0c:4]=0xc07db014 "2" // "2"
         r0 = var_6h
         sym.strcmp () // int strcmp("\x17", "2")
         (a, b) = compare (r0, 0)
         je 0xc0443af0            // unlikely

    loc_0xc0443af0: // orphan
         r0 = 2
         
         goto loc_0xc0443a54;
}

// ----- END sitronix_proc_stswkselect_write -----

// ----- BEGIN sitronix_proc_swu_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_swu_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443b28] // [0xc0443be8:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443b98 // unlikely
        goto loc_0xc0443b58;
    loc_0xc0443b98:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443be0 // unlikely
        goto loc_0xc0443bac;
    loc_0xc0443be0:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443b70;
        return r0;
    loc_0xc0443b70:
        r4 = [0xc0443b78] // [0xc0443bf0:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443b84:
        // CODE XREF from sym.sitronix_proc_swu_write @ 0xc0443bdc(x)
        r0 = 1
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443b58: // orphan
         r4 = [0xc0443b60]        // [0xc0443bec:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x10]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443bb0           // likely

    loc_0xc0443bb0: // orphan
         r1 = [r4 + 0x14]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443b98           // likely

         goto loc_0xc0443bc8;
    loc_0xc0443bc8: // orphan
         r4 = [0xc0443bd0]        // [0xc0443bf0:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_swu_write -----

// ----- BEGIN sitronix_proc_glove_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_glove_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443c04] // [0xc0443cc4:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443c74 // unlikely
        goto loc_0xc0443c34;
    loc_0xc0443c74:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443cbc // unlikely
        goto loc_0xc0443c88;
    loc_0xc0443cbc:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443c4c;
        return r0;
    loc_0xc0443c4c:
        r4 = [0xc0443c54] // [0xc0443ccc:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443c60:
        // CODE XREF from sym.sitronix_proc_glove_write @ 0xc0443cb8(x)
        r0 = 2
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443c34: // orphan
         r4 = [0xc0443c3c]        // [0xc0443cc8:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x38]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443c8c           // likely

    loc_0xc0443c8c: // orphan
         r1 = [r4 + 0x3c]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443c74           // likely

         goto loc_0xc0443ca4;
    loc_0xc0443ca4: // orphan
         r4 = [0xc0443cac]        // [0xc0443ccc:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_glove_write -----

// ----- BEGIN sitronix_proc_charge_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_charge_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443ce0] // [0xc0443da0:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443d50 // unlikely
        goto loc_0xc0443d10;
    loc_0xc0443d50:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443d98 // unlikely
        goto loc_0xc0443d64;
    loc_0xc0443d98:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443d28;
        return r0;
    loc_0xc0443d28:
        r4 = [0xc0443d30] // [0xc0443da8:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443d3c:
        // CODE XREF from sym.sitronix_proc_charge_write @ 0xc0443d94(x)
        r0 = 3
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443d10: // orphan
         r4 = [0xc0443d18]        // [0xc0443da4:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x60]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443d68           // likely

    loc_0xc0443d68: // orphan
         r1 = [r4 + 0x64]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443d50           // likely

         goto loc_0xc0443d80;
    loc_0xc0443d80: // orphan
         r4 = [0xc0443d88]        // [0xc0443da8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_charge_write -----

// ----- BEGIN sitronix_proc_jittersuppress_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_jittersuppress_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443dbc] // [0xc0443e7c:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443e2c // unlikely
        goto loc_0xc0443dec;
    loc_0xc0443e2c:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443e74 // unlikely
        goto loc_0xc0443e40;
    loc_0xc0443e74:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443e04;
        return r0;
    loc_0xc0443e04:
        r4 = [0xc0443e0c] // [0xc0443e84:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443e18:
        // CODE XREF from sym.sitronix_proc_jittersuppress_write @ 0xc0443e70(x)
        r0 = 4
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443dec: // orphan
         r4 = [0xc0443df4]        // [0xc0443e80:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x88]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443e44           // likely

    loc_0xc0443e44: // orphan
         r1 = [r4 + 0x8c]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443e2c           // likely

         goto loc_0xc0443e5c;
    loc_0xc0443e5c: // orphan
         r4 = [0xc0443e64]        // [0xc0443e84:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_jittersuppress_write -----

// ----- BEGIN sitronix_proc_palm_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_palm_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443e98] // [0xc0443f58:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443f08 // unlikely
        goto loc_0xc0443ec8;
    loc_0xc0443f08:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc0443f50 // unlikely
        goto loc_0xc0443f1c;
    loc_0xc0443f50:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443ee0;
        return r0;
    loc_0xc0443ee0:
        r4 = [0xc0443ee8] // [0xc0443f60:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443ef4:
        // CODE XREF from sym.sitronix_proc_palm_write @ 0xc0443f4c(x)
        r0 = 5
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443ec8: // orphan
         r4 = [0xc0443ed0]        // [0xc0443f5c:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0xb0]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443f20           // likely

    loc_0xc0443f20: // orphan
         r1 = [r4 + 0xb4]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443f08           // likely

         goto loc_0xc0443f38;
    loc_0xc0443f38: // orphan
         r4 = [0xc0443f40]        // [0xc0443f60:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_palm_write -----

// ----- BEGIN sitronix_proc_headphone_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_headphone_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0443f74] // [0xc0444034:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc0443fe4 // unlikely
        goto loc_0xc0443fa4;
    loc_0xc0443fe4:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc044402c // unlikely
        goto loc_0xc0443ff8;
    loc_0xc044402c:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0443fbc;
        return r0;
    loc_0xc0443fbc:
        r4 = [0xc0443fc4] // [0xc044403c:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = 1
        
    loc_0xc0443fd0:
        // CODE XREF from sym.sitronix_proc_headphone_write @ 0xc0444028(x)
        r0 = 6
        sym.sitronix_mode_switch ()
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0443fa4: // orphan
         r4 = [0xc0443fac]        // [0xc0444038:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0xd8]         // "on"
         sym.strcmp () // int strcmp("\x17", "on")
         (a, b) = compare (r0, 0)
         bne 0xc0443ffc           // likely

    loc_0xc0443ffc: // orphan
         r1 = [r4 + 0xdc]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc0443fe4           // likely

         goto loc_0xc0444014;
    loc_0xc0444014: // orphan
         r4 = [0xc044401c]        // [0xc044403c:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r1 = r7
         
}

// ----- END sitronix_proc_headphone_write -----

// ----- BEGIN sitronix_proc_grip_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_grip_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc0444050] // [0xc04441d0:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        mvngt r6, 0x15
        bgt 0xc04440c4 // unlikely
        goto loc_0xc0444080;
    loc_0xc04440c4:
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc04441c8 // unlikely
        goto loc_0xc04440d8;
    loc_0xc04441c8:
        sp += 0x14
        pop (r4, r5, r6, r7, pc)
        goto loc_0xc0444098;
        return r0;
    loc_0xc0444098:
        r4 = [0xc04440a0] // [0xc04441d8:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r2 = r7
        
    loc_0xc04440ac:
        // CODE XREFS from sym.sitronix_proc_grip_write @ 0xc0444104(x), 0xc0444130(x), 0xc044415c(x), 0xc044418c(x)
        r1 = 1
        return r0;
    loc_0xc0444080: // orphan
         r4 = [0xc0444088]        // [0xc04441d4:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x108]        // "0"
         sym.strcmp () // int strcmp("\x17", "0")
         r7 = r0 - 0
         bne 0xc04440dc           // likely

    loc_0xc04440dc: // orphan
         r1 = [r4 + 0x10c]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc0444108           // likely

    loc_0xc0444108: // orphan
         r1 = [r4 + 0x110]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc0444134           // likely

    loc_0xc0444134: // orphan
         r1 = [r4 + 0x114]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc0444160           // likely

    loc_0xc0444160: // orphan
         r1 = [r4 + 0x100]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc0444190           // likely

    loc_0xc0444190: // orphan
         r1 = [r4 + 0x104]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         r7 = r0 - 0
         mvnne r6, 4
         bne 0xc04440c4           // likely

         goto loc_0xc04441a8;
    loc_0xc04441a8: // orphan
         r4 = [0xc04441b0]        // [0xc04441d8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r3 = [r4]
         r1 = r7
         r2 = (byte) [r3 + 0x1ad]
         
    loc_0xc04440b0: // orphan
         // CODE XREF from sym.sitronix_proc_grip_write @ 0xc04441c4(x)
         r0 = 7
         sym.sitronix_mode_switch_value () // sym.sitronix_mode_switch_value(0x7, 0x0, 0x0, 0x0, 0x0)
         r0 = [r4]
         r0 += 0x70
         sym.mutex_unlock ()      // sym.mutex_unlock(0x6f)

         goto loc_0xc0444174;
    loc_0xc0444174: // orphan
         r4 = [0xc044417c]        // [0xc04441d8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r3 = [r4]
         r2 = (byte) [r3 + 0x1ad]
         
    loc_0xc0444148: // orphan
         r4 = [0xc0444150]        // [0xc04441d8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r2 = 3
         
         goto loc_0xc044411c;
    loc_0xc044411c: // orphan
         r4 = [0xc0444124]        // [0xc04441d8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r2 = 2
         
         goto loc_0xc04440f0;
    loc_0xc04440f0: // orphan
         r4 = [0xc04440f8]        // [0xc04441d8:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         r2 = 1
         
         goto loc_0xc0444098;
}

// ----- END sitronix_proc_grip_write -----

// ----- BEGIN sitronix_proc_strawdata_test_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_strawdata_test_write (int32_t arg1, int32_t arg2) {
        push (r4, r5, r6, r7, lr)
        sp -= 0x14
        r5 = [0xc04441ec] // [0xc04442ec:4]=0xc0a04e08
        r0 = r1       // arg2
        r1 = var_2h
        r6 = r2       // arg3
        r3 = [r5]
        [var_ch] = r3
        r3 = 0
        [var_2h] = r3
        [var_6h] = r3
        [var_ah] = (half) r3
        sym.sitronix_copycmd_without_line () // sym.sitronix_copycmd_without_line(0x0, 0x177fda, 0x0)
        (a, b) = compare (r0, 0)
        bgt 0xc04442dc // unlikely
        goto loc_0xc0444218;
    loc_0xc04442dc:
        r6 = ~0x15
        goto 0xc044425c
        
    loc_0xc044425c:
        // CODE XREF from sym.sitronix_proc_strawdata_test_write @ 0xc04442e0(x)
        r2 = [var_ch]
        r0 = r6
        r3 = [r5]
        (a, b) = compare (r2, r3)
        je 0xc04442e4 // unlikely
        goto loc_0xc0444270;
        goto loc_0xc0444230;
        return r0;
    loc_0xc0444230:
        r4 = [0xc0444238] // [0xc04442f4:4]=0xc0a5d4d0
        r0 = [r4]
        r0 += 0x70
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = r7
        r0 = [r4]
        sym.sitronix_ts_enable_raw () // sym.sitronix_ts_enable_raw(0x0, 0x0, 0x0)
        sym.sitronix_mt_restore ()
        
    loc_0xc0444250:
        // CODE XREF from sym.sitronix_proc_strawdata_test_write @ 0xc04442a8(x)
        r0 = [r4]
        r0 += 0x70
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        return r0;
    loc_0xc0444270: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0444218: // orphan
         r4 = [0xc0444220]        // [0xc04442f0:4]=0xc0a2d800 // (pstr 0xc0802d7a) "swu"
         r0 = var_2h
         r1 = [r4 + 0x2e4]        // "off"
         sym.strcmp () // int strcmp("\x17", "off")
         r7 = r0 - 0
         bne 0xc0444274           // likely

    loc_0xc0444274: // orphan
         r1 = [r4 + 0x2e8]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc04442ac           // likely

    loc_0xc04442ac: // orphan
         r1 = [r4 + 0x2ec]
         r0 = var_2h
         sym.strcmp () // int strcmp("\x17", "")
         (a, b) = compare (r0, 0)
         bne 0xc04442dc           // likely

         goto loc_0xc04442c0;
    loc_0xc04442c0: // orphan
         r4 = [0xc04442c8]        // [0xc04442f4:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         sym.sitronix_mt_pause ()
         r1 = 2
         
    loc_0xc04442a0: // orphan
         // CODE XREF from sym.sitronix_proc_strawdata_test_write @ 0xc04442d8(x)
         r0 = [r4]
         sym.sitronix_ts_enable_raw () // sym.sitronix_ts_enable_raw(-1, 0x0, 0x0)
         
    loc_0xc0444288: // orphan
         r4 = [0xc0444290]        // [0xc04442f4:4]=0xc0a5d4d0
         r0 = [r4]
         r0 += 0x70
         sym.mutex_lock ()        // sym.mutex_lock(0x70)
         sym.sitronix_mt_pause ()
         r1 = 1

         goto loc_0xc0444230;
}

// ----- END sitronix_proc_strawdata_test_write -----

// ----- BEGIN sitronix_proc_strawdata_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_strawdata_write (void) {
        goto sym.sitronix_proc_strawdata_test_write // sym.sitronix_proc_strawdata_test_write(0x0, 0x0)
}

// ----- END sitronix_proc_strawdata_write -----

// ----- BEGIN sitronix_create_sysfs (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_create_sysfs (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cc60(x)
        push (r4, r5, r6, lr)
        r1 = 0
        r4 = r0       // arg1
        r0 = [0xc0444364] // [0xc0444390:4]=0xc0802c49 "sitronix_ts_attrs" // "sitronix_ts_attrs"
        sym.kobject_create_and_add () // sym.kobject_create_and_add(0xc0802c49, 0x0)
        r1 = [0xc044436c] // [0xc0444394:4]=0xc0731ef0
        [r4 + 0x2c] = r0
        sym.sysfs_create_group () // sym.sysfs_create_group(0xc0802c49)
        r5 = r0 - 0   // "sitronix_ts_attrs"
        je 0xc0444388 // unlikely
        goto loc_0xc0444378;
    loc_0xc0444388:
        r0 = r5
        pop (r4, r5, r6, pc)
        return r0;
}

// ----- END sitronix_create_sysfs -----

// ----- BEGIN sitronix_remove_sysfs (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_remove_sysfs (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_remove @ 0xc043c678(x)
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043caf8(x)
        r3 = [r0 + 0x2c] // arg1
        (a, b) = compare (r3, 0)
        je lr
        push (r4, lr)
        r4 = r0       // arg1
        r1 = [0xc04443b4] // [0xc04443c4:4]=0xc0731ef0
        r0 = r3
        sym.sysfs_remove_group () // sym.sysfs_remove_group(-1, 0xc0731ef0)
        r0 = [r4 + 0x2c]
        pop (r4, lr)  // r13
        goto sym.kobject_put // sym.kobject_put(-1)
}

// ----- END sitronix_remove_sysfs -----

// ----- BEGIN sitronix_create_st_dev (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_create_st_dev (int32_t arg1) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cc7c(x)
        push (r0, r1, r2, r3, r4, r5, r6, r7, r8, sb, sl, lr)
        sl = r0       // arg1
        r6 = [0xc0444ac4] // [0xc0444bf4:4]=0xc0a04e08
        r0 = var_10h
        r8 = [0xc0444acc] // [0xc0444bf8:4]=0xc0a5d4f8 // (pstr 0xc0802a09) "sitronix"
        r2 = 1
        r7 = [0xc0444ad4] // [0xc0444bfc:4]=0xc0802c5b "sitronixDev" // "sitronixDev"
        r1 = 0
        r3 = [r6]
        [var_ch] = r3
        r3 = [r8 + 4]
        r3 = r3 << 0x14
        [r0 - 8]! = r3
        r3 = r7       // "sitronixDev"
        sym.alloc_chrdev_region () // sym.alloc_chrdev_region(0x177fd8, 0x0, 0x1, 0xc0802c5b)
        r5 = r0 - 0
        blt 0xc0444bd4 // unlikely
        goto loc_0xc0444af8;
    loc_0xc0444bd4:
        // CODE XREF from sym.sitronix_create_st_dev @ 0xc0444b8c(x)
        r2 = [var_10h]
        r0 = r5
        r3 = [r6]
        (a, b) = compare (r2, r3)
        je 0xc0444bec // unlikely
        goto loc_0xc0444be8;
    loc_0xc0444bec:
        sp += 0x10
        pop (r4, r5, r6, r7, r8, sb, sl, pc)
        goto loc_0xc0444b3c;
        return r0;
    loc_0xc0444b3c:
        r2 = r8 + 0x68
        r1 = r7
        sym.__class_create () // sym.__class_create(0x0, 0x0, 0x68)
        if (r0 != 0x1000)
        sb = r0
        [r4 + 0x68] = r0
        bls 0xc0444b90 // likely
        goto loc_0xc0444b58;
    loc_0xc0444b90:
        r2 = [r8 + 4]
        r3 = r5
        [sp] = r7
        r1 = r5
        r2 = r2 << 0x14
        sym.device_create () // sym.device_create(0x0, 0x0, 0xfff00000, 0x0, 0x0, 0x0)
        if (r0 != 0x1000)
        bls 0xc0444bc0 // likely
        goto loc_0xc0444bb0;
    loc_0xc0444bc0:
        r2 = r8 + 0x6c
        r1 = [0xc0444bcc] // [0xc0444c08:4]=0xc0802c67 "&ts->irq_wait_queue" // "&ts->irq_wait_queue"
        r0 = sl + 0x29c
        sym.__init_waitqueue_head () // sym.__init_waitqueue_head(0x29c)
        [sl + 0x2a8] = (byte) r5
            goto loc_0xc0444bb0;
    loc_0xc0444bb0:
        r0 = [r8 + 0x68]
        r5 = ~0x12
        sym.class_destroy () // sym.class_destroy(-1)
        goto 0xc0444b70
        return r0;
    loc_0xc0444af8: // orphan
         r5 = [0xc0444b00]        // [0xc0444c00:4]=0xc0a2db98
         r0 = r8 + 8
         r3 = [var_ch]
         r4 = r8
         r1 = r5
         r3 = r3 >> 0x14
         [r8 + 4] = r3
         sym.cdev_init ()         // sym.cdev_init(0x8, 0xc0a2db98)
         r2 = 1
         r0 = r8 + 8
         r3 = 0
         [r8 + 0x54] = r5
         [r8 + 0x50] = r3
         r1 = [var_8h]
         sym.cdev_add ()          // sym.cdev_add(0x8, 0x178016, 0x1)
         r5 = r0 - 0
         bne 0xc0444b78           // likely

    loc_0xc0444b78: // orphan
         r1 = 1
         r0 = [var_8h_2]
         sym.unregister_chrdev_region () // sym.unregister_chrdev_region(0x178016, 0x1)
         r3 = 0
         [r4 + 0x68] = r3
         
         goto loc_0xc0444b3c;
    loc_0xc0444b70: // orphan
         // CODE XREF from sym.sitronix_create_st_dev @ 0xc0444bbc(x)
         r0 = [0xc0444b78]        // [0xc0444c04:4]=0xc0a5d500
         sym.cdev_del ()          // sym.cdev_del(0xc0a5d500)

         goto loc_0xc0444b58;
    loc_0xc0444b58: // orphan
         r1 = r5
         r3 = r7
         r2 = 0x100
         r0 = [r8 + 4]
         sym.__unregister_chrdev () // sym.__unregister_chrdev(-1, 0x0, 0x100)
         r5 = sb

}

// ----- END sitronix_create_st_dev -----

// ----- BEGIN sitronix_remove_st_dev (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_remove_st_dev (void) {
        // CALL XREF from sym.sitronix_ts_remove @ 0xc043c670(x)
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043caec(x)
        push (r4, r5, r6, lr)
        r5 = [0xc0444c18] // [0xc0444c50:4]=0xc0a5d4f8 // (pstr 0xc0802a09) "sitronix"
        r0 = [r5 + 0x68]
        r4 = [r5 + 4]
        (a, b) = compare (r0, 0)
        popeq (r4, r5, r6, pc) // r13
        goto loc_0xc0444c24;
        break;
}

// ----- END sitronix_remove_st_dev -----

// ----- BEGIN sitronix_copy_to_user (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_copy_to_user (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS: CALL 0xc0444d0c  CALL 0xc0444d44  CALL 0xc0444d7c
        // XREFS: CALL 0xc0444db4  CALL 0xc0444dec  CALL 0xc0444e24
        // XREFS: CALL 0xc0444e5c
        push (r0, r1, r2, r4, r5, lr)
        r5 = r2       // arg3
        r4 = [0xc0444c64] // [0xc0444ce0:4]=0xc0a5d4c8
        r2 = 0
        r3 = [r4]
        [r3] = r2
        r3 = r0       // arg1
        [sp] = r1     // arg2
        r1 = 0x1008
        r0 = [r4]
        r2 = [0xc0444c84] // [0xc0444ce4:4]=0xc0802c7b "%s = %d." // "%s = %d\n"
        sym.snprintf () // int snprintf(0, -1, "%s = %d\n", 0, -1)
        r1 = [r4]
        r4 = r0 - 0
        (>=) goto 0xc0444cd0 // likely
        goto loc_0xc0444c90;
    loc_0xc0444cd0:
        r2 = r4
        r0 = r5
        sym._copy_to_user_45 () // sym._copy_to_user_45(0x0, 0x0)
        goto 0xc0444cbc
        
    loc_0xc0444cbc:
        // CODE XREF from sym.sitronix_copy_to_user @ 0xc0444cdc(x)
        (a, b) = compare (r0, 0)
        movlt r4, 0
        r0 = r4
        sp += 0xc
        pop (r4, r5, pc)
        goto loc_0xc0444ca0;
        return r0;
    loc_0xc0444ca0:
        r1 = 1
        r0 = [0xc0444cac] // [0xc0444cec:4]=0xc07ccde8 "./include/linux/thread_info.h" // "./include/linux/thread_info.h"
        [r2] = (byte) r1
        r2 = 9
        r1 = 0x96
        sym.warn_slowpath_fmt () // sym.warn_slowpath_fmt(0xc07ccde8, 0x96, 0x9, 0x0, 0x0, 0x0)
        
    loc_0xc0444cb8:
        r0 = r4
        return r0;
}

// ----- END sitronix_copy_to_user -----

// ----- BEGIN sitronix_proc_swu_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_swu_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444d00] // [0xc0444d20:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444d08] // [0xc0444d24:4]=0xc0802c84 "ST_MODE_SWU" // "ST_MODE_SWU"
        r3 = [r3]
        r1 = (byte) [r3 + 0x193]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802c84, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_swu_read -----

// ----- BEGIN sitronix_proc_glove_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_glove_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444d38] // [0xc0444d58:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444d40] // [0xc0444d5c:4]=0xc0802c90 "ST_MODE_GLOVE" // "ST_MODE_GLOVE"
        r3 = [r3]
        r1 = (byte) [r3 + 0x194]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802c90, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_glove_read -----

// ----- BEGIN sitronix_proc_charge_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_charge_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444d70] // [0xc0444d90:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444d78] // [0xc0444d94:4]=0xc0802c9e "ST_MODE_CHARGE" // "ST_MODE_CHARGE"
        r3 = [r3]
        r1 = (byte) [r3 + 0x195]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802c9e, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_charge_read -----

// ----- BEGIN sitronix_proc_jittersuppress_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_jittersuppress_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444da8] // [0xc0444dc8:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444db0] // [0xc0444dcc:4]=0xc0802cad "ST_MODE_JITTERSUPPRESS" // "ST_MODE_JITTERSUPPRESS"
        r3 = [r3]
        r1 = (byte) [r3 + 0x196]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802cad, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_jittersuppress_read -----

// ----- BEGIN sitronix_proc_palm_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_palm_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444de0] // [0xc0444e00:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444de8] // [0xc0444e04:4]=0xc0802cc4 "ST_MODE_PALM" // "ST_MODE_PALM"
        r3 = [r3]
        r1 = (byte) [r3 + 0x197]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802cc4, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_palm_read -----

// ----- BEGIN sitronix_proc_headphone_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_headphone_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444e18] // [0xc0444e38:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444e20] // [0xc0444e3c:4]=0xc0802cd1 "ST_MODE_HEADPHONE" // "ST_MODE_HEADPHONE"
        r3 = [r3]
        r1 = (byte) [r3 + 0x198]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802cd1, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_headphone_read -----

// ----- BEGIN sitronix_proc_grip_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_proc_grip_read (int32_t arg1, int32_t arg2) {
        push (r4, lr)
        r4 = r3       // arg4
        r3 = [0xc0444e50] // [0xc0444e70:4]=0xc0a5d4d0
        r2 = r1       // arg2
        r0 = [0xc0444e58] // [0xc0444e74:4]=0xc0802ce3 "ST_MODE_GRIP" // "ST_MODE_GRIP"
        r3 = [r3]
        r1 = (byte) [r3 + 0x199]
        sym.sitronix_copy_to_user () // sym.sitronix_copy_to_user(0xc0802ce3, 0xff, 0x0)
        r2 = 0
        stm r4, (r0, r2)
        r0 = r2
        pop (r4, pc)  // r13
}

// ----- END sitronix_proc_grip_read -----

// ----- BEGIN sitronix_ts_addrmode_write (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_addrmode_write_2 (int32_t arg1, int32_t arg2, int32_t arg3) {
        // XREFS: CALL 0xc0445334  CALL 0xc044604c  CALL 0xc0446080
        // XREFS: CALL 0xc044618c  CALL 0xc04461c0  CALL 0xc04461ec
        // XREFS: CALL 0xc044621c  CALL 0xc0446254  CALL 0xc0446288
        // XREFS: CALL 0xc04462b4  CALL 0xc04462e0  CALL 0xc0446414
        // XREFS: CALL 0xc044654c  CALL 0xc044657c  CALL 0xc04465b0
        // XREFS: CALL 0xc04465d8  CALL 0xc0446600  CALL 0xc044662c
        [sp - 4]! = lr
        ip = r1       // arg2
        r3 = [r0 + 0x10] // arg1
        r1 = r2       // arg3
        r0 = ip
        lr = [r3 + 0x2c]
        r2 = [r3 + 0x14]
        r3 = lr
        pop (lr)      // r13
        bx r3
}

// ----- END sitronix_ts_addrmode_write -----

// ----- BEGIN sitronix_do_upgrade_flash_icp_all (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_do_upgrade_flash_icp_all (int32_t arg_ah, int32_t arg_ah_2, int32_t arg_ah_3) {
        // CALL XREF from sym.sitronix_do_upgrade @ 0xc04466d0(x)
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x2c
        r8 = [0xc0445c04] // [0xc0445ea4:4]=0xc0a04e08
        r2 = 0
        r5 = [0xc0445c0c] // [0xc0445ea8:4]=0xc0a5d4d0
        r1 = 1
        [var_ch] = r2
        r3 = [r8]
        [var_10h] = r2
        [var_14h] = r2
        [var_24h] = r3
        r3 = var_28h
        [var_18h] = r2
        [r3 - 8]! = r2
        [var_1ch] = r2
        r7 = [0xc0445c38] // [0xc0445eac:4]=0xc0a7d668
        r2 = [r5]
        r0 = r7
        [r2 + 0x91] = (byte) r1
        r2 = var_14h
        r1 = var_ch
        [var_4h] = r2
        r2 = var_10h
        [sp] = r2
        r2 = var_18h
        sym.st_check_fw () // sym.st_check_fw(0xc0a7d668, 0x177fc4, 0x177fd0, 0x177fd8, 0x0, 0x0)
        (a, b) = compare (r0, 0)
        (>=) goto 0xc0445cc0 // unlikely
        goto loc_0xc0445c64;
    while (/* 0xc0445cc0 */) {
        r4 = ~4
        r2 = [var_24h_2]
        r0 = r4
        r3 = [r8]
        (a, b) = compare (r2, r3)
        je 0xc0445e9c // unlikely
        sym.__stack_chk_fail () // void __stack_chk_fail(void)
        r3 = [var_1ch_2]
        (a, b) = compare (r3, 0)
        bne 0xc0445ca0 // likely
        sym.sitronix_ts_get_device_info () // sym.sitronix_ts_get_device_info(0x0)
        r4 = 1
        r3 = [var_18h_2]
        (a, b) = compare (r3, 0)
        je 0xc0445ca8 // likely
        // CODE XREFS from sym.sitronix_do_upgrade_flash_icp_all @ 0xc0445d20(x), 0xc0445df0(x)
        r0 = [r5]
        sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(-1)
        sym.st_irq_on ()
        r0 = [r5]
        r3 = 0
        (a, b) = compare (r4, r3)
        [r0 + 0x91] = (byte) r3
        blt 0xc0445ca8 // unlikely
    }
    while (/* 0xc0445ccc */) {
    }
    loc_0xc0445ce0:
        sym.st_irq_off ()
        r0 = [r5]
        r6 = r7
        r2 = (byte) [r0 + 0x2de]
        (a, b) = compare (r2, 0)
        bne 0xc0445d44 // likely
        goto loc_0xc0445cf8;
    while (/* 0xc0445d44 */) {
        r4 = ~0
        goto 0xc0445c68
        r3 = (byte) [r7 + r3]
        r1 = (byte) [r0 + 0x15]
        (a, b) = compare (r3, r1)
        [var_28h] = r3
        strle r2, [sp, 0x1c]
        strle r2, [sp, 0x18]
        movle r4, r2
        ble 0xc0445c68 // likely
    }
    while (/* 0xc0445d54 */) {
    }
    while (/* 0xc0445d6c */) {
    }
    while (/* 0xc0445dc0 */) {
    }
    loc_0xc0445dd0:
        r3 = [var_1ch]
        (a, b) = compare (r3, 0)
        bne 0xc0445df4 // unlikely
        goto loc_0xc0445ddc;
    loc_0xc0445df4:
        sb = [0xc0445dfc] // [0xc0445eb0:4]=0xc0a5d668
        r7 = 4
        
    while (/* 0xc0445dfc */) {
        // CODE XREF from sym.sitronix_do_upgrade_flash_icp_all @ 0xc0445e44(x)
        r3 = [var_18h]
        (a, b) = compare (r3, 0)
        bne 0xc0445e48 // unlikely
        // CODE XREF from sym.sitronix_do_upgrade_flash_icp_all @ 0xc0445e98(x)
        r0 = 1
        sym.st_icp_flash_lock () // sym.st_icp_flash_lock(0x1, 0x0)
        goto 0xc0445c68
    }
    while (/* 0xc0445e3c */) {
    }
    loc_0xc0445e44:
        goto 0xc0445ddc
        goto loc_0xc0445dfc;
    loc_0xc0445cf8:
        r3 = [var_24h]
        ip = r7 + r3
        lr = (byte) [ip + 0xe]
        r1 = (byte) [ip + 0xf]
        add r1, r1, lr, lsl 8
        [var_28h] = r1
        r3 += r1
        (a, b) = compare (r3, 0x13000)
        bls 0xc0445d24 // likely
        goto loc_0xc0445d1c;
        return r0;
    loc_0xc0445e48: // orphan
         sb = [0xc0445e50]        // [0xc0445eb0:4]=0xc0a5d668
         r7 = 4

         goto loc_0xc0445de8;
    loc_0xc0445e90: // orphan
         r7 -= 1
         bne 0xc0445e50           // likely

    loc_0xc0445e50: // orphan
         r1 = [var_ch]
         r3 = (word) [arg_ah_3]
         r2 = [var_18h]
         r0 = r6 + r1
         sym.st_icp_flash_write () // sym.st_icp_flash_write(0x0, 0x0, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0)
         r1 = 0
         r0 = sb
         r2 = [var_18h]
         sym.st_icp_flash_read () // sym.st_icp_flash_read(0x0, 0x0, 0x0)
         r0 = sb
         r1 = [var_ch]
         r2 = [var_18h]
         r1 = r6 + r1
         sym.st_compare_array ()  // sym.st_compare_array(0x0, 0x0, 0x0)
         (a, b) = compare (r0, 0)
         je 0xc0445de8            // likely

         goto loc_0xc0445e98;
    loc_0xc0445e98: // orphan
         
         goto loc_0xc0445e3c;
}

// ----- END sitronix_do_upgrade_flash_icp_all -----

// ----- BEGIN sitronix_spi_pram_rw (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_spi_pram_rw (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg_38h) {
        // XREFS(26)
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x14
        r4 = [0xc0445ec4] // [0xc0446090:4]=0xc0a5d4cc
        fp = r2       // arg3
        r5 = [arg_38h]
        sb = r3       // arg4
        r7 = [0xc0445ed4] // [0xc0446094:4]=0xc0a5d4d0
        r6 = 0
        r8 = [0xc0445edc] // [0xc0446098:4]=0xc0a5d4c8
        [var_8h] = r0 // arg1
        [var_ch] = r1 // arg2
        
    loc_0xc0445ee0:
        // CODE XREF from sym.sitronix_spi_pram_rw @ 0xc0445fa0(x)
        (a, b) = compare (r5, 0)
        ble 0xc0446020 // likely
        goto loc_0xc0445ee8;
        return r0;
    loc_0xc0445ee8:
        r3 = [var_ch]
        (a, b) = compare (r5, 0x100)
        r2 = [r4]
        r3 = r6 + r3
        r1 = r3 >> 0x10
        [r2 + 1] = (byte) r1
        r2 = [r4]
        r1 = r3 >> 8
        [r2 + 2] = (byte) r1
        r2 = [r4]
        [r2 + 3] = (byte) r3
        r3 = [var_8h]
        ble 0xc0445fa4 // likely
        goto loc_0xc0445f1c;
    loc_0xc0445fa4:
        (a, b) = compare (r3, 0)
        je 0xc044605c // likely
        goto loc_0xc0445fac;
    while (/* 0xc044605c */) {
        r0 = 0
        // CODE XREFS from sym.sitronix_spi_pram_rw @ 0xc0446058(x), 0xc044608c(x)
        sp += 0x14
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        sl = [r4]
        r2 = 0x100
        r1 = fp + r6  // r13
        r0 = sl + 4
        sym.memcpy () // void *memcpy(-1, 0x00000000, -1)
        r2 = 0x103
        r1 = sl
        r0 = [r7]
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, -1, 0x103)
        (a, b) = compare (r0, 0)
        (>=) goto 0xc0445f98 // unlikely
        goto 0xc0446024
    }
    loc_0xc044608c:
        goto 0xc0446024
        
        goto loc_0xc0446008;
        goto loc_0xc0445f24;
        return r0;
    loc_0xc0445f24:
        r2 = [r4]
        r1 = 0
        r3 = (byte) [r2 + 1]
        r3 = ~r3
        r3 = ~r3
        [r2 + 1] = (byte) r3
        sl = [r4]
        r2 = 0x101
        r0 = sl + 4
        sym.memset () // void *memset(-1, 0, -1)
        r3 = [r7]
        r1 = 3
        r0 = sl
        r3 = [r3 + 0x10]
        r2 = [r3 + 0x14]
        [sp] = r2
        r3 = [r3 + 0x28]
        r2 = [r8]
        ip = r3
        r3 = 0x101
        ip ()         // 0xffffffff(-1, 0x3, -1, 0x101)
        (a, b) = compare (r0, 0)
        blt 0xc0446024 // likely
        goto loc_0xc0445f80;
    loc_0xc0445f80:
        r1 = [r8]
        r0 += 1
        r2 = 0x100
        r1 += r0
        r0 = sb + r6
        sym.memcpy () // void *memcpy(0, 0, -1)
        
    loc_0xc0445f98:
        r6 += 0x100
        r5 -= 0x100
        goto 0xc0445ee0
    loc_0xc0446008: // orphan
         r1 = [r8]
         r0 += 1
         r2 = r5
         r1 += r0
         r0 = sb + r6
         sym.memcpy () // void *memcpy(0, 0, 0)

         goto loc_0xc0445f1c;
    loc_0xc0445f1c: // orphan
         (a, b) = compare (r3, 0)
         je 0xc044602c            // likely

}

// ----- END sitronix_spi_pram_rw -----

// ----- BEGIN sitronix_spi_hdl_fw (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_spi_hdl_fw (int32_t arg1, int32_t arg_2ah, int32_t arg_2ah_2, int32_t arg_2ah_3, int32_t arg_2eh) {
        // CALL XREF from sym.sitronix_do_upgrade_hostdownload @ 0xc04464cc(x)
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x3c
        r4 = [0xc04460ac] // [0xc0446488:4]=0xc0a04e08
        r2 = 0
        r1 = var_10h
        [var_10h] = r2
        [var_14h] = r2
        r6 = r0       // arg1
        r3 = [r4]
        [var_18h] = r2
        [var_1ch] = r2
        [var_34h] = r3
        r3 = var_38h
        [var_20h] = r2
        [r3 - 0x14]! = r2
        r2 = var_18h
        [var_4h] = r2
        r2 = var_14h
        [sp] = r2
        r2 = var_1ch
        sym.st_check_fw () // sym.st_check_fw(0x0, 0x177fb0, 0x177fbc, 0x177fc4, 0x0, 0x0)
        (a, b) = compare (r0, 0)
        [var_1ch] = r4
        (>=) goto 0xc044611c // likely
        goto loc_0xc04460fc;
    loc_0xc044611c:
        r0 = [var_14h_2]
        r1 = var_20h_2
        r0 = r6 + r0
        sym.st_check_cfg () // sym.st_check_cfg(0xffff, 0x178020)
        (a, b) = compare (r0, 0)
        blt 0xc044643c // unlikely
        goto loc_0xc0446134;
    loc_0xc044643c:
        r3 = [0xc0446444] // [0xc044648c:4]=0xc0a5d4d0
        r2 = 0x64     // 'd'
        r1 = [0xc044644c] // [0xc044649c:4]=0xc0802dda "st_check_cfg fail" // "st_check_cfg fail"
        r0 = [r3]
        goto 0xc044610c
        
    loc_0xc044610c:
        // CODE XREF from sym.sitronix_spi_hdl_fw @ 0xc044644c(x)
        r0 += 0x98
        sym.strlcpy () // char *strlcpy("", 0, 0)
        return r0;
    loc_0xc0446480: // orphan
         sp += 0x3c
         pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)

    loc_0xc0446438: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0446134: // orphan
         r4 = [0xc044613c]        // [0xc044648c:4]=0xc0a5d4d0
         r3 = 4
         [var_18h] = r3

         goto loc_0xc0446114;
    loc_0xc0446114: // orphan
         r0 = ~0
         
         goto loc_0xc0446150;
    loc_0xc0446150: // orphan
         r0 = [r4]
         sb = 0x53                // 'S'
         sym.sitronix_ts_reset_device () // sym.sitronix_ts_reset_device(-1)
         r2 = 5
         r0 = [r4]
         r3 = 0x3c                // '<'
         r8 = 0x71                // 'q'
         r7 = 0x23                // '#'
         fp = ~0x5a
         r1 = var_2eh
         [var_2eh] = (byte) sb
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) r7
         [var_32h] = (byte) fp
         [var_32h] = (byte) r3
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x5)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // likely

    loc_0xc0446140: // orphan
         // CODE XREF from sym.sitronix_spi_hdl_fw @ 0xc044647c(x)
         r3 = [var_18h]
         r3 -= 1
         [var_18h] = r3
         je 0xc0446114            // unlikely

         goto loc_0xc0446198;
    loc_0xc0446198: // orphan
         r5 = 5
         r1 = var_2eh
         r2 = r5
         r0 = [r4]
         [var_2eh] = (byte) sb
         sl = 0x55                // 'U'
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) r7
         [var_32h] = (byte) r5
         [var_32h] = (byte) sl
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x5)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // likely

         goto loc_0xc04461cc;
    loc_0xc04461cc: // orphan
         r2 = r5
         r1 = var_2eh
         r0 = [r4]
         [var_2eh] = (byte) sb
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) r7
         [var_32h] = (byte) sl
         [var_32h] = (byte) sl
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // likely

         goto loc_0xc04461f8;
    loc_0xc04461f8: // orphan
         r2 = 0x14
         r1 = var_2eh
         [var_32h] = (byte) r2
         r2 = r5
         r0 = [r4]
         [var_2eh] = (byte) sb
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) r7
         [var_32h] = (byte) sl
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // likely

         goto loc_0xc0446228;
    loc_0xc0446228: // orphan
         r2 = r5
         r1 = var_2eh
         r0 = [r4]
         r7 = 0
         r3 = 0x5a                // 'Z'
         [var_2eh] = (byte) r7
         r8 = ~0xc
         [var_2eh] = (byte) r7
         [var_2eh] = (byte) r8
         [var_32h] = (byte) r3
         [var_32h] = (byte) fp
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, r7)
         blt 0xc0446140           // likely

         goto loc_0xc0446260;
    loc_0xc0446260: // orphan
         r2 = r5
         r1 = var_2eh
         r0 = [r4]
         fp = 2
         [var_2eh] = (byte) r7
         sb = 1
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) fp
         [var_32h] = (byte) r7
         [var_32h] = (byte) sb
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, r7)
         blt 0xc0446140           // likely

         goto loc_0xc0446294;
    loc_0xc0446294: // orphan
         r2 = r5
         r1 = var_2eh
         r0 = [r4]
         [var_2eh] = (byte) r7
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) fp
         [var_32h] = (byte) r7
         [var_32h] = (byte) r7
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, r7)
         blt 0xc0446140           // likely

         goto loc_0xc04462c0;
    loc_0xc04462c0: // orphan
         r2 = r5
         r1 = var_2eh
         r0 = [r4]
         [var_2eh] = (byte) r7
         [var_2eh] = (byte) r8
         [var_2eh] = (byte) fp
         [var_32h] = (byte) r7
         [var_32h] = (byte) sb
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x0)
         (a, b) = compare (r0, r7)
         blt 0xc0446140           // likely

         goto loc_0xc04462ec;
    loc_0xc04462ec: // orphan
         r3 = 0x10000
         r2 = r6
         [sp] = r3
         r1 = 0x7f0000
         r3 = r7
         r0 = r7
         sym.sitronix_spi_pram_rw () // sym.sitronix_spi_pram_rw(0x0, 0x7f0000, 0x0, 0x0, 0x0)
         (a, b) = compare (r0, r7)
         blt 0xc0446140           // unlikely

         goto loc_0xc0446310;
    loc_0xc0446310: // orphan
         r3 = [r4]
         r2 = (byte) [r3 + 0x14]
         (a, b) = compare (r2, 0x83)
         bne 0xc0446450           // likely

    loc_0xc0446450: // orphan
         r3 = (byte) [r6 + 0x84]
         (a, b) = compare (r3, 0)
         bne 0xc044632c           // likely

    loc_0xc044632c: // orphan
         r5 = [0xc0446334]        // [0xc0446494:4]=0x7f0ffc
         r7 = 4

         goto loc_0xc0446368;
    loc_0xc0446368: // orphan
         r3 = [0xc0446370]        // [0xc0446498:4]=0x7ffffc
         r5 += 0x1000
         (a, b) = compare (r5, r3)
         bne 0xc0446334           // likely

    loc_0xc0446334: // orphan
         r3 = arg_2ah
         r2 = 0
         r1 = r5
         [sp] = r7
         r0 = 1
         sym.sitronix_spi_pram_rw () // sym.sitronix_spi_pram_rw(0x1, 0x0, 0x0, 0x17802a, 0x0)
         r0 = r5 - 0x7f0000
         r2 = 4
         r0 = r6 + r0
         r1 = arg_2ah_2
         sym.st_compare_array ()  // sym.st_compare_array(0xff810000, 0x17802a, 0x4)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // likely

         goto loc_0xc0446378;
    loc_0xc0446378: // orphan
         r3 = [var_20h]
         r2 = [var_14h]
         r1 = [var_18h]
         [sp] = r3
         r3 = 0
         r2 = r6 + r2
         r0 = r3
         sym.sitronix_spi_pram_rw () // sym.sitronix_spi_pram_rw(0x0, 0x0, 0xffff, 0x0, 0x0)
         r2 = 0
         r0 = 1
         r3 = [var_20h]
         r1 = [var_18h]
         [sp] = r7
         r1 += r3
         r3 = arg_2ah_2
         r1 -= 4
         sym.sitronix_spi_pram_rw () // sym.sitronix_spi_pram_rw(0x1, -1, 0x0, 0x17802a, 0x0)
         r2 = 4
         r3 = [var_20h]
         r1 = arg_2ah_3
         r0 = [var_14h]
         r0 += r3
         r0 -= 4
         r0 = r6 + r0
         sym.st_compare_array ()  // sym.st_compare_array(0xfffe, 0x17802a, 0x4)
         (a, b) = compare (r0, 0)
         blt 0xc0446140           // unlikely

         goto loc_0xc04463e4;
    loc_0xc04463e4: // orphan
         r2 = 5
         r1 = arg_2eh
         r0 = [r4]
         r5 = 0
         r3 = ~0xc
         [arg_2eh] = (byte) r5
         [arg_2eh] = (byte) r3
         r3 = 2
         [var_20h_2] = (byte) r5
         [arg_2eh] = (byte) r3
         r3 = 3
         [var_20h_2] = (byte) r3
         sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x17802e, 0x5)
         (a, b) = compare (r0, r5)
         blt 0xc0446140           // likely

         goto loc_0xc0446420;
    loc_0xc0446420: // orphan
         r0 = r5

         goto loc_0xc044645c;
    loc_0xc044645c: // orphan
         r2 = 0x2000
         r1 = 0x400000
         [sp] = r2
         r0 = r3
         r2 = r6 + 0x10000
         sym.sitronix_spi_pram_rw () // sym.sitronix_spi_pram_rw(0x0, 0x400000, 0x10000, 0x0, 0x0)
         (a, b) = compare (r0, 0)
         (>=) 
         goto loc_0xc044647c;
    loc_0xc044647c: // orphan
         
         goto loc_0xc0446320;
    loc_0xc0446320: // orphan
         r3 = (byte) [r3 + 0x29]
         (a, b) = compare (r3, 0x46) // 'F'
         bhi 0xc0446450           // likely

         goto loc_0xc04460fc;
    loc_0xc04460fc: // orphan
         r3 = [0xc0446104]        // [0xc044648c:4]=0xc0a5d4d0
         r2 = 0x64                // 'd'
         r1 = [0xc044610c]        // [0xc0446490:4]=0xc0802dc9 "st_check_fw fail" // "st_check_fw fail"
         r0 = [r3]

}

// ----- END sitronix_spi_hdl_fw -----

// ----- BEGIN sitronix_do_upgrade_hostdownload (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_do_upgrade_hostdownload (int32_t arg_ah) {
        // CALL XREF from sym.sitronix_do_upgrade @ 0xc044671c(x)
        push (r4, r5, r6, r7, r8, sb, lr)
        sp -= 0x14
        r8 = [0xc04464b0] // [0xc0446640:4]=0xc0a04e08
        r6 = 1
        r4 = [0xc04464b8] // [0xc0446644:4]=0xc0a5d4d0
        r3 = [r8]
        [var_ch] = r3
        r3 = [r4]
        [r3 + 0x91] = (byte) r6
        sym.st_irq_off ()
        r0 = [0xc04464d0] // [0xc0446648:4]=0xc0a7d668
        sym.sitronix_spi_hdl_fw () // sym.sitronix_spi_hdl_fw(0xc0a7d668, 0x0, 0x0, 0x0, 0x0)
        r5 = r0 - 0
        (>=) goto 0xc044651c // unlikely
        goto loc_0xc04464d8;
    loc_0xc044651c:
        r2 = 5
        r1 = var_6h
        r0 = [r4]
        r5 = 0
        r3 = ~0xc
        [var_6h] = (byte) r5
        [var_6h] = (byte) r3
        r7 = 0x53     // 'S'
        [var_6h] = (byte) r5
        sb = 0x4c     // 'L'
        [var_ah] = (byte) r5
        [var_ah] = (byte) r5
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r2 = 5
        r3 = ~0xf
        r0 = [r4]
        [var_6h] = (byte) r3
        r3 = 6
        r1 = sp + r3
        [var_6h] = (byte) r3
        [var_6h] = (byte) r5
        [var_ah] = (byte) r5
        r5 = 0x23     // '#'
        [var_ah] = (byte) r6
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r0 = 0x14
        r6 = 0x71     // 'q'
        sym.msleep () // sym.msleep(0x14, 0x178006)
        r2 = 5
        r0 = [r4]
        r3 = 0x50     // 'P'
        r1 = var_ah
        [var_ah] = (byte) r5
        [arg_ah] = (byte) r3
        [var_ah] = (byte) r7
        [var_ah] = (byte) r6
        [arg_ah] = (byte) sb
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x55     // 'U'
        r1 = var_ah
        [var_ah] = (byte) r5
        [arg_ah] = (byte) r3
        [var_ah] = (byte) r7
        [var_ah] = (byte) r6
        [arg_ah] = (byte) sb
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x41     // 'A'
        r1 = var_ah
        [var_ah] = (byte) r5
        [arg_ah] = (byte) r3
        [var_ah] = (byte) r7
        [var_ah] = (byte) r6
        [arg_ah] = (byte) sb
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r2 = 5
        r0 = [r4]
        r3 = 0x5a     // 'Z'
        r1 = var_ah
        [var_ah] = (byte) r5
        [arg_ah] = (byte) r3
        r3 = ~0x3c
        [var_ah] = (byte) r7
        [var_ah] = (byte) r6
        [arg_ah] = (byte) r3
        sym.sitronix_ts_addrmode_write_2 () // sym.sitronix_ts_addrmode_write_2(-1, 0x178006, 0x5)
        r5 = r0
        goto 0xc04464ec
        
    loc_0xc04464ec:
        // CODE XREF from sym.sitronix_do_upgrade_hostdownload @ 0xc0446634(x)
        r0 = 0x14
        sym.msleep () // sym.msleep(0x14, 0x0)
        sym.st_irq_on ()
        r3 = [r4]
        r2 = 0
        r0 = r5
        [r3 + 0x91] = (byte) r2
        r2 = [var_ch]
        r3 = [r8]
        (a, b) = compare (r2, r3)
        je 0xc0446638 // unlikely
        goto loc_0xc0446518;
        return r0;
    loc_0xc0446518: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc04464d8: // orphan
         r0 = [r4]
         r2 = 0x64                // 'd'
         r1 = [0xc04464e8]        // [0xc044664c:4]=0xc0802dec "sitronix_spi_hdl_fw fail" // "sitronix_spi_hdl_fw fail"
         r0 += 0x98
         sym.strlcpy () // char *strlcpy("", "sitronix_spi_hdl_fw fail", -1)

}

// ----- END sitronix_do_upgrade_hostdownload -----

// ----- BEGIN sitronix_do_upgrade (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_do_upgrade (void) {
        // CALL XREF from sym.sitronix_stupgrade_store @ 0xc0440e74(x)
        // CALL XREF from sym.st_proc_stupgrade_write @ 0xc04436cc(x)
        // CALL XREF from sym.st_dev_function @ 0xc044474c(x)
        push (r0, r1, r4, r5, r6, r7, r8, lr)
        r7 = [0xc044665c] // [0xc0446740:4]=0xc0a04e08
        r5 = [0xc0446660] // [0xc0446744:4]=0xc0a5d4d0
        r6 = [0xc0446664] // [0xc0446748:4]=0xc0a5d564
        r3 = [r7]
        [var_4h] = r3
        r3 = 0
        [sp] = r3
        r3 = [r5]
        r4 = (byte) [r3 + 0x2df]
        (a, b) = compare (r4, 0)
        bne 0xc0446708 // likely
        goto loc_0xc0446680;
    while (/* 0xc0446708 */) {
        sym.sitronix_do_upgrade_flash_icp_all () // sym.sitronix_do_upgrade_flash_icp_all(0x0, 0x0, 0x0)
        goto 0xc0446720
        r3 = [sp]
        r0 = [0xc04466e4] // [0xc044674c:4]=0xc0a7d668
        r2 = [r3]
        r1 = [r3 + 4]
        (a, b) = compare (r2, 0x13000)
        movhi r2, 0x13000
        [r6] = r2
        r2 = [r6]
        sym.memcpy () // void *memcpy(0x00000000, -1, -1)
        r3 = [r5]
        r2 = 1
        [r3 + 0x2df] = (byte) r2
    }
    loc_0xc044671c:
        sym.sitronix_do_upgrade_hostdownload () // sym.sitronix_do_upgrade_hostdownload(0x0)
        
    loc_0xc0446720:
        // CODE XREF from sym.sitronix_do_upgrade @ 0xc04466d4(x)
        r4 = r0
        r0 = [sp]
        sym.release_firmware () // sym.release_firmware(0x2000)
        r3 = 0
        [r6] = r3
        goto 0xc04466b8
        return r0;
    loc_0xc0446738: // orphan
         sp += 8
         pop (r4, r5, r6, r7, r8, pc)

    loc_0xc04466cc: // orphan
         sym.__stack_chk_fail () // void __stack_chk_fail(void)

        return r0;
    loc_0xc0446680: // orphan
         r8 = r6
         [r8] + 4 = r4

    loc_0xc04466a8: // orphan
         r4 += 1
         (a, b) = compare (r4, 3)
         bne 0xc0446688           // likely

    loc_0xc0446688: // orphan
         r3 = [r5]
         r1 = r8
         r0 = sp                  // r13
         r2 = [r3 + 4]
         r2 += 0x10
         sym.request_firmware ()  // sym.request_firmware(0x178000, 0x0, 0xf)
         (a, b) = compare (r0, 0)
         je 0xc04466d8            // unlikely

         goto loc_0xc04466b4;
    loc_0xc04466b4: // orphan
         r4 = ~1

}

// ----- END sitronix_do_upgrade -----

// ----- BEGIN sitronix_replace_dump_buf (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_replace_dump_buf (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cab8(x)
        push (r4, lr)
        r1 = 0
        r4 = [0xc0446760] // [0xc0446778:4]=0xc0a5d568
        r2 = 0x100
        r0 = r4
        sym.memset () // void *memset(0x00000000, 0, -1)
        r0 = r4
        r1 = [0xc0446774] // [0xc044677c:4]=0xc0802e05 "st7123.dump" // "st7123.dump"
        pop (r4, lr)
        goto sym.strcpy // char *strcpy("", "st7123.dump")
}

// ----- END sitronix_replace_dump_buf -----

// ----- BEGIN sitronix_ts_reg_read (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_reg_read_2 (int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) {
        // CALL XREFS from sym.st_test_fw @ 0xc0448ab0(x), 0xc0448b1c(x), 0xc0448c10(x), 0xc0448d54(x), 0xc0448e58(x)
        [sp - 4]! = lr
        ip = r1       // arg2
        r1 = r2       // arg3
        r2 = r3       // arg4
        r3 = [r0 + 0x10] // arg1
        r0 = ip
        lr = [r3 + 0x18]
        r3 = [r3 + 0x14]
        ip = lr
        pop (lr)      // r13
        bx ip
}

// ----- END sitronix_ts_reg_read -----

// ----- BEGIN sitronix_vfswrite (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_vfswrite (void) {
        // XREFS(56)
        ip = [0xc0446910] // [0xc044691c:4]=0xc0a2ec18
        ip = (byte) [ip + 0x48]
        (a, b) = compare (ip, 0)
        je lr
        goto sym.kernel_write // sym.kernel_write(0x0, 0x0)
}

// ----- END sitronix_vfswrite -----

// ----- BEGIN sitronix_set_default_test_criteria (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_set_default_test_criteria (void) {
        // CALL XREF from sym.sitronix_ts_probe @ 0xc043cab0(x)
        r3 = [0xc04495c0] // [0xc044961c:4]=0xc0a5d4d0
        r2 = [0xc04495c4] // [0xc0449620:4]=0xfffffed4
        r3 = [r3]
        [r3 + 0x2d4] = r2
        r2 = 0xbb8
        [r3 + 0x2d8] = r2
        r2 = 0x1c2
        [r3 + 0x2b0] = r2
        r2 = 0x64     // 'd'
        [r3 + 0x2b4] = r2
        r2 = 0x4b0
        [r3 + 0x2b8] = r2
        r2 = 0x1f4
        [r3 + 0x2bc] = r2
        r2 = 0
        [r3 + 0x2c0] = r2
        r2 = 0x50     // 'P'
        [r3 + 0x2c4] = r2
        r2 = 0x7d     // '}'
        [r3 + 0x2c8] = r2
        r2 = 0x1e
        [r3 + 0x2cc] = r2
        r2 = 0x384
        [r3 + 0x2d0] = r2
        bx lr
}

// ----- END sitronix_set_default_test_criteria -----

// ----- BEGIN sitronix_replace_test_cmd (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_replace_test_cmd (void) {
        bx lr
}

// ----- END sitronix_replace_test_cmd -----

// ----- BEGIN sitronix_request_test_criteria (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_request_test_criteria (void) {
        r0 = 0
        bx lr
}

// ----- END sitronix_request_test_criteria -----

// ----- BEGIN sitronix_touch_selftest (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_touch_selftest (int32_t arg_1ah, int32_t arg_1ah_2, int32_t arg_1ah_3, int32_t arg_8h, int32_t arg_1ah_4, int32_t arg_1ah_5, int32_t arg_ch) {
        push (r4, r5, r6, r7, r8, sb, sl, fp, lr)
        sp -= 0x54
        r5 = [0xc0449640] // [0xc04498e4:4]=0xc0a04e08
        r2 = 0x1a4
        r8 = [0xc0449648] // [0xc04498e8:4]=0xc0a2ec18
        r1 = 0x241
        r0 = [0xc0449650] // [0xc04498ec:4]=0xc08034ae "/sdcard/ST_SELFTEST_LOG.txt" // "/sdcard/ST_SELFTEST_LOG.txt"
        r3 = [r5]
        r7 = [0xc0449658] // [0xc04498f0:4]=0xc0a5d4d0
        [var_4ch] = r3
        r3 = 1
        [r8 + 0x48] = (byte) r3
        sym.filp_open () // sym.filp_open(0xc08034ae, 0x241, 0x1a4)
        r3 = sp
        bic r3, r3, 0x1fc0
        bic r3, r3, 0x3f
        if (r0 != 0x1000)
        [var_ch] = r5
        r3 = [r3 + 8]
        movls r4, r0  // "/sdcard/ST_SELFTEST_LOG.txt"
        r0 = 0
        movhi r4, 0
        strbhi r4, [r8, 0x48]
        [var_8h] = r3
        sym.set_fs_8 () // sym.set_fs_8(0x0)
        r1 = 0
        r0 = [r7]
        r2 = 0
        r3 = 0
        r5 = var_50h
        strd r2, r3, [r5, -0x40]!
        sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(0x0, 0x0)
        r0 = [r7]
        r3 = 1
        r0 += 0x70
        [r0 + 0x21] = (byte) r3
        sym.mutex_lock () // sym.mutex_lock(0x70)
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_record_ic_info () // sym.st_record_ic_info(0xc08034ae, 0x177f98)
        r0 = var_18h
        sym.sitronix_get_ic_position () // sym.sitronix_get_ic_position(0x177fa0)
        r2 = (byte) [var_18h_2]
        r0 = var_1ah
        r1 = (byte) [var_18h_2]
        r3 = r2 << 4
        r2 = r2 >> 4
        r3 &= 0x10
        [sp] = r2
        r3 |= r1
        r2 = [0xc0449700] // [0xc04498f4:4]=0xc08034ca "IC position X,Y = (%03d,%03d)." // "IC position X,Y = (%03d,%03d)\n"
        r1 = 0x32     // '2'
        sym.snprintf () // int snprintf("\x17", -1, "IC position X,Y = (%03d,%03d)\n", 0x7f, -1)
        r0 = var_1ah
        sym.strlen () // size_t strlen("\x17")
        r3 = r5
        r2 = r0
        r1 = var_1ah
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_test_normal_rawdata () // sym.st_test_normal_rawdata(0xc08034ae, 0x177f98, 0x177fa6, 0x177f98, 0x0, 0x0, 0x0, 0x0)
        (a, b) = compare (r0, 0)
        r0 = arg_1ah
        ldreq r1, [pc, 0x1bc] // [0xc04498f8:4]=0xc08034e9 "Test normal rawdata successed!."
        ldrne r1, [pc, 0x1bc] // [0xc04498fc:4]=0xc0803509 "Test normal rawdata failed!." // "Test normal rawdata failed!\n"
        sym.strcpy () // char *strcpy("", "Test normal rawdata failed!\n")
        r0 = arg_1ah
        sym.strlen () // size_t strlen("\xa0\xc0")
        r3 = r5
        r2 = r0
        r1 = arg_1ah
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_test_open_mux_on_off () // sym.st_test_open_mux_on_off(0xc08034ae, 0x177f98, 0x177fae, 0x177f98, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)
        r6 = r0 - 0   // "/sdcard/ST_SELFTEST_LOG.txt"
        r0 = arg_1ah_2
        ldreq r1, [pc, 0x188] // [0xc0449900:4]=0xc0803526 "Test open successed!."
        ldrne r1, [pc, 0x188] // [0xc0449904:4]=0xc080353c "Test open failed!." // "Test open failed!\n"
        sym.strcpy () // char *strcpy("", "Test open failed!\n")
        r0 = arg_1ah_2
        sym.strlen () // size_t strlen("")
        r3 = r5
        r2 = r0
        r1 = arg_1ah_2
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_test_short_odd () // sym.st_test_short_odd(0xc08034ae, 0x177f98)
        fp = r0 - 0   // "/sdcard/ST_SELFTEST_LOG.txt"
        r0 = arg_1ah_3
        ldreq r1, [pc, 0x154] // [0xc0449908:4]=0xc0803584 "Test short_odd successed!."
        ldrne r1, [pc, 0x154] // [0xc044990c:4]=0xc080359f "Test short_odd failed!." // "Test short_odd failed!\n"
        sym.strcpy () // char *strcpy("", "Test short_odd failed!\n")
        r0 = arg_1ah_3
        sym.strlen () // size_t strlen("")
        r3 = r5
        r2 = r0
        r1 = arg_1ah_3
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_test_short_even () // sym.st_test_short_even(0xc08034ae, 0x177f98)
        sl = r0 - 0   // "/sdcard/ST_SELFTEST_LOG.txt"
        r0 = arg_1ah_4
        ldreq r1, [pc, 0x120] // [0xc0449910:4]=0xc080354f "Test short_even successed!."
        ldrne r1, [pc, 0x120] // [0xc0449914:4]=0xc080356b "Test short_even failed!." // "Test short_even failed!\n"
        sym.strcpy () // char *strcpy("", "Test short_even failed!\n")
        r0 = arg_1ah_4
        sym.strlen () // size_t strlen("")
        r3 = r5
        r2 = r0
        r1 = arg_1ah_4
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r1 = r5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.st_test_std () // sym.st_test_std(0xc08034ae, 0x177f98)
        sb = r0 - 0   // "/sdcard/ST_SELFTEST_LOG.txt"
        r0 = arg_1ah_5
        ldreq r1, [pc, 0xec] // [0xc0449918:4]=0xc08035b7 "Test STD successed!."
        ldrne r1, [pc, 0xec] // [0xc044991c:4]=0xc08035cc "Test STD failed!." // "Test STD failed!\n"
        sym.strcpy () // char *strcpy("", "Test STD failed!\n")
        r0 = arg_1ah_5
        sym.strlen () // size_t strlen("")
        r3 = r5
        r2 = r0
        r1 = arg_1ah_5
        r0 = r4       // "/sdcard/ST_SELFTEST_LOG.txt"
        sym.sitronix_vfswrite ()
        r3 = fp >> 0x1f
        r3 |= r6
        r3 |= sl
        orrs r3, r3, sb, lsr 31
        addeq r6, r6, fp
        addeq sl, r6, sl
        mvnne sb, 0
        addeq sb, sl, sb
        r0 = [arg_8h]
        sym.set_fs_8 () // sym.set_fs_8(0x0)
        r3 = (byte) [r8 + 0x48]
        (a, b) = compare (r3, 0)
        je 0xc044988c // unlikely
        goto loc_0xc0449880;
    loc_0xc044988c:
        r3 = [0xc0449894] // [0xc0449920:4]=0xc0a90668
        (a, b) = compare (sb, 0)
        r0 = [r7]
        moveq r2, 1
        movne r2, 0
        r0 += 0x70
        [r3 + 8] = (byte) r2
        sym.mutex_unlock () // sym.mutex_unlock(0x6f)
        sym.sitronix_ts_mt_reset_process ()
        r0 = [r7]
        r3 = 0
        r1 = 1
        [r0 + 0x91] = (byte) r3
        sym.sitronix_ts_irq_enable () // sym.sitronix_ts_irq_enable(-1, 0x1)
        r3 = [arg_ch]
        r2 = [var_4ch]
        r3 = [r3]
        (a, b) = compare (r2, r3)
        je 0xc04498dc // unlikely
        goto loc_0xc04498d8;
    loc_0xc04498dc:
        sp += 0x54
        pop (r4, r5, r6, r7, r8, sb, sl, fp, pc)
        return r0;
    loc_0xc0449880: // orphan
         r1 = 0
         r0 = r4
         sym.filp_close ()        // sym.filp_close(0x0, 0x0)

}

// ----- END sitronix_touch_selftest -----

// ----- BEGIN sitronix_selftest_result_read (T)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_selftest_result_read (void) {
        r3 = [0xc044992c] // [0xc0449934:4]=0xc0a90668
        r0 = (byte) [r3 + 8]
        r0 ^= 1
        bx lr
}

// ----- END sitronix_selftest_result_read -----

// ----- BEGIN sitronix_ts_init (t)
// callconv: r0 arm32 (r0, r1, r2, r3, stack);
void sym.sitronix_ts_init (void) {
        push (r4, lr)
        sym.sitronix_ts_i2c_init ()
        r4 = r0 - 0
        bne 0xc091a3c4 // unlikely
        goto loc_0xc091a3b8;
    loc_0xc091a3c4:
        r0 = r4
        pop (r4, pc)
        return r0;
}

// ----- END sitronix_ts_init -----
