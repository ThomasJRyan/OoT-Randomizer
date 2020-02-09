#include "gfx.h"
#include "skulltula_hud.h"
#include "text.h"

uint16_t* skulltulas = (uint16_t*)0x8011A6A0;

void draw_skulltula_count() {
    z64_disp_buf_t *db = &(z64_ctxt.gfx->overlay);
    
    if (*skulltulas > 0){
        gSPDisplayList(db->p++, &setup_db);
        gDPPipeSync(db->p++);
        gDPSetCombineMode(db->p++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        uint16_t alpha = z64_game.hud_alpha_channels.minimap;
        if (alpha == 0xAA) alpha = 0xFF;

        gDPSetPrimColor(db->p++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);

        sprite_load(db, &quest_items_sprite, 11, 1);
        sprite_draw(db, &quest_items_sprite, 0, 67, 205, 16, 16);

        char test[3] = "00";
        test[0] += *skulltulas / 10;
        test[1] += *skulltulas % 10;

        gDPSetPrimColor(db->p++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
        if (*skulltulas % 10 == 0 && *skulltulas <= 50) gDPSetPrimColor(db->p++, 0, 0, 0x80, 0xFF, 0x00, alpha);
        text_print(test, 84, 206);
        text_flush(db);

        gDPPipeSync(db->p++);
    }
}