#pragma once

enum class Estado
{
	NINGUNO,
	DESHABILITADO,
	SELECCION,
};

enum class btnType
{
	BTN_DEFAULT,
	BTN_CHAMPS,
	BTN_ITEMS,
	BTN_CONJ,
	BTN_BACKUP,
	BTN_DEVMENU,
	BTN_SALIR,
	BTN_GUARDAR,
	BTN_ADD_CHAMP,
	BTN_MOD_CHAMP,
	BTN_DEL_CHAMP,
	BTN_LIST_CHAMP,
	BTN_ADD_ITEM,
	BTN_MOD_ITEM,
	BTN_DEL_ITEM,
	BTN_LIST_ITEM,
	BTN_ADD_CONJ,
	BTN_MOD_CONJ,
	BTN_DEL_CONJ,
	BTN_LIST_CONJ,
	BTN_DET_CONJ,
	BTN_CREATE_BKP,
	BTN_RESTORE_BKP,
	BTN_VOLVER,
};

enum class EstadoMenu
{
	MENUPRINCIPAL,
	MENUDEV,
	MENUCHAMP,
	MENUALTA_CHAMP,
	MENUBAJA_CHAMP,
	MENUMOSTRAR_CHAMP,
	MENUMOD_CHAMP,
	MENUITEM,
	MENUALTA_ITEM,
	MENUBAJA_ITEM,
	MENUMOD_ITEM,
	MENUMOSTRAR_ITEM,
	MENUMOSTRAR_CONJ,
	MENUMASOPCIONES_ITEM,
	MENUMASOPCIONES_CHAMP,
	MENUMASOPCIONES_CONJ,
	MENUCONJ,
	MENUDET_CONJ,
	MENUALTA_CONJ,
	MENUBAJA_CONJ,
	MENUMOD_CONJ,
	MENUBKP,
	MENUBKP_CREATE,
	MENUBKP_RESTORE,
};

