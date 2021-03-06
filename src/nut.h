/*  =========================================================================
    nut - agent nut structure

    Copyright (C) 2014 - 2017 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef NUT_H_INCLUDED
#define NUT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _nut_t nut_t;

//  @interface
//  Create a new nut
FTY_NUT_EXPORT nut_t *
    nut_new (void);

//  Destroy the nut
FTY_NUT_EXPORT void
    nut_destroy (nut_t **self_p);

// are there changes to be saved?
FTY_NUT_EXPORT bool
    nut_changed(nut_t *self);

//  Store fty_proto_t message transfering ownership
FTY_NUT_EXPORT void
    nut_put (nut_t *self, fty_proto_t **message_p);

//  Get list of asset names
FTY_NUT_EXPORT zlistx_t *
    nut_get_assets (nut_t *self);

// Get list of names of all UPS and PDU
FTY_NUT_EXPORT zlist_t *
    nut_get_powerdevices (nut_t *self);

// Get list of sensors names
FTY_NUT_EXPORT zlist_t *
    nut_get_sensors (nut_t *self);

// Helper function for nut_asset_XXX
FTY_NUT_EXPORT const char *
    nut_asset_get_string (nut_t *self, const char *asset_name, const char *ext_key);

// Returns ip address (well-known extended attribute 'ip.1') of given asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have ip address specified
FTY_NUT_EXPORT const char *
    nut_asset_ip (nut_t *self, const char *asset_name);

// Returns daisychain number (well-known extended attribute '...') of give asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have daisychain number specified
FTY_NUT_EXPORT const char *
    nut_asset_daisychain (nut_t *self, const char *asset_name);

// return port string of given asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have port specified
FTY_NUT_EXPORT const char *
    nut_asset_port (nut_t *self, const char *asset_name);

// ---------------------------------------------------------------------------
// return asset subtype string of given asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have asset subtype specified
FTY_NUT_EXPORT const char *
    nut_asset_subtype (nut_t *self, const char *asset_name);

// ---------------------------------------------------------------------------
// return asset location (aka parent_name) string of given asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have parent_name.1 specified
FTY_NUT_EXPORT const char *
    nut_asset_location (nut_t *self, const char *asset_name);

// return asset max_current (defined by user) of given asset
// or NULL when asset_name does not exist
// or "" (empty string) when given asset does not have max_current specified
FTY_NUT_EXPORT const char *
    nut_asset_max_current (nut_t *self, const char *asset_name);

//  Save nut to disk
//  If 'fullpath' is NULL does nothing
//  0 - success, -1 - error
FTY_NUT_EXPORT int
    nut_save (nut_t *self, const char *fullpath);

//  Load nut from disk
//  If 'fullpath' is NULL does nothing
//  0 - success, -1 - error
FTY_NUT_EXPORT int
    nut_load (nut_t *self, const char *fullpath);

//  Print the nut
FTY_NUT_EXPORT void
    nut_print (nut_t *self);

//  Self test of this class
FTY_NUT_EXPORT void
    nut_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
