<?php
/* 
Copyright 2008 Daniel Lombraña González, David Anderson, Franisco Fernández de Vega

This file is part of OGM.

OGM is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OGM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with OGM.  If not, see <http://www.gnu.org/licenses/>.
*/

session_start();
session_unset();
session_destroy();
header("Location: index.php");
?>
