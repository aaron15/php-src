<?php

function _skip_lc_messages($lc_messages = 'C')
{
    if (!_set_lc_messages($lc_messages)) {
        die("skip Cannot set LC_MESSAGES to '{$lc_messages}'\n");
    }
}

function _set_lc_messages($lc_messages = 'C')
{
    if (pg_result(pg_query("SHOW LC_MESSAGES"), 0, 0) != $lc_messages) {
        if (!@pg_exec("SET LC_MESSAGES='{$lc_messages}'")) {
            return false;
        }
    }

    return true;
}

?>
