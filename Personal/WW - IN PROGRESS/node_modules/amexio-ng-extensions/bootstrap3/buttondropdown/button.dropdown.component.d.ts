import { AfterContentInit, OnInit, QueryList } from '@angular/core';
import { ItemComponent } from "./dropdown.item.component";
export declare class ButtonDropdownComponent implements OnInit, AfterContentInit {
    label: string;
    type: string;
    size: string;
    dropdownItemData: any[];
    elementId: any;
    btnStyleClass: string;
    btnDropdownStyle: string;
    btnGroupStyleClass: string;
    dropdownItemRef: QueryList<ItemComponent>;
    constructor();
    ngOnInit(): void;
    ngAfterContentInit(): void;
    createConfig(): void;
    createDropdownItemConfig(): void;
    itemClick(event: any, itemData: any): void;
}
