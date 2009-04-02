<?php 
/* 
Copyright 2008 Daniel Lombraña González, David P. Anderson, Francisco Fernández de Vega

This file is part of Jarifa.

Jarifa is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Jarifa is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with Jarifa.  If not, see <http://www.gnu.org/licenses/>.
*/

class map 
{
    public $key;
    public $users;

    function __construct($key=null)
    {
        $this->key=$key;
    }

    function initialize($LatLng,$zoom)
    {
        printf('
            function initialize() {
              if (GBrowserIsCompatible()) {
                    var map = new GMap2(document.getElementById("map_canvas"));
                        map.addControl(new GLargeMapControl());
                        map.setCenter(new GLatLng('.$LatLng[0].','.$LatLng[1].'), '.$zoom.');

var volunteer = new GIcon();
volunteer.image = "./img/volunteer.png"
volunteer.iconSize = new GSize(38, 38);
volunteer.iconAnchor = new GPoint(18, 33);
volunteer.infoWindowAnchor = new GPoint(18, 0);

var supplier = new GIcon();
supplier.image = "./img/supplier.png"
supplier.iconSize = new GSize(38, 38);
supplier.iconAnchor = new GPoint(18, 33);
supplier.infoWindowAnchor = new GPoint(18, 0);


                    ');
       $user_LatLng = $this->markers();
       foreach ($user_LatLng as $user => $coordinates)
       {
                //print($user_LatLng[$user][2]);
                printf('var point = new GLatLng('.$coordinates[0].','.$coordinates[1].');');
                // We check if the role is volunteer (green arrow) or supplier (purple arrow)
                if ($user_LatLng[$user][2]=="volunteer")
                    printf('map.addOverlay(new GMarker(point,volunteer));');
                else
                    printf('map.addOverlay(new GMarker(point,supplier));');
       }
       printf('             
                  }
                }
            ');
    }

      function coordinates($location)
      {
          // Web RPC to conver a location into longitude and latitude
          // Escape blanks with plus chars
          $location=str_replace(" ","+",$location);
          $request='q='.$location.'&output=csv&key='.$this->key;
          $LatLng = file_get_contents(trim('http://maps.google.com/maps/geo?').$request, false,$this->context);
          $LatLng = explode(",",$LatLng);
          // Latitude
          $aux[0] = $LatLng[2];
          // Longitude
          $aux[1] = $LatLng[3];
          return($aux);
      }


    function markers()
    {
        foreach($this->users as $user)
        {
            $user_LatLng[$user->name]=array($user->latitude,$user->longitude,$user->role);
        }
        return($user_LatLng);
    }

    function create($users,$country)
    {
        $this->users = $users;
        printf('<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;key='.$this->key.'"
                type="text/javascript"></script>
                <script type="text/javascript">
              ');
        $LatLng = $this->coordinates($country);
        $this->initialize($LatLng,1);
    }

}
?>